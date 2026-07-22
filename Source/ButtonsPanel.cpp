#include "ButtonsPanel.h"
#include "Canvas.h"

ButtonsPanel::ButtonsPanel(Canvas* owner):
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

    // Определяем корневую папку приложения
    auto appDir = juce::File::getSpecialLocation(juce::File::currentExecutableFile).getParentDirectory();
    // Геометрические фигуры (верхняя панель)
    // Line
    auto iconLineNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LineNormal.png"));
    auto iconLineDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LineDown.png"));
    auto iconLineOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LineOver.png"));
    FLineButton1.setImages(iconLineNormal.get(), iconLineOver.get(), iconLineDown.get());

    // Rect
    auto iconRectNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RectNormal.png"));
    auto iconRectDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RectDown.png"));
    auto iconRectOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RectOver.png"));
    FRectButton2.setImages(iconRectNormal.get(), iconRectOver.get(), iconRectDown.get());

    // Triangle
    auto iconTriangleNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TriangleNormal.png"));
    auto iconTriangleDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TriangleDown.png"));
    auto iconTriangleOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TriangleOver.png"));
    FTriangleButton3.setImages(iconTriangleNormal.get(), iconTriangleOver.get(), iconTriangleDown.get());

    // Romb
    auto iconRombNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RombNormal.png"));
    auto iconRombDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RombDown.png"));
    auto iconRombOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/RombOver.png"));
    FRombButton4.setImages(iconRombNormal.get(), iconRombOver.get(), iconRombDown.get());

    // Trapezoid
    auto iconTrapNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TrapNormal.png"));
    auto iconTrapDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TrapDown.png"));
    auto iconTrapOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TrapOver.png"));
    FTrapezoidButton5.setImages(iconTrapNormal.get(), iconTrapOver.get(), iconTrapDown.get());

    // Parallelogram
    auto iconParallelNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ParallelNormal.png"));
    auto iconParallelDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ParallelDown.png"));
    auto iconParallelOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ParallelOver.png"));
    FParallelogramButton6.setImages(iconParallelNormal.get(), iconParallelOver.get(), iconParallelDown.get());

    // Ellipse
    auto iconEllipseNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EllipseNormal.png"));
    auto iconEllipseDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EllipseDown.png"));
    auto iconEllipseOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EllipseOver.png"));
    FEllipseButton7.setImages(iconEllipseNormal.get(), iconEllipseOver.get(), iconEllipseDown.get());

    // Polygon (с отдельной иконкой для включённого состояния)
    auto iconPolygonNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PollygonNormal.png"));
    auto iconPolygonDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PollygonDown.png"));
    auto iconPolygonOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PollygonOver.png"));
    auto iconPolygonEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PollygonEnable.png"));
    FPolygonButton8.setImages(iconPolygonNormal.get(), iconPolygonOver.get(), iconPolygonDown.get(), iconPolygonEnable.get());

    //Дополнительные кнопки

// Copy
    auto iconCopyNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CopyNormal.png"));
    auto iconCopyDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CopyDown.png"));
    auto iconCopyOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CopyOver.png"));
    auto iconCopyEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CopyEnable.png"));
    FButtonCopy.setImages(iconCopyNormal.get(), iconCopyOver.get(), iconCopyDown.get(), iconCopyEnable.get());

    // Paste
    auto iconPasteNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PasteNormal.png"));
    auto iconPasteDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PasteDown.png"));
    auto iconPasteOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PasteOver.png"));
    auto iconPasteEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PasteEnable.png"));
    FButtonPaste.setImages(iconPasteNormal.get(), iconPasteOver.get(), iconPasteDown.get(), iconPasteEnable.get());

    // Grid
    auto iconGridNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/GridNormal.png"));
    auto iconGridDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/GridDown.png"));
    auto iconGridOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/GridOver.png"));
    auto iconGridEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/GridEnable.png"));
    FButtonGrid.setImages(iconGridNormal.get(), iconGridOver.get(), iconGridDown.get(), iconGridEnable.get());

    // Layers
    auto iconLayersNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LayersNormal.png"));
    auto iconLayersDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LayersDown.png"));
    auto iconLayersOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LayersOver.png"));
    auto iconLayersEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/LayersEnable.png"));
    FButtonLayers.setImages(iconLayersNormal.get(), iconLayersOver.get(), iconLayersDown.get(), iconLayersEnable.get());

    // ZoomIn
    auto iconZoomInNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomInNormal.png"));
    auto iconZoomInDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomInDown.png"));
    auto iconZoomInOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomInOver.png"));
    auto iconZoomInEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomInEnable.png"));
    FButtonZoomIn.setImages(iconZoomInNormal.get(), iconZoomInOver.get(), iconZoomInDown.get(), iconZoomInEnable.get());

    // ZoomOut
    auto iconZoomOutNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomOutNormal.png"));
    auto iconZoomOutDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomOutDown.png"));
    auto iconZoomOutOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomOutOver.png"));
    auto iconZoomOutEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ZoomOutEnable.png"));
    FButtonZoomOut.setImages(iconZoomOutNormal.get(), iconZoomOutOver.get(), iconZoomOutDown.get(), iconZoomOutEnable.get());

    //блок слушателя кнопок режима геометрии
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
}
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
}
void ButtonsPanel::paint(Graphics & g)
{
    g.fillAll(juce::Colour(191, 90, 90));
    //g.fillRect(0, 0, 1280, 70);
    g.setColour(Colour(217,217,217));
    //верхняя панель
    //перемычки верхней панели
    g.fillRect(80, 0, 13, 70);
    g.fillRect(374, 0, 13, 70);
    g.fillRect(529, 0, 13, 70);
    g.fillRect(684, 0, 13, 70);
    g.fillRect(684, 0, 13, 70);
    g.fillRect(811, 0, 13, 70);
    g.fillRect(901, 0, 13, 70);
    g.fillRect(1117, 0, 13, 70);
    g.fillRect(1117, 0, 13, 70);
    g.fillRect(1198, 0, 13, 70);

    //текст 1) сохранить как 2) у кнопки сохранить нажать стрелку с кодировками 3) выбрать utf8
    g.setColour(juce::Colours::black);
    g.setFont(juce::Font(16.0f, juce::Font::bold));
    auto bounds = getLocalBounds();
    float centerX = 20.0f;   // Отступ слева
    float centerY = bounds.getHeight() / 3.0f;
    juce::String text = juce::String::fromUTF8(u8"Цвет");
    juce::Rectangle<float> textArea(centerX + 660, centerY - 20, 140, 20);
    g.drawText(text, textArea, juce::Justification::centred, true);
    juce::String text2 = juce::String::fromUTF8(u8"Геометрия");
    juce::Rectangle<float> textArea2(centerX + 125, centerY - 20, 140, 20);
    g.drawText(text2, textArea2, juce::Justification::centred, true);
}


void ButtonsPanel::resized(void)
{
    //Геометрия
    FLineButton1.setBounds(91, 23, 40, 40);  // - 30 по Y
    FRectButton2.setBounds(126, 23, 40, 40); // +35 по X для последующих кнопок по X
    FTriangleButton3.setBounds(161, 23, 40, 40);
    FRombButton4.setBounds(196, 23, 40, 40);
    FTrapezoidButton5.setBounds(231, 23, 40, 40);
    FParallelogramButton6.setBounds(266, 23, 40, 40);
    FEllipseButton7.setBounds(301, 23, 40, 40);
    FPolygonButton8.setBounds(336, 23, 40, 40);

    FButtonCopy.setBounds(825,23,40,40);
    FButtonPaste.setBounds(860,23,40,40);
    FButtonGrid.setBounds(910,23,40,40);
    FButtonLayers.setBounds(940,23,40,40);
    FButtonZoomIn.setBounds(1130,23,40,40);
    FButtonZoomOut.setBounds(1160,23,40,40);

    FPolygonButton8.setEnabled(false);
    FButtonCopy.setEnabled(false);
    FButtonPaste.setEnabled(false);
    FButtonGrid.setEnabled(false);
    FButtonLayers.setEnabled(false);
    FButtonZoomIn.setEnabled(false);
    FButtonZoomOut.setEnabled(false);
}
