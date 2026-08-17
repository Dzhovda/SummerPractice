#include "../Include/MainComponent.h"

MainComponent::MainComponent()
{
    canvas = new Canvas();
    buttonsPanelLeft = new ButtonsPanelLeft(canvas);
    buttonsPanel = new ButtonsPanel(canvas);
    colourPanel = new ColourPanel(canvas);
    sliderPanels = new SliderPanels(canvas);

    addAndMakeVisible(canvas);
    addAndMakeVisible(buttonsPanel);
    addAndMakeVisible(buttonsPanelLeft);
    addAndMakeVisible(colourPanel);
    addAndMakeVisible(sliderPanels);

    setSize(1280, 720);
}

MainComponent::~MainComponent()
{
    delete canvas;
    delete buttonsPanelLeft;
    delete buttonsPanel;
    delete colourPanel;
    delete sliderPanels;
}

void MainComponent::resized(void)
{
    int width = getWidth();
    int height = getHeight();

    buttonsPanel->setBounds(0, 0, width, 70);
    buttonsPanelLeft->setBounds(0, 0, 80, height);
    sliderPanels->setBounds(398, 0, 300, 70);

    canvas->setBounds(80, 70, width - 80, height - 70);
    colourPanel->setBounds(706, 20, 96, 32);
}