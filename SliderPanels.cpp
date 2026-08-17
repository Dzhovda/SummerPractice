#include "SliderPanels.h"
#include "Canvas.h"
#include <iostream>

SliderPanels::SliderPanels(Canvas* owner)
{
    this->owner = owner;

    // Настройка слайдера толщины
    sliderThickness.setSliderStyle(Slider::LinearHorizontal);
    sliderThickness.setRange(1, 40, 1);
    sliderThickness.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 30);

    // Настройка слайдера прозрачности
    sliderOpacity.setSliderStyle(Slider::LinearHorizontal);
    sliderOpacity.setRange(0.0f, 1.0f, 0.05f);
    sliderOpacity.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 30);

    // Подписка на события и добавление в иерархию
    sliderThickness.addListener(this);
    sliderOpacity.addListener(this);
    addAndMakeVisible(sliderOpacity);
    addAndMakeVisible(sliderThickness);
}

SliderPanels::~SliderPanels()
{
    // Слушатели автоматически отписываются при разрушении
}

void SliderPanels::paint(Graphics& g)
{
    g.setColour(juce::Colours::black);
    g.setFont(juce::Font(16.0f, juce::Font::bold));

    auto bounds = getLocalBounds();
    float centerX = 20.0f;   // Отступ слева
    float centerY = bounds.getHeight() / 3.0f;

    juce::String text = juce::String::fromUTF8(u8"Толщина");
    juce::Rectangle<float> textArea(centerX - 30, centerY - 20, 140, 20);
    g.drawText(text, textArea, juce::Justification::centred, true);

    juce::String text2 = juce::String::fromUTF8(u8"Прозрачность");
    juce::Rectangle<float> textArea2(centerX + 125, centerY - 20, 140, 20);
    g.drawText(text2, textArea2, juce::Justification::centred, true);
}

void SliderPanels::sliderValueChanged(Slider* slider)
{
    if (slider == &sliderThickness)
    {
        int thickness = sliderThickness.getValue();
        owner->setCurrentThickness(thickness);
    }
    if (slider == &sliderOpacity)
    {
        int opacity = sliderOpacity.getValue();
        owner->setCurrentOpacity(opacity);
    }
}

void SliderPanels::resized(void)
{
    sliderThickness.setBounds(0, 30, 120, 32);
    sliderOpacity.setBounds(161, 30, 120, 32);
}