#include "MenuModel.h"
#include "Canvas.h"

MenuModel::MenuModel(Canvas* owner)
    : owner(owner)
{

}

MenuModel::~MenuModel()
{
}

juce::StringArray MenuModel::getMenuBarNames()
{
    return { "File", "Edit", "Help" };
}

juce::PopupMenu MenuModel::getMenuForIndex(int topLevelMenuIndex, const juce::String& menuName)
{
    juce::PopupMenu menu;

    if (topLevelMenuIndex == 0) // File
    {
        menu.addItem(File_New, "New");
        menu.addItem(File_Open, "Open...");
        menu.addItem(File_Save, "Save");
        menu.addItem(File_SaveAs, "Save As...");
        menu.addSeparator();
        menu.addItem(File_Export, "Export...");
        menu.addSeparator();
        menu.addItem(File_Exit, "Exit");
    }
    else if (topLevelMenuIndex == 1) // Edit
    {
        // можно добавить пункты позже
    }
    else if (topLevelMenuIndex == 2) // Help
    {
        // можно добавить позже
    }

    return menu;
}

void MenuModel::menuItemSelected(int menuItemID, int topLevelMenuIndex)
{
    switch (menuItemID)
    {
    case File_New:
        owner->DeleteLines();
        break;
    case File_Open:
        owner->loadPNGFromFile();
        break;
    case File_Save:
        owner->saveCanvasToPNG();
        break;
    case File_SaveAs:
        owner->saveCanvasToPNG(); // или отдельный метод
        break;
    case File_Export:
        owner->saveCanvasToPNG(); // или отдельный метод для экспорта
        break;
    case File_Exit:
        JUCEApplication::getInstance()->systemRequestedQuit();
        break;
    default:
        break;
    }
}