#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas: public Component
{
public:
    Canvas(void);
    ~Canvas(void) override;
    JUCE_LEAK_DETECTOR(Canvas)
    void paint(Graphics&) override;
    void mouseDown(const MouseEvent&) override;
    void mouseDrag(const MouseEvent&) override;
    void mouseUp(const MouseEvent&) override;

    struct Line// стракт для храннеия данных рисования линии, квадрата, элипса
    {
        Point<int> start;
        Point<int> end;
        Colour colour;
        int thickness;
        enum Figures { brush, eraser, line, rect, triangle, romb, trapezoid, parallelogram, ellipse, polygon };
        Figures figures;
        float opacity = 1.0f;
        bool fill = false;
        std::vector<Point<int>> points;
    };
    //для левой панели
    void SetFigures(Line::Figures figures) {
        currentLine.figures = figures;
    }
    void SetFill(bool fill) {
        currentLine.fill = fill;
    }
    bool GetFill() {
        return currentLine.fill;
    }
    //для цвета
    void setCurrentColour(Colour colour) {
        currentLine.colour = colour;
    }
    //для ползунков
    void setCurrentThickness(int thickness){
        this->thickness = thickness;
    }
    void setCurrentOpacity(int opacity) {
        this->opacity = opacity;
    }
    int getThickness()
    {
        return this->thickness;
    }
    int getOpacity()
    {
        return this->opacity;
    }
    void DeleteLines() {
        lines.clear();
        currentLine = Line();
        isDragging = false;
        backgroundImage = juce::Image();
        repaint();
    }
    // Files
    void saveCanvasToPNG();
    void loadPNGFromFile();
private:
    // блок рисования
    std::vector<Line> lines;
    bool isDragging;
    Line currentLine; // временные данные рисования
    int thickness = 1;
    float opacity = 1.0f;
    juce::Colour backgroundColor = Colour(200, 200, 200);
    juce::Image backgroundImage;
};

