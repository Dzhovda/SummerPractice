#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <stack>
/**
 * @class Canvas
 * @brief Класс холста для рисования.
 *
 * Класс Canvas является центральным компонентом графического редактора.
 * Он отвечает за хранение всех нарисованных фигур, обработку событий мыши,
 * отрисовку содержимого, управление параметрами рисования (цвет, толщина,
 * прозрачность), а также за сохранение и загрузку PNG-изображений.
 *
 * Основные функции:
 * - Хранение фигур в векторе lines
 * - Обработка событий мыши (mouseDown, mouseDrag, mouseUp)
 * - Отрисовка фигур через метод paint()
 * - Управление параметрами рисования (цвет, толщина, прозрачность)
 * - Сохранение и загрузка PNG-изображений
 * - Очистка холста
 *
 * @see Line, ButtonsPanel, ColourPanel
 */
class Canvas : public Component
{
public:
    /**
     * @brief Конструктор холста.
     */
    Canvas(void);

    /**
     * @brief Деструктор холста.
     */
    ~Canvas(void) override;

    /**
     * @brief Отрисовывает всё содержимое холста.
     *
     * Рисует фон (если есть backgroundImage), все сохранённые фигуры
     * из вектора lines, а также временную фигуру во время процесса
     * рисования (если isDragging == true).
     *
     * Для разных типов фигур используются разные методы отрисовки:
     * - line – drawLine
     * - rect – drawRect (с нормализацией координат)
     * - ellipse – drawEllipse (с нормализацией координат)
     * - triangle, romb, trapezoid, parallelogram – Path (addTriangle/addQuadrilateral)
     * - brush – цикл по точкам с drawRect
     *
     * @param g Объект Graphics для рисования.
     */
    void paint(Graphics&) override;

    /**
     * @brief Обработчик нажатия кнопки мыши на холсте.
     *
     * В зависимости от текущего инструмента (кисть, ластик или геометрическая фигура)
     * запоминает начальную точку рисования, текущие параметры (цвет, толщину, прозрачность)
     * и устанавливает флаг isDragging = true.
     *
     * Для кисти и ластика очищается вектор точек и добавляется первая точка.
     * Для геометрических фигур запоминается начальная точка, конечная точка обнуляется.
     *
     * @param e Объект события мыши, содержащий координаты и состояние кнопок.
     * @see mouseDrag, mouseUp
     */
    void mouseDown(const MouseEvent&) override;

    /**
     * @brief Обработчик движения мыши с зажатой кнопкой.
     *
     * Для кисти и ластика добавляет текущую позицию мыши в вектор точек.
     * Для геометрических фигур обновляет конечную точку.
     * После каждого обновления вызывает repaint() для отображения временной фигуры.
     *
     * @param e Объект события мыши.
     * @see mouseDown, mouseUp
     */
    void mouseDrag(const MouseEvent&) override;

    /**
     * @brief Обработчик отпускания кнопки мыши.
     *
     * Фиксирует конечную точку, добавляет текущую фигуру в вектор lines,
     * сбрасывает флаг isDragging и вызывает repaint() для окончательной отрисовки.
     *
     * @param e Объект события мыши.
     * @see mouseDown, mouseDrag
     */
    void mouseUp(const MouseEvent&) override;

    /**
     * @struct Line
     * @brief Структура, описывающая одну нарисованную фигуру.
     *
     * Хранит все параметры фигуры, необходимые для её отрисовки:
     * координаты начальной и конечной точек (для геометрических фигур),
     * цвет, толщину, прозрачность, тип фигуры и массив точек (для кисти/ластика).
     */
    struct Line
    {
        Point<int> start;        ///< Начальная точка фигуры
        Point<int> end;          ///< Конечная точка фигуры
        Colour colour;           ///< Цвет фигуры
        int thickness;           ///< Толщина линии
        /**
         * @brief Перечисление типов фигур.
         */
        enum Figures { brush, eraser, fillFigure, line, rect, triangle, romb, trapezoid, parallelogram, ellipse, polygon };
        Figures figures;         ///< Тип фигуры
        float opacity = 1.0f;    ///< Прозрачность (0.0 – 1.0)
        bool fill = false;       ///< Флаг заливки (true – заливать, false – только контур)
        std::vector<Point<int>> points; ///< Вектор точек для кисти/ластика
    };

    // ===== Управление инструментами =====

    /**
     * @brief Устанавливает текущий тип фигуры.
     * @param figures Тип фигуры из перечисления Line::Figures.
     */
    void SetFigures(Line::Figures figures) {
        currentLine.figures = figures;
    }

    /**
     * @brief Устанавливает режим заливки.
     * @param fill true – фигуры будут заливаться цветом, false – только контур.
     */
    void SetFill(bool fill) {
        currentLine.fill = fill;
    }

    /**
     * @brief Возвращает текущий режим заливки.
     * @return bool true – заливка включена, false – только контур.
     */
    bool GetFill() {
        return currentLine.fill;
    }

    // ===== Управление цветом =====

    /**
     * @brief Устанавливает текущий цвет рисования.
     * @param colour Новый цвет.
     */
    void setCurrentColour(Colour colour) {
        currentLine.colour = colour;
    }

    // ===== Управление параметрами =====

    /**
     * @brief Устанавливает толщину линии.
     * @param thickness Толщина в пикселях (1–15).
     */
    void setCurrentThickness(int thickness) {
        this->thickness = thickness;
    }

    /**
     * @brief Устанавливает прозрачность.
     * @param opacity Значение от 0.0 до 1.0.
     */
    void setCurrentOpacity(int opacity) {
        this->opacity = opacity;
    }

    /**
     * @brief Возвращает текущую толщину.
     * @return int Толщина линии.
     */
    int getThickness() {
        return this->thickness;
    }

    /**
     * @brief Возвращает текущую прозрачность.
     * @return int Прозрачность (0.0 – 1.0).
     */
    int getOpacity() {
        return this->opacity;
    }
    // ===== Работа с холстом =====

    /**
     * @brief Удаляет все фигуры с холста.
     *
     * Очищает вектор lines, сбрасывает временную линию,
     * удаляет фоновое изображение и перерисовывает холст.
     * Используется для кнопки "Delete All" или "New".
     */
    void DeleteLines() {
        lines.clear();
        currentLine = Line();
        isDragging = false;
        backgroundImage = juce::Image();
        repaint();
    }
    void Canvas::CancelStep()
    {
        if (undoStack.empty()) return;

        // Сохраняем текущее состояние в redoStack
        redoStack.push(backgroundImage.createCopy());

        // Восстанавливаем предыдущее состояние
        backgroundImage = undoStack.top();
        undoStack.pop();

        // Если изображение невалидно, заменим его на пустое (фон)
        if (!backgroundImage.isValid())
        {
            backgroundImage = juce::Image(juce::Image::ARGB, getWidth(), getHeight(), true);
            Graphics g(backgroundImage);
            g.fillAll(backgroundColor);
        }

        repaint();
    }
    void ReturnStep()
    {
        if (redoStack.empty()) return;

        // 1. Сохраняем текущее состояние в undoStack
        undoStack.push(backgroundImage.createCopy());

        // 2. Восстанавливаем состояние из redoStack
        backgroundImage = redoStack.top();
        redoStack.pop();

        repaint();
    }

    // ===== Файловые операции =====

    /**
     * @brief Сохраняет текущее содержимое холста в PNG-файл.
     *
     * Открывает диалог выбора файла через FileChooser, создаёт изображение
     * размером с холст, переносит на него все нарисованные фигуры,
     * а затем сохраняет в формате PNG.
     *
     * При возникновении ошибки (например, недоступность папки для записи)
     * выводится соответствующее предупреждение через AlertWindow.
     *
     * @note Используется асинхронный диалог FileChooser (launchAsync),
     *       что предотвращает блокировку интерфейса.
     * @see loadPNGFromFile
     */
    void saveCanvasToPNG();

    /**
     * @brief Загружает PNG-изображение и устанавливает его как фон холста.
     *
     * Открывает диалог выбора файла через FileChooser, загружает
     * выбранное PNG-изображение и сохраняет его в поле backgroundImage.
     *
     * Алгоритм работы:
     * 1. Открывает диалог выбора файла с фильтром *.png
     * 2. Загружает изображение через PNGImageFormat::loadFrom()
     * 3. Проверяет корректность загрузки
     * 4. Очищает вектор lines и сбрасывает временную линию
     * 5. Сохраняет изображение в backgroundImage
     * 6. Вызывает repaint() для обновления холста
     *
     * При возникновении ошибки (файл не найден или не является PNG)
     * выводится предупреждение через AlertWindow.
     *
     * @note Загруженное изображение становится фоном, поверх которого
     *       можно рисовать новые фигуры.
     * @see saveCanvasToPNG
     */
    void loadPNGFromFile();
    Image prepareImage();

private:
    std::vector<Line> lines;          ///< Вектор всех сохранённых фигур
    bool isDragging;                  ///< Флаг, указывающий на процесс рисования
    Line currentLine;                 ///< Временная фигура (для обратной связи)
    int thickness = 1;               ///< Текущая толщина линии
    float opacity = 1.0f;            ///< Текущая прозрачность
    juce::Colour backgroundColor = Colour(200, 200, 200); ///< Цвет фона холста
    juce::Image backgroundImage;     ///< Фоновое изображение (загруженное PNG)
    juce::Image image;
    std::unique_ptr<juce::FileChooser> currentChooser;

    std::stack<juce::Image> undoStack; // для Cancel
    std::stack<juce::Image> redoStack; // для Return
};