#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;

/**
 * @class ButtonsPanelLeft
 * @brief Левая панель с инструментами рисования.
 *
 * Содержит кнопки для выбора инструментов: кисть, ластик, заливка,
 * пипетка, текст, режим заливки/контура, рука (перемещение).
 * Также содержит кнопки навигации: отмена (Cancel), возврат (Return),
 * сохранение (Save) и удаление всех фигур (DeleteAll).
 *
 * Все кнопки реализованы как DrawableButton с иконками.
 * При нажатии передаёт команды в холст (Canvas).
 *
 * @see Canvas, DrawableButton, Button::Listener
 */
class ButtonsPanelLeft : public Component, public DrawableButton::Listener
{
public:
    /**
     * @brief Конструктор левой панели инструментов.
     * @param owner Указатель на объект Canvas, которому будут передаваться команды.
     *              Должен существовать всё время жизни панели.
     */
    ButtonsPanelLeft(Canvas* owner);

    /**
     * @brief Деструктор. Отписывает слушателей от кнопок.
     */
    ~ButtonsPanelLeft();

    /**
     * @brief Детектор утечек JUCE.
     */
    JUCE_LEAK_DETECTOR(ButtonsPanelLeft)

        /**
         * @brief Отрисовывает фон панели и вертикальную подпись "Инструменты".
         * @param g Объект Graphics для рисования.
         */
        void paint(Graphics&) override;

    /**
     * @brief Позиционирует все кнопки внутри панели.
     *
     * Задаёт координаты и размеры каждой кнопки (обычно 25x25 пикселей)
     * с фиксированными отступами по вертикали.
     */
    void resized(void) override;

    /**
     * @brief Обработчик нажатия на кнопку.
     *
     * Определяет, какая кнопка была нажата, и вызывает соответствующий
     * метод холста: SetFigures() для выбора инструмента, SetFill() для
     * заливки, а также методы для отмены, возврата, сохранения и очистки.
     *
     * @param button Указатель на нажатую кнопку.
     */
    void buttonClicked(Button*) override;

private:
    Canvas* owner = nullptr; ///< Указатель на холст для передачи команд.

    // ===== Кнопки инструментов =====

    DrawableButton FBrush;        ///< Кнопка "Кисть"
    DrawableButton FEraser;       ///< Кнопка "Ластик"
    DrawableButton FFill;         ///< Кнопка "Заливка" (переключаемая)
    DrawableButton FPipette;      ///< Кнопка "Пипетка" (выбор цвета)
    DrawableButton FText;         ///< Кнопка "Текст"
    DrawableButton FFillOutline;  ///< Кнопка "Заливка/Контур" (переключаемая)
    DrawableButton FMove;         ///< Кнопка "Рука" (перемещение холста)

    /* Закомментированные кнопки (задел на будущее)
    DrawableButton FDottedLine;   ///< Кнопка "Пунктирная линия"
    DrawableButton FStreakLine;   ///< Кнопка "Штриховая линия"
    DrawableButton FMirrow;       ///< Кнопка "Зеркало"
    */

    // ===== Кнопки навигации =====

    DrawableButton FCancelButton;   ///< Кнопка "Отмена" (Undo)
    DrawableButton FReturnButton;   ///< Кнопка "Возврат" (Redo)
    DrawableButton FSaveButton;     ///< Кнопка "Сохранить" (Save)
    DrawableButton FDeleteAllButton; ///< Кнопка "Удалить всё" (Clear Canvas)

    /**
     * @brief Текстовая метка "Инструменты".
     *
     * Отображается вертикально (повёрнута на 90°) и служит подписью
     * для левой панели инструментов.
     */
    Label FInstrumentPanel;
};