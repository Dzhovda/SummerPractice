#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ButtonsPanel.h"
#include "Canvas.h"
#include "ButtonsPanelLeft.h"
#include "ColourPanel.h"
#include "SliderPanels.h"
class MainComponent : public Component
{
public:
    MainComponent(void);
    ~MainComponent(void) override;
    void resized(void) override;
private:
    
    Canvas* canvas;
    ButtonsPanel* buttonsPanel;
    ButtonsPanelLeft* buttonsPanelLeft;
    ColourPanel* colourPanel;
    SliderPanels* sliderPanels;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};