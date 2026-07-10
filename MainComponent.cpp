#include "../Include/MainComponent.h"

//topbar = 100(file -  1280x30(144 160 173), ToolsPanel - 1280x70(191 90 90))
//leftToolsBar(80x620)(144 160 173)
//buttons - 26x26, sliders - 120x6, перемычки - 13x70, перемычкиLeft - 13x80

// начать делать разметку как в макете, разобратьс€ с масштабированием, отрисовать все кнопки
MainComponent::MainComponent(void)
    : FUpPanelButton1(TextButton(String("Line"))),
    FUpPanelButton2(TextButton(String("Rect"))),
    FUpPanelButton3(TextButton(String("Triangle"))),
    FUpPanelButton4(TextButton(String("Romb"))),
    FUpPanelButton5(TextButton(String("Trapezoid"))),
    FUpPanelButton6(TextButton(String("Parallelogram"))),
    FUpPanelButton7(TextButton(String("Ellipse"))),
    FUpPanelButton8(TextButton(String("Polygon"))),
    FUpColourButton1(TextButton(String("red"))),
    FUpColourButton2(TextButton(String("green"))),
    FUpColourButton3(TextButton(String("black")))
{
    setOpaque(true);
    //setSize(800, 800);

    addAndMakeVisible(FUpPanelButton1);
    addAndMakeVisible(FUpPanelButton2);
    addAndMakeVisible(FUpPanelButton3);
    addAndMakeVisible(FUpPanelButton4);
    addAndMakeVisible(FUpPanelButton5);
    addAndMakeVisible(FUpPanelButton6);
    addAndMakeVisible(FUpPanelButton7);
    addAndMakeVisible(FUpPanelButton8);
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
    FUpPanelButton1.addListener(this);
    FUpPanelButton2.addListener(this);
    FUpPanelButton3.addListener(this);
    FUpPanelButton4.addListener(this);
    FUpPanelButton7.addListener(this);
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
    if (button == &FUpPanelButton1) {
        //tool = Tools::line;
        currentLine.figures = Line::Figures::line;
    }
    if (button == &FUpPanelButton2) {
        //tool = Tools::rect;
        currentLine.figures = Line::Figures::rect;
    }
    if (button == &FUpPanelButton3) {
        currentLine.figures = Line::Figures::triangle;
    }
    if (button == &FUpPanelButton4) {
        currentLine.figures = Line::Figures::romb;
    }
    if (button == &FUpPanelButton7) {
        //tool = Tools::ellipse;
        currentLine.figures = Line::Figures::ellipse;
    }
}
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
    Path a;
    g.fillAll(Colours::powderblue);
    //верхн€€ панель
    g.drawRect(0,0,1280,70);
    //a.addTriangle(600, 600, 750, 750, 750, 600);
    //g.fillPath(a);
    //лева€ панель
    g.drawRect(0, 70, 80, 650);
    //перемычки верхней панели
    g.drawRect(80,0,13,70);
    g.drawRect(374, 0, 13, 70);
    g.drawRect(529, 0, 13, 70);
    g.drawRect(684, 0, 13, 70);
    g.drawRect(684, 0, 13, 70);
    g.drawRect(811, 0, 13, 70);
    g.drawRect(901, 0, 13, 70);
    g.drawRect(1117, 0, 13, 70);
    g.drawRect(1117, 0, 13, 70);
    g.drawRect(1198, 0, 13, 70);
    //перемычки левой панели
    g.drawRect(0, 70, 80, 13);
    g.drawRect(0, 432, 80, 13); // мб + 30 по Y
    if (isDragging) {
        g.setColour(currentLine.colour);
        //разбиение на рисование фигур
        if (currentLine.figures == Line::Figures::line) {
            g.drawLine(currentLine.start.x, currentLine.start.y,
                currentLine.end.x, currentLine.end.y,
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::rect) {
            g.drawRect(std::min(currentLine.start.x, currentLine.end.x), std::min(currentLine.start.y, currentLine.end.y),
                abs(currentLine.start.x - currentLine.end.x),
                abs(currentLine.start.y - currentLine.end.y),
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::triangle) {
            a.addTriangle(currentLine.start.x, currentLine.start.y,
                currentLine.end.x, currentLine.end.y,
                currentLine.start.x - (currentLine.end.x - currentLine.start.x), currentLine.end.y);
            g.fillPath(a);
        }
        if (currentLine.figures == Line::Figures::romb) {
            g.drawLine(currentLine.start.x, currentLine.start.y,
                currentLine.end.x, currentLine.end.y,
                currentLine.thickness);
            g.drawLine(currentLine.start.x, currentLine.start.y + 2 * abs(currentLine.start.y - currentLine.end.y),
                currentLine.end.x, currentLine.end.y,
                currentLine.thickness);// правый низ
            g.drawLine(currentLine.start.x, currentLine.start.y,
                currentLine.start.x - abs(currentLine.start.x - currentLine.end.x), currentLine.end.y,
                currentLine.thickness);
        }
        if (currentLine.figures == Line::Figures::ellipse) {
            g.drawEllipse(std::min(currentLine.start.x, currentLine.end.x), std::min(currentLine.start.y, currentLine.end.y),
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
            g.drawRect(std::min(line.start.x, line.end.x), std::min(line.start.y, line.end.y), abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
        }
        if (line.figures == Line::Figures::triangle) {
            a.addTriangle(line.start.x, line.start.y, line.end.x, line.end.y, line.start.x - (line.end.x - line.start.x), line.end.y);
            g.fillPath(a);
        }
        if (line.figures == Line::Figures::romb) {
            g.drawLine(line.start.x, line.start.y,
                line.end.x, line.end.y,
                line.thickness);
            g.drawLine(line.start.x, line.start.y + 2 * abs(line.start.y - line.end.y),
                line.end.x, line.end.y,
                line.thickness);// правый низ
            g.drawLine(line.start.x, line.start.y,
                line.start.x - abs(line.start.x - line.end.x), line.end.y,
                line.thickness);
            g.drawLine(line.start.x, line.start.y,
                line.start.x - abs(line.start.x - line.end.x), line.start.y + 2 * abs(line.start.y - line.end.y),
                line.thickness);
        }
        if (line.figures == Line::Figures::ellipse) {
            g.drawEllipse(std::min(line.start.x, line.end.x), std::min(line.start.y, line.end.y), abs(line.start.x - line.end.x), abs(line.start.y - line.end.y), line.thickness);
        }
        //g.strokePath(a);
    }
    
}
////////////////////////////////////
//сделать свою функцию€ дл€ рисовани€ фигур с единым алгоритмом запоминани€ координат но с разными функци€ми рисовани€

//
void MainComponent::resized(void)
{
    FUpPanelButton1.setBounds(98, 23, 25, 25);  // - 30 по Y
    FUpPanelButton2.setBounds(133, 23, 25, 25); // +35 по X дл€ последующих кнопок по X
    FUpPanelButton3.setBounds(168, 23, 25, 25);
    FUpPanelButton4.setBounds(203, 23, 25, 25);
    FUpPanelButton5.setBounds(238, 23, 25, 25);
    FUpPanelButton6.setBounds(273, 23, 25, 25);
    FUpPanelButton7.setBounds(308, 23, 25, 25);
    FUpPanelButton8.setBounds(343, 23, 25, 25);


    //FUpPanelButton1.setBounds(110, 40, 50, 50);
    FUpColourButton1.setBounds(500,40,50,50);
    FUpColourButton2.setBounds(560, 40, 50, 50);
    FUpColourButton3.setBounds(620, 40, 50, 50);
}