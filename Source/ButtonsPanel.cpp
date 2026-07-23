#include "ButtonsPanel.h"
#include "Canvas.h"

/**
 * @brief Конструктор панели верхних кнопок.
 *
 * Инициализирует все кнопки, задаёт их стиль (ImageAboveTextLabel),
 * добавляет их в иерархию, загружает иконки из папки Resources
 * и подписывает себя как слушателя нажатий.
 *
 * @param owner Указатель на объект Canvas, которому будут передаваться команды.
 *              Должен существовать всё время жизни панели.
 */
ButtonsPanel::ButtonsPanel(Canvas* owner) :
    owner(owner),
    FLineButton1("Line", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FRectButton2("Rect", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FTriangleButton3("Triangle", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FRombButton4("Romb", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FTrapezoidButton5("Trapezoid", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FParallelogramButton6("Parallelogram", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FEllipseButton7("Ellipse", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FPolygonButton8("Polygon", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonCopy("Copy", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonPaste("Paste", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonGrid("Grid", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonLayers("Layers", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonZoomIn("ZoomIn", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FButtonZoomOut("ZoomOut", DrawableButton::ButtonStyle::ImageAboveTextLabel)
{
    Component::setOpaque(true);

    // Добавляем кнопки как видимые дочерние компоненты
    Component::addAndMakeVisible(FLineButton1);
    Component::addAndMakeVisible(FRectButton2);
    Component::addAndMakeVisible(FTriangleButton3);
    Component::addAndMakeVisible(FRombButton4);
    Component::addAndMakeVisible(FTrapezoidButton5);
    Component::addAndMakeVisible(FParallelogramButton6);
    Component::addAndMakeVisible(FEllipseButton7);
    Component::addAndMakeVisible(FPolygonButton8);
    Component::addAndMakeVisible(FButtonCopy);
    Component::addAndMakeVisible(FButtonPaste);
    Component::addAndMakeVisible(FButtonGrid);
    Component::addAndMakeVisible(FButtonLayers);
    Component::addAndMakeVisible(FButtonZoomIn);
    Component::addAndMakeVisible(FButtonZoomOut);

    // Загрузка иконок (путь относительно рабочей директории)
    auto appDir = juce::File::getCurrentWorkingDirectory().getParentDirectory().getParentDirectory();

    // ===== Инициализация иконок геометрических фигур =====
    // Line
    auto iconLineNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LineNormal.png"));
    auto iconLineDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LineDown.png"));
    auto iconLineOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LineOver.png"));
    FLineButton1.setImages(iconLineNormal.get(), iconLineOver.get(), iconLineDown.get());

    // Rect
    auto iconRectNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RectNormal.png"));
    auto iconRectDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RectDown.png"));
    auto iconRectOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RectOver.png"));
    FRectButton2.setImages(iconRectNormal.get(), iconRectOver.get(), iconRectDown.get());

    // Triangle
    auto iconTriangleNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TriangleNormal.png"));
    auto iconTriangleDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TriangleDown.png"));
    auto iconTriangleOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TriangleOver.png"));
    FTriangleButton3.setImages(iconTriangleNormal.get(), iconTriangleOver.get(), iconTriangleDown.get());

    // Romb
    auto iconRombNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RombNormal.png"));
    auto iconRombDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RombDown.png"));
    auto iconRombOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/RombOver.png"));
    FRombButton4.setImages(iconRombNormal.get(), iconRombOver.get(), iconRombDown.get());

    // Trapezoid
    auto iconTrapNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TrapNormal.png"));
    auto iconTrapDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TrapDown.png"));
    auto iconTrapOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TrapOver.png"));
    FTrapezoidButton5.setImages(iconTrapNormal.get(), iconTrapOver.get(), iconTrapDown.get());

    // Parallelogram
    auto iconParallelNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ParallelNormal.png"));
    auto iconParallelDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ParallelDown.png"));
    auto iconParallelOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ParallelOver.png"));
    FParallelogramButton6.setImages(iconParallelNormal.get(), iconParallelOver.get(), iconParallelDown.get());

    // Ellipse
    auto iconEllipseNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EllipseNormal.png"));
    auto iconEllipseDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EllipseDown.png"));
    auto iconEllipseOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EllipseOver.png"));
    FEllipseButton7.setImages(iconEllipseNormal.get(), iconEllipseOver.get(), iconEllipseDown.get());

    // Polygon (с отдельной иконкой для включённого состояния)
    auto iconPolygonNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PollygonNormal.png"));
    auto iconPolygonDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PollygonDown.png"));
    auto iconPolygonOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PollygonOver.png"));
    auto iconPolygonEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PollygonEnable.png"));
    FPolygonButton8.setImages(iconPolygonNormal.get(), iconPolygonOver.get(), iconPolygonDown.get(), iconPolygonEnable.get());

    // ===== Дополнительные кнопки =====
    // Copy
    auto iconCopyNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CopyNormal.png"));
    auto iconCopyDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CopyDown.png"));
    auto iconCopyOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CopyOver.png"));
    auto iconCopyEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CopyEnable.png"));
    FButtonCopy.setImages(iconCopyNormal.get(), iconCopyOver.get(), iconCopyDown.get(), iconCopyEnable.get());

    // Paste
    auto iconPasteNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PasteNormal.png"));
    auto iconPasteDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PasteDown.png"));
    auto iconPasteOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PasteOver.png"));
    auto iconPasteEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PasteEnable.png"));
    FButtonPaste.setImages(iconPasteNormal.get(), iconPasteOver.get(), iconPasteDown.get(), iconPasteEnable.get());

    // Grid
    auto iconGridNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/GridNormal.png"));
    auto iconGridDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/GridDown.png"));
    auto iconGridOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/GridOver.png"));
    auto iconGridEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/GridEnable.png"));
    FButtonGrid.setImages(iconGridNormal.get(), iconGridOver.get(), iconGridDown.get(), iconGridEnable.get());

    // Layers
    auto iconLayersNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LayersNormal.png"));
    auto iconLayersDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LayersDown.png"));
    auto iconLayersOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LayersOver.png"));
    auto iconLayersEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/LayersEnable.png"));
    FButtonLayers.setImages(iconLayersNormal.get(), iconLayersOver.get(), iconLayersDown.get(), iconLayersEnable.get());

    // ZoomIn
    auto iconZoomInNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomInNormal.png"));
    auto iconZoomInDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomInDown.png"));
    auto iconZoomInOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomInOver.png"));
    auto iconZoomInEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomInEnable.png"));
    FButtonZoomIn.setImages(iconZoomInNormal.get(), iconZoomInOver.get(), iconZoomInDown.get(), iconZoomInEnable.get());

    // ZoomOut
    auto iconZoomOutNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomOutNormal.png"));
    auto iconZoomOutDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomOutDown.png"));
    auto iconZoomOutOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomOutOver.png"));
    auto iconZoomOutEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ZoomOutEnable.png"));
    FButtonZoomOut.setImages(iconZoomOutNormal.get(), iconZoomOutOver.get(), iconZoomOutDown.get(), iconZoomOutEnable.get());

    // Подписка на события кнопок
    FLineButton1.addListener(this);
    FRectButton2.addListener(this);
    FTriangleButton3.addListener(this);
    FRombButton4.addListener(this);
    FTrapezoidButton5.addListener(this);
    FParallelogramButton6.addListener(this);
    FEllipseButton7.addListener(this);
    FPolygonButton8.addListener(this);
    FButtonCopy.addListener(this);
    FButtonPaste.addListener(this);
    FButtonGrid.addListener(this);
    FButtonLayers.addListener(this);
    FButtonZoomIn.addListener(this);
    FButtonZoomOut.addListener(this);
}

/**
 * @brief Деструктор панели верхних кнопок.
 *
 * Отписывает слушателей от всех кнопок, чтобы избежать
 * утечек памяти и обращений к разрушенному объекту.
 */
ButtonsPanel::~ButtonsPanel()
{
    FLineButton1.removeListener(this);
    FRectButton2.removeListener(this);
    FTriangleButton3.removeListener(this);
    FRombButton4.removeListener(this);
    FTrapezoidButton5.removeListener(this);
    FParallelogramButton6.removeListener(this);
    FEllipseButton7.removeListener(this);
    FPolygonButton8.removeListener(this);
    FButtonCopy.removeListener(this);
    FButtonPaste.removeListener(this);
    FButtonGrid.removeListener(this);
    FButtonLayers.removeListener(this);
    FButtonZoomIn.removeListener(this);
    FButtonZoomOut.removeListener(this);
}

/**
 * @brief Обработчик нажатия на кнопку.
 *
 * Определяет, какая кнопка была нажата, и вызывает соответствующий
 * метод холста (owner->SetFigures()) для изменения текущего типа фигуры.
 * Для дополнительных кнопок (Copy, Paste и др.) пока вызовы не реализованы.
 *
 * @param button Указатель на нажатую кнопку.
 */
void ButtonsPanel::buttonClicked(Button* button) {
    Canvas::Line line;
    if (button == &FLineButton1) {
        owner->SetFigures(Canvas::Line::Figures::line);
    }
    if (button == &FRectButton2) {
        owner->SetFigures(Canvas::Line::Figures::rect);
    }
    if (button == &FTriangleButton3) {
        owner->SetFigures(Canvas::Line::Figures::triangle);
    }
    if (button == &FRombButton4) {
        owner->SetFigures(Canvas::Line::Figures::romb);
    }
    if (button == &FTrapezoidButton5) {
        owner->SetFigures(Canvas::Line::Figures::trapezoid);
    }
    if (button == &FParallelogramButton6) {
        owner->SetFigures(Canvas::Line::Figures::parallelogram);
    }
    if (button == &FEllipseButton7) {
        owner->SetFigures(Canvas::Line::Figures::ellipse);
    }
    if (button == &FPolygonButton8) {
        owner->SetFigures(Canvas::Line::Figures::polygon);
    }
    // Дополнительные кнопки (Copy, Paste, Grid, Layers, ZoomIn, ZoomOut)
    // пока не реализованы – только заглушки.
}

/**
 * @brief Отрисовывает фон панели и текстовые подписи.
 *
 * Заливает фон цветом (RGB: 191, 90, 90), рисует вертикальные
 * разделители между группами кнопок и выводит подписи "Цвет" и "Геометрия".
 *
 * @param g Объект Graphics для рисования.
 */
void ButtonsPanel::paint(Graphics& g)
{
    g.fillAll(juce::Colour(191, 90, 90));
    g.setColour(Colour(217, 217, 217));
    // Рисование разделителей
    g.fillRect(80, 0, 13, 70);
    g.fillRect(374, 0, 13, 70);
    g.fillRect(529, 0, 13, 70);
    g.fillRect(684, 0, 13, 70);
    g.fillRect(811, 0, 13, 70);
    g.fillRect(901, 0, 13, 70);
    g.fillRect(1117, 0, 13, 70);
    g.fillRect(1198, 0, 13, 70);

    // Подписи
    g.setColour(juce::Colours::black);
    g.setFont(juce::Font(16.0f, juce::Font::bold));
    auto bounds = getLocalBounds();
    float centerX = 20.0f;
    float centerY = bounds.getHeight() / 3.0f;

    juce::String text = juce::String::fromUTF8(u8"Цвет");
    juce::Rectangle<float> textArea(centerX + 660, centerY - 20, 140, 20);
    g.drawText(text, textArea, juce::Justification::centred, true);

    juce::String text2 = juce::String::fromUTF8(u8"Геометрия");
    juce::Rectangle<float> textArea2(centerX + 125, centerY - 20, 140, 20);
    g.drawText(text2, textArea2, juce::Justification::centred, true);
}

/**
 * @brief Позиционирует все кнопки панели.
 *
 * Задаёт координаты и размеры для каждой кнопки (40x40 пикселей)
 * с фиксированными отступами. Также отключает неактивные в данный
 * момент кнопки (Polygon, Copy, Paste, Grid, Layers, ZoomIn, ZoomOut).
 */
void ButtonsPanel::resized(void)
{
    // Группа "Геометрия"
    FLineButton1.setBounds(91, 23, 40, 40);
    FRectButton2.setBounds(126, 23, 40, 40);
    FTriangleButton3.setBounds(161, 23, 40, 40);
    FRombButton4.setBounds(196, 23, 40, 40);
    FTrapezoidButton5.setBounds(231, 23, 40, 40);
    FParallelogramButton6.setBounds(266, 23, 40, 40);
    FEllipseButton7.setBounds(301, 23, 40, 40);
    FPolygonButton8.setBounds(336, 23, 40, 40);

    // Дополнительные кнопки
    FButtonCopy.setBounds(825, 23, 40, 40);
    FButtonPaste.setBounds(860, 23, 40, 40);
    FButtonGrid.setBounds(910, 23, 40, 40);
    FButtonLayers.setBounds(940, 23, 40, 40);
    FButtonZoomIn.setBounds(1130, 23, 40, 40);
    FButtonZoomOut.setBounds(1160, 23, 40, 40);

    // Временно отключаем нереализованные функции
    FPolygonButton8.setEnabled(false);
    FButtonCopy.setEnabled(false);
    FButtonPaste.setEnabled(false);
    FButtonGrid.setEnabled(false);
    FButtonLayers.setEnabled(false);
    FButtonZoomIn.setEnabled(false);
    FButtonZoomOut.setEnabled(false);
}