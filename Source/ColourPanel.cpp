#include "ColourPanel.h"
#include "Canvas.h"
ColourPanel::ColourPanel(Canvas* owner): FColourGradient()
{
	this->owner = owner;
	FColourGradient.addColour(0.0f, Colours::red);
	FColourGradient.addColour(0.18f, Colours::orange);
	FColourGradient.addColour(0.36f, Colours::yellow);
	FColourGradient.addColour(0.54f, Colours::green);
	FColourGradient.addColour(0.72f, Colours::blue);
	FColourGradient.addColour(0.9f, Colours::violet);
	//FColourGradient.addColour(1.0f, Colours::black);

	setSliderStyle(Slider::LinearHorizontal);
	setRange(0.0, 0.8, 0.01); // путем изменения интервала и длины, и длины цветом на градиенте можно менять визуальное совпадение сцветом
	setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	//sliderValueChanged(Slider*);
	//addAndMakeVisible(slider);
}
ColourPanel::~ColourPanel() {

}
void ColourPanel::valueChanged() {
	float hue = (float)getValue();
	Colour newColour = Colour::fromHSV(hue, 1.0f, 1.0f, 1.0f);
	owner->setCurrentColour(newColour);
}
void ColourPanel::paint(Graphics &g) {
	auto area = getLocalBounds().toFloat();
	FColourGradient.point1 = area.getTopLeft();
	FColourGradient.point2 = area.getTopRight(); // горизонтальный градиент
	g.setGradientFill(FColourGradient);
	g.fillRoundedRectangle(area, 1.0f);
	Slider::paint(g);
}
void ColourPanel::resized() {
	Slider::resized();
}