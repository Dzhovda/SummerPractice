#include "../Include/MainComponent.h"

//topbar = 100(file -  1280x30(144 160 173), ToolsPanel - 1280x70(191 90 90))
//leftToolsBar(80x620)(144 160 173)
//buttons - 26x26, sliders - 120x6, перемычки - 13x70, перемычкиLeft - 13x80

// начать делать разметку как в макете, разобратьс€ с масштабированием, отрисовать все кнопки
MainComponent::MainComponent(void)
    : FLeftPanelButton1(TextButton(String("Line"))),
    FLeftPanelButton2(TextButton(String("Rect"))),
    FLeftPanelButton3(TextButton(String("Ellipse"))),
    //FLeftPanelButton4(TextButton(String("mel"))),
    FUpPanelButton1(TextButton(String("thickness"))),
    FUpColourButton1(TextButton(String("red"))),
    FUpColourButton2(TextButton(String("green"))),
    FUpColourButton3(TextButton(String("black")))
{
    setOpaque(true);
    //setSize(800, 800);

    addAndMakeVisible(FLeftPanelButton1);
    addAndMakeVisible(FLeftPanelButton2);
    addAndMakeVisible(FLeftPanelButton3);
    //addAndMakeVisible(FLeftPanelButton4);
    addAndMakeVisible(FUpPanelButton1);
    addAndMakeVisible(FUpColourButton1);
    addAndMakeVisible(FUpColourButton2);
    addAndMakeVisible(FUpColourButton3);
    //блок слушател€ кнопок цвета
    currentLine.colour = Colours::black;
    FUpColourButton1.addListener(this);
    FUpColourButton2.addListener(this);
    FUpColourButton3.addListener(this);
    //блок слушател€ кнопок режима геометрии
    FLeftPanelButton1.addListener(this);
    FLeftPanelButton2.addListener(this);
    FLeftPanelButton3.addListener(this);
}
//
MainComponent::~MainComponent(void)
{
}
void MainComponent::buttonClicked(Button* button) {
    if (button == &FUpColourButton1) {
        currentLine.colour = Colours::red;
    }
    if (button == &FUpColourButton2) {
        currentLine.colour = Colours::green;
    }
    if (button == &FUpColourButton3) {
        currentLine.colour = Colours::black;
    }
    if (button == &FLeftPanelButton1) {
        //tool = Tools::line;
        currentLine.figures = Line::Figures::line;
    }
    if (button == &FLeftPanelButton2) {
        //tool = Tools::rect;
        currentLine.figures = Line::Figures::rect;
    }
    if (button == &FLeftPanelButton3) {
        //tool = Tools::ellipse;
        currentLine.figures = Line::Figures::ellipse;
    }
}
////////////////////засунуть в функцию дл€ линии
void MainComponent::mouseDown(const MouseEvent& e) {
    currentLine.end.setX(0);
    currentLine.end.setY(0);
    currentLine.start = e.getPosition();
    isDragging = true;
}
void MainComponent::mouseDrag(const MouseEvent& e) {
    currentLine.end = e.getPosition();
    repaint();
}
void MainComponent::mouseUp(const MouseEvent& e) {
    currentLine.end = e.getPosition();
    lines.push_back(currentLine);
    isDragging = false;
    repaint();
}
void MainComponent::paint(Graphics& g)
{
    Line line;
    g.fillAll(Colours::powderblue);
    g.drawRect(110, 100, 1100, 550); //примерное положение полотна до введени€ множителей
    if (isDragging) {
        g.setColour(currentLine.colour);
        //разбиение на рисование фигур
        if (currentLine.figures == Line::Figures::line) {
            g.drawLine(currentLine.start.x, currentLine.start.y,
                currentLine.end.x, currentLine.end.y,
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::rect) {
            g.drawRect(currentLine.start.x, currentLine.start.y,
                abs(currentLine.start.x - currentLine.end.x),
                abs(currentLine.start.y - currentLine.end.y),
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::ellipse) {
            g.drawEllipse(currentLine.start.x, currentLine.start.y,
                abs(currentLine.start.x - currentLine.end.x),
                abs(currentLine.start.y - currentLine.end.y),
                currentLine.thickness);
        }
    }
    for (int i = 0; i < lines.size(); i++) {
        line = lines[i];
        g.setColour(line.colour);
        if (line.figures == Line::Figures::line) {
            g.drawLine(line.start.x, line.start.y, line.end.x, line.end.y, line.thickness);
        }
        if (line.figures == Line::Figures::rect) {
            g.drawRect(line.start.x, line.start.y, abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
        }
        if (line.figures == Line::Figures::ellipse) {
            g.drawEllipse(line.start.x, line.start.y, abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
        }
    }
}
////////////////////////////////////
//сделать свою функцию€ дл€ рисовани€ фигур с единым алгоритмом запоминани€ координат но с разными функци€ми рисовани€

//
void MainComponent::resized(void)
{
    FLeftPanelButton1.setBounds(50, 100, 50, 50);
    FLeftPanelButton2.setBounds(50, 155, 50, 50);
    FLeftPanelButton3.setBounds(50, 210, 50, 50);
    FLeftPanelButton4.setBounds(50, 265, 50, 50);
    FUpPanelButton1.setBounds(110, 40, 50, 50);
    FUpColourButton1.setBounds(500,40,50,50);
    FUpColourButton2.setBounds(560, 40, 50, 50);
    FUpColourButton3.setBounds(620, 40, 50, 50);
}