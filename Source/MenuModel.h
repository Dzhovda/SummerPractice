#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;
class MenuModel : public juce::MenuBarModel
{
public:
    MenuModel(Canvas* owner);
    ~MenuModel() override;

    // Переопределяем методы MenuBarModel
    juce::StringArray getMenuBarNames() override;
    juce::PopupMenu getMenuForIndex(int topLevelMenuIndex, const juce::String& menuName) override;
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;

private:
    Canvas* owner = nullptr;
    // ID пунктов меню
    enum FileMenuIDs { File_New = 1, File_Open, File_Save, File_SaveAs, File_Export, File_Exit };
};