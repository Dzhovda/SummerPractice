#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
//
class MainComponent : public Component, public Button::Listener
{
public:
    MainComponent(void);
    ~MainComponent(void) override;
    //
    void paint(Graphics&) override;
    void resized(void) override;
    void mouseDown(const MouseEvent&);
    void mouseDrag(const MouseEvent&);
    void mouseUp(const MouseEvent&);
    void buttonClicked(Button*);
private:
    // кнопки левой панели
    
    // кнопки верхней панели
    //TextButton FUpPanelButton1;
    TextButton FUpPanelButton1;
    TextButton FUpPanelButton2;
    TextButton FUpPanelButton3;
    TextButton FUpPanelButton4;
    TextButton FUpPanelButton5;
    TextButton FUpPanelButton6;
    TextButton FUpPanelButton7;
    TextButton FUpPanelButton8;
    // 3 кнопки цвета(временный вариант до введения градиента выбора)
    TextButton FUpColourButton1;
    TextButton FUpColourButton2;
    TextButton FUpColourButton3;
    // блок рисования
    struct Line// стракт для храннеия данных рисования линии, квадрата, элипса
    {
        Point<int> start;
        Point<int> end;
        Colour colour;
        int thickness = 1;
        enum Figures {line, rect, triangle, romb, trapezoid, parallelogram, ellipse, polygon};
        Figures figures;
    };
    std::vector<Line> lines;
    bool isDragging;
    Line currentLine; // временные данные рисования
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};