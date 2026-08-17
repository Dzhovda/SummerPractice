#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;

/**
 * @class MenuModel
 * @brief Модель строки меню приложения.
 *
 * Класс MenuModel реализует выпадающее меню «Файл» для графического редактора.
 * Наследует juce::MenuBarModel и предоставляет пункты меню:
 * - New – очистка холста
 * - Open – загрузка PNG-изображения
 * - Save – сохранение холста в PNG
 * - Save As – сохранение с выбором имени
 * - Export – экспорт в PNG
 * - Exit – завершение приложения
 *
 * Все пункты меню при выборе вызывают соответствующие методы объекта Canvas.
 * Модель подключается к главному окну через метод setMenuBar().
 *
 * @see Canvas, juce::MenuBarModel
 */
class MenuModel : public juce::MenuBarModel
{
public:
    /**
     * @brief Конструктор модели меню.
     * @param owner Указатель на объект Canvas, которому будут передаваться
     *              команды при выборе пунктов меню. Должен существовать
     *              всё время жизни модели.
     */
    MenuModel(Canvas* owner);

    /**
     * @brief Деструктор модели меню.
     *
     * Освобождает ресурсы. Указатель owner не удаляется, так как
     * холст управляется родительским компонентом.
     */
    ~MenuModel() override;

    /**
     * @brief Детектор утечек JUCE.
     */
    JUCE_LEAK_DETECTOR(MenuModel)

        /**
         * @brief Возвращает список имён меню верхнего уровня.
         *
         * Переопределяет метод juce::MenuBarModel::getMenuBarNames().
         * Возвращает массив строк: "File", "Edit", "Help".
         *
         * @return juce::StringArray Список имён меню.
         */
        juce::StringArray getMenuBarNames() override;

    /**
     * @brief Создаёт выпадающее меню для указанного пункта.
     *
     * Переопределяет метод juce::MenuBarModel::getMenuForIndex().
     * Для индекса 0 (меню "File") создаёт PopupMenu с пунктами:
     * New, Open, Save, Save As, Export, Exit.
     * Для остальных индексов возвращает пустое меню.
     *
     * @param topLevelMenuIndex Индекс меню (0 – File, 1 – Edit, 2 – Help).
     * @param menuName          Имя меню (для отладки).
     * @return juce::PopupMenu  Объект выпадающего меню.
     */
    juce::PopupMenu getMenuForIndex(int topLevelMenuIndex, const juce::String& menuName) override;

    /**
     * @brief Обработчик выбора пункта меню.
     *
     * Переопределяет метод juce::MenuBarModel::menuItemSelected().
     * По идентификатору пункта (menuItemID) выполняет соответствующее действие:
     * - File_New    -> owner->clearCanvas() / DeleteLines()
     * - File_Open   -> owner->loadPNGFromFile()
     * - File_Save   -> owner->saveCanvasToPNG()
     * - File_SaveAs -> owner->saveCanvasToPNG()
     * - File_Export -> owner->saveCanvasToPNG()
     * - File_Exit   -> JUCEApplication::getInstance()->systemRequestedQuit()
     *
     * @param menuItemID        Идентификатор выбранного пункта меню.
     * @param topLevelMenuIndex Индекс меню верхнего уровня.
     */
    void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;

private:
    Canvas* owner = nullptr; ///< Указатель на холст для выполнения команд.

    /**
     * @brief Идентификаторы пунктов меню.
     *
     * Используются для идентификации выбранного пункта в методе
     * menuItemSelected(). Каждому пункту соответствует уникальное число.
     */
    enum FileMenuIDs { File_New = 1, File_Open, File_Save, File_SaveAs, File_Export, File_Exit };
};