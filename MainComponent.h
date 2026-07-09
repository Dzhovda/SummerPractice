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
    TextButton FLeftPanelButton1;
    TextButton FLeftPanelButton2;
    TextButton FLeftPanelButton3;
    TextButton FLeftPanelButton4;
    // кнопки верхней панели
    TextButton FUpPanelButton1;
    // 3 кнопки цвета(временный вариант до введения градиента выбора)
    TextButton FUpColourButton1;
    TextButton FUpColourButton2;
    TextButton FUpColourButton3;
    // блок рисования
    struct Line
    {
        Point<int> start;
        Point<int> end;
        Colour colour;
        int thickness = 1;
        enum Figures {line, rect, ellipse};
        Figures figures;
    };
    std::vector<Line> lines;
    bool isDragging;
    Line currentLine; // временные данные рисования
    // блок проверки нажатия кнопок
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};