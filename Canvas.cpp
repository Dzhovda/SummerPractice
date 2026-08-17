#include "Canvas.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include <stack>

void drawPath(Graphics& g, Path& path, float opacity, bool fill, int thickness,
    int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4,
    bool triangle = false)
{
    if (triangle)
    {
        if (fill)
        {
            g.setOpacity(opacity);
            path.addTriangle(X1, Y1, X2, Y2, X3, Y3);
            g.fillPath(path);
        }
        else
        {
            g.setOpacity(opacity);
            path.addTriangle(X1, Y1, X2, Y2, X3, Y3);
            g.strokePath(path, PathStrokeType(thickness));
        }
    }
    else
    {
        if (fill)
        {
            g.setOpacity(opacity);
            path.addQuadrilateral(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
            g.fillPath(path);
        }
        else
        {
            g.setOpacity(opacity);
            path.addQuadrilateral(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
            g.strokePath(path, PathStrokeType(thickness));
        }
    }
}

void Canvas::DrawFigures(Canvas::Line& line, Graphics& g, Path& path, float opacity)
{
    if (line.figures == Canvas::Line::Figures::brush || line.figures == Line::Figures::eraser)
    {
        Colour drawColour = (line.figures == Canvas::Line::Figures::brush) ? line.colour : backgroundColor;
        g.setColour(drawColour);
        g.setOpacity(line.opacity);

        // Рисуем отрезки между соседними точками
        for (int i = 1; i < line.points.size(); ++i)
        {
            Point<int> p1 = line.points[i - 1];
            Point<int> p2 = line.points[i];
            g.drawLine(p1.x, p1.y, p2.x, p2.y, line.thickness);
        }
        return;
    }

    // Геометрические фигуры
    g.setColour(line.colour);
    g.setOpacity(line.opacity);

    if (line.figures == Canvas::Line::Figures::line)
    {
        g.drawLine(line.start.x, line.start.y, line.end.x, line.end.y, line.thickness);
    }
    else if (line.figures == Canvas::Line::Figures::rect)
    {
        int x1 = std::min(line.start.x, line.end.x), y1 = std::min(line.start.y, line.end.y);
        int x2 = std::max(line.start.x, line.end.x), y2 = std::min(line.start.y, line.end.y);
        int x3 = std::max(line.start.x, line.end.x), y3 = std::max(line.start.y, line.end.y);
        int x4 = std::min(line.start.x, line.end.x), y4 = std::max(line.start.y, line.end.y);
        drawPath(g, path, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
    }
    else if (line.figures == Canvas::Line::Figures::triangle)
    {
        int x1 = line.start.x, y1 = line.start.y;
        int x2 = line.end.x, y2 = line.end.y;
        int x3 = line.start.x - (line.end.x - line.start.x), y3 = line.end.y;
        drawPath(g, path, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, 0, 0, true);
    }
    else if (line.figures == Canvas::Line::Figures::romb)
    {
        int dx = abs(line.end.x - line.start.x);
        int dy = abs(line.start.y - line.end.y);
        int cx = line.start.x, cy = line.start.y;
        int x1 = cx + dx, y1 = cy;
        int x2 = cx, y2 = cy + dy;
        int x3 = cx - dx, y3 = cy;
        int x4 = cx, y4 = cy - dy;
        drawPath(g, path, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
    }
    else if (line.figures == Canvas::Line::Figures::trapezoid)
    {
        int shift = 0.2 * abs(line.start.x - line.end.x);
        int x1 = line.start.x, y1 = line.start.y;
        int x2 = line.end.x + shift, y2 = line.start.y;
        int x3 = line.end.x, y3 = line.end.y;
        int x4 = line.start.x + shift, y4 = line.end.y;
        drawPath(g, path, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
    }
    else if (line.figures == Canvas::Line::Figures::parallelogram)
    {
        int shift = 0.2 * abs(line.start.x - line.end.x);
        int x1 = line.start.x, y1 = line.start.y;
        int x2 = line.end.x - shift, y2 = line.start.y;
        int x3 = line.end.x, y3 = line.end.y;
        int x4 = line.start.x + shift, y4 = line.end.y;
        drawPath(g, path, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
    }
    else if (line.figures == Canvas::Line::Figures::ellipse)
    {
        g.drawEllipse(std::min(line.start.x, line.end.x), std::min(line.start.y, line.end.y),
            abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
    }
    // polygon – пока не реализован
}

void FillFigure(juce::Point<int> startPoint, Image& image, Colour newColour)
{
    if (startPoint.x < 0 || startPoint.x >= image.getWidth() ||
        startPoint.y < 0 || startPoint.y >= image.getHeight())
        return;

    Colour targetColour = image.getPixelAt(startPoint.x, startPoint.y);

    if (targetColour == newColour)
        return;

    juce::Image::BitmapData data(image,
        0, 0,
        image.getWidth(),
        image.getHeight(),
        juce::Image::BitmapData::readWrite);

    std::stack<juce::Point<int>> pixelStack;
    pixelStack.push(startPoint);

    while (!pixelStack.empty())
    {
        juce::Point<int> p = pixelStack.top();
        pixelStack.pop();

        int x = p.getX();
        int y = p.getY();

        if (x < 0 || x >= data.width || y < 0 || y >= data.height)
            continue;

        Colour currentColour = data.getPixelColour(x, y);

        if (currentColour != targetColour)
            continue;

        data.setPixelColour(x, y, newColour);

        pixelStack.push({ x + 1, y });
        pixelStack.push({ x - 1, y });
        pixelStack.push({ x, y + 1 });
        pixelStack.push({ x, y - 1 });
    }
}
void Canvas::resized()
{
    int w = getWidth();
    int h = getHeight();
    if (w <= 0 || h <= 0) return;

    if (backgroundImage.isValid())
    {
        juce::Image newImage(juce::Image::ARGB, w, h, true);
        Graphics g(newImage);
        g.fillAll(backgroundColor);
        g.drawImage(backgroundImage, 0, 0, w, h, 0, 0, backgroundImage.getWidth(), backgroundImage.getHeight());
        backgroundImage = newImage;
    }
    else
    {
        backgroundImage = juce::Image(juce::Image::ARGB, w, h, true);
        Graphics g(backgroundImage);
        g.fillAll(backgroundColor);
    }
}

Canvas::Canvas()
{
    backgroundImage = juce::Image(juce::Image::ARGB, 1280, 720, true);
    Graphics g(backgroundImage);
    g.fillAll(backgroundColor);
}

Canvas::~Canvas() {}

void Canvas::mouseDown(const MouseEvent& e)
{
    if (currentLine.figures == Canvas::Line::Figures::brush || currentLine.figures == Canvas::Line::Figures::eraser)
    {
        currentLine.points.clear();
        currentLine.start = e.getPosition();
        currentLine.thickness = getThickness();
        currentLine.opacity = getOpacity();
        currentLine.points.push_back(currentLine.start);
        isDragging = true;
    }
    else if (currentLine.figures == Canvas::Line::Figures::fillFigure)
    {
        if (backgroundImage.isValid())
            undoStack.push(backgroundImage.createCopy());
        else
        {
            juce::Image emptyImage(juce::Image::ARGB, getWidth(), getHeight(), true);
            Graphics g(emptyImage);
            g.fillAll(backgroundColor);
            undoStack.push(emptyImage);
        }
        while (!redoStack.empty()) redoStack.pop();

        FillFigure(e.getPosition(), backgroundImage, currentLine.colour);
        repaint();
        return;
    }
    else
    {
        currentLine.thickness = getThickness();
        currentLine.opacity = getOpacity();
        currentLine.start = e.getPosition();
        currentLine.end = e.getPosition();
        isDragging = true;
    }
}

void Canvas::mouseDrag(const MouseEvent& e)
{
    if (!isDragging) return;

    if (currentLine.figures == Canvas::Line::Figures::brush || currentLine.figures == Canvas::Line::Figures::eraser)
    {
        currentLine.points.push_back(e.getPosition());
    }
    else
    {
        currentLine.end = e.getPosition();
    }

    repaint();
}

void Canvas::mouseUp(const MouseEvent& e)
{
    if (!isDragging) return;

    if (currentLine.figures != Canvas::Line::Figures::brush &&
        currentLine.figures != Canvas::Line::Figures::eraser)
    {
        currentLine.end = e.getPosition();
    }

    if (backgroundImage.isValid())
        undoStack.push(backgroundImage.createCopy());
    else
    {
        juce::Image emptyImage(juce::Image::ARGB, getWidth(), getHeight(), true);
        Graphics g(emptyImage);
        g.fillAll(backgroundColor);
        undoStack.push(emptyImage);
    }
    while (!redoStack.empty()) redoStack.pop();

    Path path;
    Graphics g(backgroundImage);
    DrawFigures(currentLine, g, path, opacity);

    currentLine.start = { 0,0 };
    currentLine.end = { 0,0 };
    isDragging = false;

    repaint();
}

void Canvas::paint(Graphics& g)
{
    g.fillAll(backgroundColor);
    if (backgroundImage.isValid())
    {
        g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(),
            0, 0, backgroundImage.getWidth(), backgroundImage.getHeight());
    }
    if (isDragging)
    {
        Path a;
        DrawFigures(currentLine, g, a, opacity);
    }
}
void Canvas::DeleteLines()
{
    if (backgroundImage.isValid())
        undoStack.push(backgroundImage.createCopy());
    else
    {
        juce::Image emptyImage(juce::Image::ARGB, getWidth(), getHeight(), true);
        Graphics g(emptyImage);
        g.fillAll(backgroundColor);
        undoStack.push(emptyImage);
    }
    while (!redoStack.empty()) redoStack.pop();

    backgroundImage = juce::Image(juce::Image::ARGB, getWidth(), getHeight(), true);
    Graphics g(backgroundImage);
    g.fillAll(backgroundColor);

    currentLine = Canvas::Line();
    isDragging = false;
    repaint();
}
void Canvas::CancelStep()
{
    if (undoStack.empty()) return;

    redoStack.push(backgroundImage.createCopy());
    backgroundImage = undoStack.top();
    undoStack.pop();

    if (!backgroundImage.isValid())
    {
        backgroundImage = juce::Image(juce::Image::ARGB, getWidth(), getHeight(), true);
        Graphics g(backgroundImage);
        g.fillAll(backgroundColor);
    }

    repaint();
}

void Canvas::ReturnStep()
{
    if (redoStack.empty()) return;

    undoStack.push(backgroundImage.createCopy());
    backgroundImage = redoStack.top();
    redoStack.pop();

    repaint();
}
void Canvas::saveCanvasToPNG()
{
    if (getWidth() <= 0 || getHeight() <= 0 || !backgroundImage.isValid())
    {
        juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
            "Error", "Canvas is empty or invalid!");
        return;
    }

    currentChooser = std::make_unique<juce::FileChooser>(
        "Save Canvas as PNG",
        juce::File::getSpecialLocation(juce::File::userDocumentsDirectory),
        "*.png"
    );

    currentChooser->launchAsync(
        juce::FileBrowserComponent::saveMode | juce::FileBrowserComponent::warnAboutOverwriting,
        [this](const juce::FileChooser& chooser)
        {
            juce::File file = chooser.getResult();
            if (file == juce::File{}) return;

            juce::FileOutputStream stream(file);
            if (stream.openedOk())
            {
                juce::PNGImageFormat pngFormat;
                if (pngFormat.writeImageToStream(backgroundImage, stream))
                    juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
                        "Success", "Canvas saved!");
                else
                    juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
                        "Error", "Failed to save.");
            }
            else
                juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
                    "Error", "Could not create file.");

            currentChooser.reset();
        }
    );
}
void Canvas::loadPNGFromFile()
{
    currentChooser = std::make_unique<juce::FileChooser>(
        "Open PNG Image",
        juce::File::getSpecialLocation(juce::File::userDocumentsDirectory),
        "*.png"
    );

    currentChooser->launchAsync(
        juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
        [this](const juce::FileChooser& chooser)
        {
            juce::File file = chooser.getResult();
            if (file == juce::File{}) return;

            juce::Image loaded = juce::PNGImageFormat::loadFrom(file);
            if (loaded.isValid())
            {
                backgroundImage = loaded;
                currentLine = Canvas::Line();
                isDragging = false;
                repaint();
                juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
                    "Success", "Image loaded.");
            }
            else
                juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
                    "Error", "Failed to load PNG.");

            currentChooser.reset();
        }
    );
}