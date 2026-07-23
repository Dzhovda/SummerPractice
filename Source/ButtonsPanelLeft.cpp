#include "ButtonsPanelLeft.h"
#include "Canvas.h"

ButtonsPanelLeft::ButtonsPanelLeft(Canvas* owner) :
    FBrush("Brush", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FEraser("Eraser", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FFill("Fill", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FPipette("Pipette", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FText("Text", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FFillOutline("FillOutline", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FMove("Move", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FCancelButton("Cancel", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FSaveButton("Save", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FReturnButton("Return", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FDeleteAllButton("DeleteAll", DrawableButton::ButtonStyle::ImageAboveTextLabel)
{
    this->owner = owner;
    Component::setOpaque(true);

    // Определяем корневую папку приложения
    auto appDir = juce::File::getCurrentWorkingDirectory().getParentDirectory().getParentDirectory();

    // ===== Загрузка иконок для инструментов =====
    // Brush
    auto iconBrushNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/BrushNormal.png"));
    auto iconBrushDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/BrushDown.png"));
    auto iconBrushOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/BrushOver.png"));
    FBrush.setImages(iconBrushNormal.get(), iconBrushOver.get(), iconBrushDown.get());

    // Eraser
    auto iconEraserNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EraserNormal.png"));
    auto iconEraserDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EraserDown.png"));
    auto iconEraserOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/EraserOver.png"));
    FEraser.setImages(iconEraserNormal.get(), iconEraserOver.get(), iconEraserDown.get());

    // Fill
    auto iconFillNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillNormal.png"));
    auto iconFillDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillDown.png"));
    auto iconFillOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillOver.png"));
    auto iconFillEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillEnable.png"));
    FFill.setImages(iconFillNormal.get(), iconFillOver.get(), iconFillDown.get(), iconFillEnable.get());

    // Pipette
    auto iconPipetteNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PipetteNormal.png"));
    auto iconPipetteDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PipetteDown.png"));
    auto iconPipetteOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PipetteOver.png"));
    auto iconPipetteEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/PipetteEnable.png"));
    FPipette.setImages(iconPipetteNormal.get(), iconPipetteOver.get(), iconPipetteDown.get(), iconPipetteEnable.get());

    // Text
    auto iconTextNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TextNormal.png"));
    auto iconTextDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TextDown.png"));
    auto iconTextOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TextOver.png"));
    auto iconTextEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/TextEnable.png"));
    FText.setImages(iconTextNormal.get(), iconTextOver.get(), iconTextDown.get(), iconTextEnable.get());

    // FillOutline (переключаемая кнопка)
    auto iconFillOutNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillOutNormal.png"));
    auto iconFillOutDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillOutDown.png"));
    auto iconFillOutOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillOutOver.png"));
    auto iconFillOutEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/FillOutDown.png"));
    FFillOutline.setImages(iconFillOutNormal.get(), iconFillOutOver.get(), iconFillOutDown.get(), iconFillOutEnable.get());
    FFillOutline.setClickingTogglesState(true); // Режим переключателя

    // Hand
    auto iconHandNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/HandNormal.png"));
    auto iconHandDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/HandDown.png"));
    auto iconHandOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/HandOver.png"));
    auto iconHandEnable = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/HandEnable.png"));
    FMove.setImages(iconHandNormal.get(), iconHandOver.get(), iconHandDown.get(), iconHandEnable.get());

    // ===== Кнопки навигации =====
    // Return
    auto iconReturnNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ReturnNormal.png"));
    auto iconReturnDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ReturnDown.png"));
    auto iconReturnOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/ReturnOver.png"));
    FReturnButton.setImages(iconReturnNormal.get(), iconReturnOver.get(), iconReturnDown.get());

    // Cancel
    auto iconCancelNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CancelNormal.png"));
    auto iconCancelDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CancelDown.png"));
    auto iconCancelOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/CancelOver.png"));
    FCancelButton.setImages(iconCancelNormal.get(), iconCancelOver.get(), iconCancelDown.get());

    // Delete
    auto iconDeleteNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/DeleteNormal.png"));
    auto iconDeleteDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/DeleteDown.png"));
    auto iconDeleteOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/DeleteOver.png"));
    FDeleteAllButton.setImages(iconDeleteNormal.get(), iconDeleteOver.get(), iconDeleteDown.get());

    // Save
    auto iconSaveNormal = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/SaveNormal.png"));
    auto iconSaveDown = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/SaveDown.png"));
    auto iconSaveOver = juce::Drawable::createFromImageFile(appDir.getFullPathName() + ("/Resources/SaveOver.png"));
    FSaveButton.setImages(iconSaveNormal.get(), iconSaveOver.get(), iconSaveDown.get());

    // Добавляем кнопки в иерархию
    Component::addAndMakeVisible(FBrush);
    Component::addAndMakeVisible(FEraser);
    Component::addAndMakeVisible(FFill);
    Component::addAndMakeVisible(FPipette);
    Component::addAndMakeVisible(FText);
    Component::addAndMakeVisible(FFillOutline);
    Component::addAndMakeVisible(FMove);
    Component::addAndMakeVisible(FSaveButton);
    Component::addAndMakeVisible(FDeleteAllButton);
    Component::addAndMakeVisible(FCancelButton);
    Component::addAndMakeVisible(FReturnButton);

    // Текстовая метка "Инструменты"
    std::string utf8Text = u8"Инструменты";
    juce::String myString = juce::String::fromUTF8(utf8Text.data(), utf8Text.size());
    FInstrumentPanel.setText(myString, NotificationType::dontSendNotification);
    Component::addAndMakeVisible(FInstrumentPanel);

    // Подписка на события кнопок
    FBrush.addListener(this);
    FEraser.addListener(this);
    FFill.addListener(this);
    FPipette.addListener(this);
    FText.addListener(this);
    FFillOutline.addListener(this);
    FMove.addListener(this);
    FDeleteAllButton.addListener(this);
    FSaveButton.addListener(this);
    FReturnButton.addListener(this);
    FCancelButton.addListener(this);
}

ButtonsPanelLeft::~ButtonsPanelLeft(void)
{
    // Слушатели автоматически отписываются при разрушении,
    // но для уверенности можно вызвать removeListener для каждой кнопки
}

void ButtonsPanelLeft::buttonClicked(Button* button)
{
    if (button == &FBrush) {
        owner->SetFigures(Canvas::Line::Figures::brush);
    }
    if (button == &FEraser) {
        owner->SetFigures(Canvas::Line::Figures::eraser);
    }
    if (button == &FFill) {
        owner->SetFigures(Canvas::Line::Figures::fillFigure);
    }
    if (button == &FFillOutline) {
        if (owner->GetFill() == false) {
            owner->SetFill(true);
        }
        else {
            owner->SetFill(false);
        }
    }
    if (button == &FDeleteAllButton) {
        owner->DeleteLines();
    }
    // Остальные кнопки (Cancel, Return, Save) пока не реализованы
    if (button == &FSaveButton) {
        owner->saveCanvasToPNG();
    }
    if (button == &FReturnButton) {
        owner->ReturnStep();
    }
    if (button == &FCancelButton) {
        owner->CancelStep();
    }
}

void ButtonsPanelLeft::resized() {
    //FInstrumentPanel.setBounds(0, 255, 100, 50);

    // Инструменты
    FBrush.setBounds(40, 85, 40, 40);
    FEraser.setBounds(40, 135, 40, 40);
    FFill.setBounds(40, 185, 40, 40);
    FPipette.setBounds(40, 235, 40, 40);
    FText.setBounds(40, 285, 40, 40);
    FFillOutline.setBounds(40, 335, 40, 40);
    FMove.setBounds(40, 385, 40, 40);

    // Кнопки навигации (в верхней части панели)
    FCancelButton.setBounds(0, 5, 40, 40);
    FReturnButton.setBounds(40, 5, 40, 40);
    FDeleteAllButton.setBounds(0, 40, 40, 40);
    FSaveButton.setBounds(40, 40, 40, 40);

    // Временно отключаем нереализованные функции
    //FFill.setEnabled(false);
    FPipette.setEnabled(false);
    FText.setEnabled(false);
    FMove.setEnabled(false);
}

void ButtonsPanelLeft::paint(Graphics& g) {
    g.fillAll(juce::Colour(144, 160, 173));
    g.setColour(Colour(191, 90, 90));
    g.fillRect(0, 0, 80, 70);

    // Горизонтальные разделители
    g.setColour(Colour(217, 217, 217));
    g.fillRect(0, 70, 80, 13);
    g.fillRect(0, 432, 80, 13);

    // Позиционирование кнопок (вынесено в resized, но оставлено здесь для синхронизации)
    
    g.setColour(juce::Colours::black);
    g.setFont(juce::Font(16.0f, juce::Font::bold));
    auto bounds = getLocalBounds();
    float centerX = 20.0f;
    float centerY = bounds.getHeight() / 3.0f;
    g.addTransform(juce::AffineTransform::rotation(juce::MathConstants<float>::pi * 3 / 2.0f,
        centerX, centerY));
    juce::String text = juce::String::fromUTF8(u8"Инструменты");
    juce::Rectangle<float> textArea(centerX - 70, centerY - 10, 140, 20);
    g.drawText(text, textArea, juce::Justification::centred, true);
}