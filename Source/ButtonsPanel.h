#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;

/**
 * @class ButtonsPanel
 * @brief Верхняя панель с кнопками выбора геометрических фигур и дополнительными действиями.
 *
 * Содержит кнопки для выбора типов фигур (линия, прямоугольник, эллипс, треугольник,
 * ромб, трапеция, параллелограмм, многоугольник), а также кнопки Copy, Paste, Grid,
 * Layers, ZoomIn, ZoomOut. Все кнопки реализованы как DrawableButton с иконками.
 * При нажатии передаёт команды в холст (Canvas).
 *
 * @see Canvas, DrawableButton, Button::Listener
 */
class ButtonsPanel : public Component, public DrawableButton::Listener
{
public:
    /**
     * @brief Конструктор панели кнопок.
     * @param owner Указатель на объект Canvas, которому будут передаваться команды.
     *              Должен существовать всё время жизни панели.
     */
    ButtonsPanel(Canvas* owner);

    /**
     * @brief Деструктор. Отписывает слушателей от кнопок.
     */
    ~ButtonsPanel(void) override;

    /**
     * @brief Детектор утечек JUCE.
     */
    JUCE_LEAK_DETECTOR(ButtonsPanel)

        /**
         * @brief Отрисовывает фон панели.
         * @param g Объект Graphics для рисования.
         */
        void paint(Graphics&) override;

    /**
     * @brief Позиционирует все кнопки внутри панели.
     * Задаёт координаты и размеры каждой кнопки (обычно 25x25 пикселей).
     */
    void resized(void) override;

    /**
     * @brief Обработчик нажатия на кнопку.
     *
     * Определяет, какая кнопка была нажата, и вызывает соответствующий
     * метод холста: SetFigures() для фигур или другие методы для
     * дополнительных действий (например, toggleGrid, copy, paste и т.д.).
     *
     * @param button Указатель на нажатую кнопку.
     */
    void buttonClicked(Button*) override;

private:
    Canvas* owner = nullptr; ///< Указатель на холст для передачи команд.

    // ===== Кнопки геометрических фигур =====

    DrawableButton FLineButton1;        ///< Кнопка "Линия"
    DrawableButton FRectButton2;        ///< Кнопка "Прямоугольник"
    DrawableButton FTriangleButton3;    ///< Кнопка "Треугольник"
    DrawableButton FRombButton4;        ///< Кнопка "Ромб"
    DrawableButton FTrapezoidButton5;   ///< Кнопка "Трапеция"
    DrawableButton FParallelogramButton6; ///< Кнопка "Параллелограмм"
    DrawableButton FEllipseButton7;     ///< Кнопка "Эллипс"
    DrawableButton FPolygonButton8;     ///< Кнопка "Многоугольник"

    // ===== Дополнительные кнопки =====

    DrawableButton FButtonCopy;         ///< Кнопка "Копировать"
    DrawableButton FButtonPaste;        ///< Кнопка "Вставить"
    DrawableButton FButtonGrid;         ///< Кнопка "Сетка" (переключаемая)
    DrawableButton FButtonLayers;       ///< Кнопка "Слои" (открывает панель слоёв)
    DrawableButton FButtonZoomIn;       ///< Кнопка "Увеличить"
    DrawableButton FButtonZoomOut;      ///< Кнопка "Уменьшить"
};