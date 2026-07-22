#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;
class SliderPanels: public Slider::Listener, public Slider
{
public:
	SliderPanels(Canvas* owner);
	~SliderPanels();
	JUCE_LEAK_DETECTOR(SliderPanels)
	void paint(Graphics&) override;
	void resized(void) override;
	void sliderValueChanged(Slider* slider) override;

private:
	Canvas* owner;
	Slider sliderThickness;
	Slider sliderOpacity;
};

