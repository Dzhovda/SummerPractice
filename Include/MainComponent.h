#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ButtonsPanel.h"
#include "Canvas.h"
#include "ButtonsPanelLeft.h"
#include "ColourPanel.h"
#include "SliderPanels.h"
#include "MenuModel.h"

/**
 * @class MainComponent
 * @brief Корневой компонент-контейнер приложения.
 *
 * Класс MainComponent является главным контейнером, который объединяет
 * все основные компоненты графического редактора:
 * - Холст (Canvas) для рисования
 * - Верхнюю панель с фигурами (ButtonsPanel)
 * - Левую панель с инструментами (ButtonsPanelLeft)
 * - Цветовой слайдер (ColourPanel)
 * - Панель слайдеров толщины и прозрачности (SliderPanels)
 *
 * Основные функции:
 * - Создание всех дочерних компонентов в конструкторе
 * - Добавление их в иерархию через addAndMakeVisible()
 * - Позиционирование всех компонентов в методе resized()
 * - Предоставление доступа к холсту через getCanvas()
 *
 * @see Canvas, ButtonsPanel, ButtonsPanelLeft, ColourPanel, SliderPanels, MenuModel
 */
class MainComponent : public Component
{
public:
    /**
     * @brief Конструктор главного компонента.
     *
     * Создаёт все дочерние компоненты: холст, панели, слайдеры.
     * Добавляет их в иерархию через addAndMakeVisible().
     * Передаёт указатель на холст всем панелям через конструкторы.
     */
    MainComponent(void);

    /**
     * @brief Деструктор главного компонента.
     *
     * Освобождает ресурсы. Все дочерние компоненты удаляются
     * автоматически, так как они добавлены через addAndMakeVisible().
     */
    ~MainComponent(void) override;

    // Закомментированный макрос детектора утечек (не используется)
    // JUCE_LEAK_DETECTOR(MainComponent)

    /**
     * @brief Позиционирует все дочерние компоненты.
     *
     * Вызывается при создании компонента и при каждом изменении
     * размеров окна. Задаёт координаты и размеры для:
     * - Верхней панели (buttonsPanel) – вся ширина, высота 70px
     * - Левой панели (buttonsPanelLeft) – ширина 80px, вся высота
     * - Панели слайдеров (sliderPanels) – внутри верхней панели
     * - Цветового слайдера (colourPanel) – внутри верхней панели
     * - Холста (canvas) – оставшееся пространство
     *
     * @note Метод использует getWidth() и getHeight() для вычисления
     *       динамических размеров, что обеспечивает адаптивность.
     */
    void resized(void) override;

    /**
     * @brief Возвращает указатель на объект холста.
     *
     * Используется для передачи холста в меню (MenuModel) и другие
     * компоненты, которым требуется доступ к его методам.
     *
     * @return Canvas* Указатель на объект Canvas.
     */
    Canvas* getCanvas() const { return canvas; }

private:
    Canvas* canvas;                     ///< Указатель на объект холста
    ButtonsPanel* buttonsPanel;         ///< Указатель на верхнюю панель
    ButtonsPanelLeft* buttonsPanelLeft; ///< Указатель на левую панель
    ColourPanel* colourPanel;           ///< Указатель на цветовой слайдер
    SliderPanels* sliderPanels;         ///< Указатель на панель слайдеров
    MenuModel* menuModel;               ///< Указатель на модель меню

    /**
     * @brief Макрос детектора утечек JUCE.
     *
     * Обеспечивает отслеживание утечек памяти для класса MainComponent
     * в отладочных сборках и запрещает копирование объектов.
     */
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};