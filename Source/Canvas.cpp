#include "Canvas.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "ButtonsPanel.h"
Canvas::Canvas()
{
}
Canvas::~Canvas(){}

void drawPath(Graphics& g, Path a, float& opacity, bool fill, int thickness, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, bool triangle = false) {
    if (triangle == true) {
        if (fill == true) {
            g.setOpacity(opacity);
            a.addTriangle(X1, Y1, X2, Y2, X3, Y3);
            g.fillPath(a);
        }
        else {
            g.setOpacity(opacity);
            a.addTriangle(X1, Y1, X2, Y2, X3, Y3);
            g.strokePath(a, juce::PathStrokeType(thickness));
        }
    }
    else {
        if (fill == true) {
            g.setOpacity(opacity);
            a.addQuadrilateral(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
            g.fillPath(a);
        }
        else {
            g.setOpacity(opacity);
            a.addQuadrilateral(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
            g.strokePath(a, juce::PathStrokeType(thickness));
        }
    }
}
void DrawFromLines(std::vector<Canvas::Line> lines, Canvas::Line line, Colour backgroundColor, Graphics& g, Path a, float opacity) {
    for (int i = 0; i < lines.size(); i++) {
        line = lines[i];
        g.setColour(line.colour);
        if (line.figures == Canvas::Line::Figures::brush) {
            for (int i = 0; i < size(line.points);i++) {
                Point point = line.points[i];
                g.drawRect(point.x, point.y, line.thickness, line.thickness, line.thickness);
            }
        }
        if (line.figures == Canvas::Line::Figures::eraser) {
            for (int i = 0; i < size(line.points);i++) {
                g.setColour(backgroundColor);
                Point point = line.points[i];
                g.drawRect(point.x, point.y, line.thickness, line.thickness, line.thickness);
            }
        }
        if (line.figures == Canvas::Line::Figures::line) {
            g.drawLine(line.start.x, line.start.y, line.end.x, line.end.y, line.thickness);
        }
        if (line.figures == Canvas::Line::Figures::rect) {
            int x1 = std::min(line.start.x, line.end.x), y1 = std::min(line.start.y, line.end.y);
            int x2 = std::max(line.start.x, line.end.x), y2 = std::min(line.start.y, line.end.y);
            int x3 = std::max(line.start.x, line.end.x), y3 = std::max(line.start.y, line.end.y);
            int x4 = std::min(line.start.x, line.end.x), y4 = std::max(line.start.y, line.end.y);
            drawPath(g, a, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (line.figures == Canvas::Line::Figures::triangle) {
            int x1 = line.start.x;
            int y1 = line.start.y;
            int x2 = line.end.x;
            int y2 = line.end.y;
            int x3 = line.start.x - (line.end.x - line.start.x); // 2*start.x - end.x
            int y3 = line.end.y;
            drawPath(g, a, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, 0, 0, true);
        }
        if (line.figures == Canvas::Line::Figures::romb) {
            int x1 = line.start.x + abs(line.end.x - line.start.x);
            int y1 = line.start.y;
            int x2 = line.start.x;
            int y2 = line.start.y + abs(line.start.y - line.end.y);
            int x3 = line.start.x - abs(line.end.x - line.start.x);
            int y3 = line.start.y;
            int x4 = line.start.x;
            int y4 = line.start.y - abs(line.start.y - line.end.y);
            drawPath(g, a, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (line.figures == Canvas::Line::Figures::trapezoid) {
            int x1 = line.start.x;
            int y1 = line.start.y;
            int x2 = line.end.x + 0.2 * abs(line.start.x - line.end.x);
            int y2 = line.start.y;
            int x3 = line.end.x;
            int y3 = line.end.y;
            int x4 = line.start.x + 0.2 * abs(line.start.x - line.end.x);
            int y4 = line.end.y;

            drawPath(g, a, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (line.figures == Canvas::Line::Figures::parallelogram) {
            int x1 = line.start.x;
            int y1 = line.start.y;
            int x2 = line.end.x - 0.2 * abs(line.start.x - line.end.x);
            int y2 = line.start.y;
            int x3 = line.end.x;
            int y3 = line.end.y;
            int x4 = line.start.x + 0.2 * abs(line.start.x - line.end.x);
            int y4 = line.end.y;
            drawPath(g, a, opacity, line.fill, line.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (line.figures == Canvas::Line::Figures::ellipse) {
            g.drawEllipse(std::min(line.start.x, line.end.x), std::min(line.start.y, line.end.y),
                abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
        }
        if (line.figures == Canvas::Line::Figures::polygon) {

        }
    }
}
void Canvas::mouseDown(const MouseEvent& e) {
    if (currentLine.figures == Line::Figures::brush || currentLine.figures == Line::Figures::eraser) {
        currentLine.points.clear();
        
        currentLine.start = e.getPosition();
        currentLine.thickness = getThickness();
        currentLine.opacity = getOpacity();
        currentLine.points.push_back(currentLine.start);
        isDragging = true;
    }
    else {
        currentLine.end.setX(0);
        currentLine.end.setY(0);
        currentLine.thickness = getThickness();
        currentLine.opacity = getOpacity();

        currentLine.start = e.getPosition();
        isDragging = true;
    }   
}
void Canvas::mouseDrag(const MouseEvent& e) {
    if (currentLine.figures == Line::Figures::brush || currentLine.figures == Line::Figures::eraser) {
        currentLine.end = e.getPosition();
        currentLine.points.push_back(currentLine.end);
        repaint();
    }
    else {
        currentLine.end = e.getPosition();
        repaint();
    }
}
void Canvas::mouseUp(const MouseEvent& e) {
    currentLine.end = e.getPosition();
    lines.push_back(currentLine);
    isDragging = false;
    repaint();
}
void Canvas::paint(Graphics& g)
{
    g.fillAll(backgroundColor);
    Line line;
    Path a;
    if (isDragging) {
        g.setColour(currentLine.colour);
        g.setOpacity(opacity);// от 0.0 до 1.0 исправить
        if (currentLine.figures == Line::Figures::brush) {
            for (int i = 0; i < size(currentLine.points);i++) {
                Point point = currentLine.points[i];
                g.drawRect(point.x,point.y, currentLine.thickness, currentLine.thickness, currentLine.thickness);
            }
        }
        if (currentLine.figures == Line::Figures::eraser) {
            for (int i = 0; i < size(currentLine.points);i++) {
                g.setColour(backgroundColor);
                Point point = currentLine.points[i];
                g.drawRect(point.x, point.y, currentLine.thickness, currentLine.thickness, currentLine.thickness);
            }
        }
        //разбиение на рисование фигур 
        if (currentLine.figures == Line::Figures::line) {
            g.drawLine(currentLine.start.x, currentLine.start.y,
                currentLine.end.x, currentLine.end.y,
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::rect) {
            g.setColour(currentLine.colour.withAlpha(opacity));
            int x1 = std::min(currentLine.start.x, currentLine.end.x), y1 = std::min(currentLine.start.y, currentLine.end.y);
            int x2 = std::max(currentLine.start.x, currentLine.end.x), y2 = std::min(currentLine.start.y, currentLine.end.y);
            int x3 = std::max(currentLine.start.x, currentLine.end.x), y3 = std::max(currentLine.start.y, currentLine.end.y);
            int x4 = std::min(currentLine.start.x, currentLine.end.x), y4 = std::max(currentLine.start.y, currentLine.end.y);
            drawPath(g, a, opacity, currentLine.fill, currentLine.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (currentLine.figures == Line::Figures::triangle) {
            int x1 = currentLine.start.x;
            int y1 = currentLine.start.y;
            int x2 = currentLine.end.x;
            int y2 = currentLine.end.y;
            int x3 = currentLine.start.x - (currentLine.end.x - currentLine.start.x); // 2*start.x - end.x
            int y3 = currentLine.end.y;
            drawPath(g, a, opacity, currentLine.fill, currentLine.thickness, x1, y1, x2, y2, x3, y3, 0, 0, true);
        }
        if (currentLine.figures == Line::Figures::romb) {
            int x1 = currentLine.start.x + abs(currentLine.end.x - currentLine.start.x);
            int y1 = currentLine.start.y;
            int x2 = currentLine.start.x;
            int y2 = currentLine.start.y + abs(currentLine.start.y - currentLine.end.y);
            int x3 = currentLine.start.x - abs(currentLine.end.x - currentLine.start.x);
            int y3 = currentLine.start.y;
            int x4 = currentLine.start.x;
            int y4 = currentLine.start.y - abs(currentLine.start.y - currentLine.end.y);
            drawPath(g, a, opacity, currentLine.fill, currentLine.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (currentLine.figures == Line::Figures::trapezoid) {
            int x1 = currentLine.start.x;
            int y1 = currentLine.start.y;
            int x2 = currentLine.end.x + 0.2 * abs(currentLine.start.x - currentLine.end.x);;
            int y2 = currentLine.start.y;
            int x3 = currentLine.end.x;
            int y3 = currentLine.end.y;
            int x4 = currentLine.start.x + 0.2 * abs(currentLine.start.x - currentLine.end.x);;
            int y4 = currentLine.end.y;
            drawPath(g, a, opacity, currentLine.fill, currentLine.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (currentLine.figures == Line::Figures::parallelogram) {
            int x1 = currentLine.start.x;
            int y1 = currentLine.start.y;
            int x2 = currentLine.end.x - 0.2 * abs(currentLine.start.x - currentLine.end.x);;
            int y2 = currentLine.start.y;
            int x3 = currentLine.end.x;
            int y3 = currentLine.end.y;
            int x4 = currentLine.start.x + 0.2 * abs(currentLine.start.x - currentLine.end.x);;
            int y4 = currentLine.end.y;
            drawPath(g, a, opacity, currentLine.fill, currentLine.thickness, x1, y1, x2, y2, x3, y3, x4, y4);
        }
        if (currentLine.figures == Line::Figures::ellipse) {
            g.drawEllipse(std::min(currentLine.start.x, currentLine.end.x), std::min(currentLine.start.y, currentLine.end.y),
                abs(currentLine.start.x - currentLine.end.x),
                abs(currentLine.start.y - currentLine.end.y),
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::polygon) {

        }
    }
    DrawFromLines(lines, line, backgroundColor, g, a, opacity);
}
void Canvas::saveCanvasToPNG()
{
    Line line;
    Path a;
    //juce::FileChooser chooser("Save To PNG", juce::File::getSpecialLocation(juce::File::userDocumentsDirectory), "*.png");

    juce::File file = juce::File::getSpecialLocation(juce::File::currentExecutableFile)
        .getParentDirectory()
        .getChildFile("canvas_export.png");

    //File file = chooser.getResult();

    int canvasWidth = getWidth();
    int canvasHieght = getHeight();

    Image image(Image::ARGB, canvasWidth, canvasHieght, true);
    Graphics g(image);

    g.fillAll(backgroundColor);
    DrawFromLines(lines, line, backgroundColor, g, a, opacity);

    FileOutputStream stream(file);

    if (stream.openedOk())
    {
        juce::PNGImageFormat pngFormat;
        if (pngFormat.writeImageToStream(image, stream))
            juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::InfoIcon,
                "Success", "Canvas saved successfully!");
        else
            juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
                "Error", "Failed to write PNG file.");
    }
    else
    {
        juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
            "Error", "Could not create file.");
    }
}
void Canvas::loadPNGFromFile() {

}