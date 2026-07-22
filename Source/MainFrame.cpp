#include "../JuceLibraryCode/JuceHeader.h"
#include "../Include/MainFrame.h"
#include "../Include/Application.h"
MainFrame::MainFrame(const String& name)
    : DocumentWindow(name, Desktop::getInstance().getDefaultLookAndFeel()
        .findColour(ResizableWindow::backgroundColourId),
        DocumentWindow::allButtons)
{
    setUsingNativeTitleBar(true);
    setResizable(true, false);
    setResizeLimits(400, 400, 10000, 10000);
    setSize(1280, 720);
    centreWithSize(1280, 720);

    setContentOwned(new MainComponent(), false);
    setVisible(true);

    MainComponent* mainComp = new MainComponent();
    setContentOwned(mainComp, true);

    // Создаём меню, передавая холст
    menuModel = std::make_unique<MenuModel>(mainComp->getCanvas());
    setMenuBar(menuModel.get());
}