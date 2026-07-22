#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ButtonsPanel.h"
#include "Canvas.h"
#include "ButtonsPanelLeft.h"
#include "ColourPanel.h"
#include "SliderPanels.h"
#include "MenuModel.h"
class MainComponent : public Component
{
public:
    MainComponent(void);
    ~MainComponent(void) override;
    //JUCE_LEAK_DETECTOR(MainComponent)
    void resized(void) override;
    Canvas* getCanvas() const { return canvas; }
private:
    
    Canvas* canvas;
    ButtonsPanel* buttonsPanel;
    ButtonsPanelLeft* buttonsPanelLeft;
    ColourPanel* colourPanel;
    SliderPanels* sliderPanels;
    MenuModel* menuModel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};