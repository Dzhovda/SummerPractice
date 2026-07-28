#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <stack>

class Canvas : public Component
{
public:
    Canvas(void);
    ~Canvas(void) override;

    void resized() override;
    void paint(Graphics&) override;
    void mouseDown(const MouseEvent&) override;
    void mouseDrag(const MouseEvent&) override;
    void mouseUp(const MouseEvent&) override;

    struct Line
    {
        Point<int> start;
        Point<int> end;
        Colour colour;
        int thickness;
        enum Figures { brush, eraser, fillFigure, line, rect, triangle, romb, trapezoid, parallelogram, ellipse, polygon };
        Figures figures;
        float opacity = 1.0f;
        bool fill = false;
        std::vector<Point<int>> points;
    };

    // Управление инструментами
    void SetFigures(Line::Figures figures) { currentLine.figures = figures; }
    void SetFill(bool fill) { currentLine.fill = fill; }
    bool GetFill() { return currentLine.fill; }
    void setCurrentColour(Colour colour) { currentLine.colour = colour; }
    void setCurrentThickness(int thickness) { this->thickness = thickness; }
    void setCurrentOpacity(int opacity) { this->opacity = opacity; }
    int getThickness() { return this->thickness; }
    int getOpacity() { return this->opacity; }

    // Действия с холстом
    void DeleteLines();
    void CancelStep();
    void ReturnStep();

    // Файловые операции
    void saveCanvasToPNG();
    void loadPNGFromFile();

private:
    bool isDragging = false;
    Line currentLine;
    int thickness = 1;
    float opacity = 1.0f;
    juce::Colour backgroundColor = Colour(200, 200, 200);
    juce::Image backgroundImage;
    std::unique_ptr<juce::FileChooser> currentChooser;

    std::stack<juce::Image> undoStack; // для Cancel
    std::stack<juce::Image> redoStack; // для Return

    // Вспомогательная функция отрисовки (используется и в paint, и в mouseUp)
    void DrawFigures(Line& line, Graphics& g, Path& path, float opacity);
};