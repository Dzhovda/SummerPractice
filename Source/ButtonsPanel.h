#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;
class ButtonsPanel: public Component, public DrawableButton::Listener
{
public:
    ButtonsPanel(Canvas* owner);
	~ButtonsPanel(void) override;

    void paint(Graphics&) override;
    void resized(void) override;
    void buttonClicked(Button*) override;

private:
    Canvas* owner = nullptr;
    // кнопки верхней панели
    DrawableButton FLineButton1;
    DrawableButton FRectButton2;
    DrawableButton FTriangleButton3;
    DrawableButton FRombButton4;
    DrawableButton FTrapezoidButton5;
    DrawableButton FParallelogramButton6;
    DrawableButton FEllipseButton7;
    DrawableButton FPolygonButton8;

    // кнопки Copy-Paste, Grid, Layers, Zoom in, Zoom out
    DrawableButton FButtonCopy;
    DrawableButton FButtonPaste;
    DrawableButton FButtonGrid;
    DrawableButton FButtonLayers;
    DrawableButton FButtonZoomIn;
    DrawableButton FButtonZoomOut;
};

