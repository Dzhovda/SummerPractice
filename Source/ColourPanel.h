#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;
class ColourPanel: public Slider
{
public:
	ColourPanel(Canvas* owner);
	~ColourPanel(void);
	void paint(Graphics&) override;
	/*void mouseDown(const MouseEvent&) override;
	void mouseDrag(const MouseEvent&) override;
	void mouseUp(const MouseEvent&) override;*/
	void resized(void) override;
	void valueChanged() override;
private:

	Canvas* owner = nullptr;
	std::vector<Colour>colours{Colours::red, Colours::orange, Colours::yellow, Colours::green, Colours::blue, Colours::violet};
	ColourGradient FColourGradient;
};

