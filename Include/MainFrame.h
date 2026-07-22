#pragma once
//
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Include/MainComponent.h"
//
class MainFrame : public DocumentWindow
{
public:
   //
   MainFrame(const String& name);
   //
   void closeButtonPressed() override
   {
       JUCEApplication::getInstance()->systemRequestedQuit();
   }
   //
   MainComponent& getMainComponent(void) { return *dynamic_cast<MainComponent*> (getContentComponent()); }
   //
private:
    std::unique_ptr<MenuModel> menuModel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainFrame)
};