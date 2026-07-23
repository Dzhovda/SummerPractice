
#include "ColourPanel.h"
#include "Canvas.h"
ColourPanel::ColourPanel(Canvas* owner) : FColourGradient()
{
    this->owner = owner;

    // Настройка градиента
    FColourGradient.addColour(0.0f, Colours::red);
    FColourGradient.addColour(0.18f, Colours::orange);
    FColourGradient.addColour(0.36f, Colours::yellow);
    FColourGradient.addColour(0.54f, Colours::green);
    FColourGradient.addColour(0.72f, Colours::blue);
    FColourGradient.addColour(0.9f, Colours::violet);
    // FColourGradient.addColour(1.0f, Colours::black); // закомментировано для расширения спектра

    // Настройка слайдера
    setSliderStyle(Slider::LinearHorizontal);
    setRange(0.0, 0.8, 0.01); // диапазон сужен для лучшего визуального соответствия
    setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
}
ColourPanel::~ColourPanel() {}
void ColourPanel::valueChanged()
{
    float hue = (float)getValue();
    Colour newColour = Colour::fromHSV(hue, 1.0f, 1.0f, 1.0f);
    owner->setCurrentColour(newColour);
}
void ColourPanel::paint(Graphics& g)
{
    auto area = getLocalBounds().toFloat();

    // Настройка координат градиента (горизонтальный)
    FColourGradient.point1 = area.getTopLeft();
    FColourGradient.point2 = area.getTopRight();

    g.setGradientFill(FColourGradient);
    g.fillRoundedRectangle(area, 1.0f);

    // Отрисовка стандартного бегунка слайдера
    Slider::paint(g);
}
void ColourPanel::resized()
{
    Slider::resized();
}