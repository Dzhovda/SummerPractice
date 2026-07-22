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

    
    auto* mainComp = new MainComponent();
    setContentOwned(mainComp, true);

    // —оздаЄм модель меню, использу€ холст из mainComp
    menuModel = std::make_unique<MenuModel>(mainComp->getCanvas());
    setMenuBar(menuModel.get());

    setVisible(true);  
}
MainFrame::~MainFrame()
{
    setMenuBar(nullptr);    // отключаем меню, оно будет удалено
    // затем автоматически удалитс€ содержимое (setContentOwned)
}