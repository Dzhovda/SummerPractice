#include "ButtonsPanelLeft.h"
#include "Canvas.h"
ButtonsPanelLeft::ButtonsPanelLeft(Canvas* owner):
    FBrush("Brush", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FEraser("Eraser", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FFill("Fill", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FPipette("Pipette", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FText("Text", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FFillOutline("FillOutline", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FMove("Move", DrawableButton::ButtonStyle::ImageAboveTextLabel),/*,
    FDottedLine("DottedLine", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FStreakLine("StreakLine", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FQuestion("Question", DrawableButton::ButtonStyle::ImageAboveTextLabel)*/
    FCancelButton("Cancel", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FSaveButton("Save", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FReturnButton("Return", DrawableButton::ButtonStyle::ImageAboveTextLabel),
    FDeleteAllButton("DeleteAll", DrawableButton::ButtonStyle::ImageAboveTextLabel)
{
    this->owner = owner;
    Component::setOpaque(true);

    // Определяем корневую папку приложения (там, где лежит .exe)
    auto appDir = juce::File::getSpecialLocation(juce::File::currentExecutableFile).getParentDirectory();

    // Brush
    auto iconBrushNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/BrushNormal.png"));
    auto iconBrushDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/BrushDown.png"));
    auto iconBrushOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/BrushOver.png"));
    FBrush.setImages(iconBrushNormal.get(), iconBrushOver.get(), iconBrushDown.get());

    // Eraser
    auto iconEraserNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EraserNormal.png"));
    auto iconEraserDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EraserDown.png"));
    auto iconEraserOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/EraserOver.png"));
    FEraser.setImages(iconEraserNormal.get(), iconEraserOver.get(), iconEraserDown.get());

    // Fill
    auto iconFillNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillNormal.png"));
    auto iconFillDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillDown.png"));
    auto iconFillOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillOver.png"));
    auto iconFillEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillEnable.png"));
    FFill.setImages(iconFillNormal.get(), iconFillOver.get(), iconFillDown.get(), iconFillEnable.get());

    // Pipette
    auto iconPipetteNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PipetteNormal.png"));
    auto iconPipetteDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PipetteDown.png"));
    auto iconPipetteOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PipetteOver.png"));
    auto iconPipetteEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/PipetteEnable.png"));
    FPipette.setImages(iconPipetteNormal.get(), iconPipetteOver.get(), iconPipetteDown.get(), iconPipetteEnable.get());

    // Text
    auto iconTextNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TextNormal.png"));
    auto iconTextDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TextDown.png"));
    auto iconTextOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TextOver.png"));
    auto iconTextEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/TextEnable.png"));
    FText.setImages(iconTextNormal.get(), iconTextOver.get(), iconTextDown.get(), iconTextEnable.get());

    // FillOutline
    auto iconFillOutNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillOutNormal.png"));
    auto iconFillOutDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillOutDown.png"));
    auto iconFillOutOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillOutOver.png"));
    auto iconFillOutEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/FillOutDown.png")); // если есть
    FFillOutline.setImages(iconFillOutNormal.get(), iconFillOutOver.get(), iconFillOutDown.get(), iconFillOutEnable.get());
    FFillOutline.setClickingTogglesState(true);
    // Hand
    auto iconHandNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/HandNormal.png"));
    auto iconHandDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/HandDown.png"));
    auto iconHandOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/HandOver.png"));
    auto iconHandEnable = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/HandEnable.png"));
    FMove.setImages(iconHandNormal.get(), iconHandOver.get(), iconHandDown.get(), iconHandEnable.get());

    // Дополнительные кнопки: Return, Cancel, Delete, Save
    // Return
    auto iconReturnNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ReturnNormal.png"));
    auto iconReturnDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ReturnDown.png"));
    auto iconReturnOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/ReturnOver.png"));
    FReturnButton.setImages(iconReturnNormal.get(), iconReturnOver.get(), iconReturnDown.get());

    // Cancel
    auto iconCancelNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CancelNormal.png"));
    auto iconCancelDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CancelDown.png"));
    auto iconCancelOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/CancelOver.png"));
    FCancelButton.setImages(iconCancelNormal.get(), iconCancelOver.get(), iconCancelDown.get());

    // Delete
    auto iconDeleteNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/DeleteNormal.png"));
    auto iconDeleteDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/DeleteDown.png"));
    auto iconDeleteOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/DeleteOver.png"));
    FDeleteAllButton.setImages(iconDeleteNormal.get(), iconDeleteOver.get(), iconDeleteDown.get());

    // Save
    auto iconSaveNormal = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/SaveNormal.png"));
    auto iconSaveDown = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/SaveDown.png"));
    auto iconSaveOver = juce::Drawable::createFromImageFile(appDir.getChildFile("Resources/SaveOver.png"));
    FSaveButton.setImages(iconSaveNormal.get(), iconSaveOver.get(), iconSaveDown.get());
    Component::addAndMakeVisible(FBrush);
    Component::addAndMakeVisible(FEraser);
    Component::addAndMakeVisible(FFill);
    Component::addAndMakeVisible(FPipette);
    Component::addAndMakeVisible(FText);
    Component::addAndMakeVisible(FFillOutline);
    Component::addAndMakeVisible(FMove);
    /*Component::addAndMakeVisible(FDottedLine);
    Component::addAndMakeVisible(FStreakLine);
    Component::addAndMakeVisible(FQuestion);*/

    Component::addAndMakeVisible(FSaveButton);
    Component::addAndMakeVisible(FDeleteAllButton);
    Component::addAndMakeVisible(FCancelButton);
    Component::addAndMakeVisible(FReturnButton);

    std::string utf8Text = u8"Инструменты";
    juce::String myString = juce::String::fromUTF8(utf8Text.data(), utf8Text.size());
    FInstrumentPanel.setText(myString, NotificationType::dontSendNotification);

    FBrush.addListener(this);
    FEraser.addListener(this);
    FFill.addListener(this);
    FPipette.addListener(this);
    FText.addListener(this);
    FFillOutline.addListener(this);
    FMove.addListener(this);
    /*FDottedLine.addListener(this);
    FStreakLine.addListener(this);
    FQuestion.addListener(this);*/
    FDeleteAllButton.addListener(this);
    FSaveButton.addListener(this);
    FReturnButton.addListener(this);
    FCancelButton.addListener(this);
}
ButtonsPanelLeft::~ButtonsPanelLeft(void)
{

}
void ButtonsPanelLeft::buttonClicked(Button* button)
{
    if (button == &FBrush) {
        owner->SetFigures(Canvas::Line::Figures::brush);
    }
    if (button == &FEraser) {
        owner->SetFigures(Canvas::Line::Figures::eraser);
    }
    if (button == &FFillOutline) {
        if (owner->GetFill() == false) {
            owner->SetFill(true);
        }
        else {
            owner->SetFill(false);
        }
    }

    //Cancel, Delete, Return, Save
    if (button == &FDeleteAllButton) {
        owner->DeleteLines();
    }
}
void ButtonsPanelLeft::resized() {
    FInstrumentPanel.setBounds(0,255,100,50);
}
void ButtonsPanelLeft::paint(Graphics& g){
    g.fillAll(juce::Colour(144, 160, 173));
    g.setColour(Colour(191, 90, 90));
    g.fillRect(0,0,80,70);
    //перемычки левой панели
    g.setColour(Colour(217, 217, 217));
    g.fillRect(0, 70, 80, 13);
    g.fillRect(0, 432, 80, 13); // мб + 30 по Y

    FBrush.setBounds(40,85,40,40);
    FEraser.setBounds(40, 135, 40, 40);
    FFill.setBounds(40, 185, 40, 40);
    FPipette.setBounds(40, 235, 40, 40);
    FText.setBounds(40, 285, 40, 40);
    FFillOutline.setBounds(40, 335, 40, 40);
    FMove.setBounds(40, 385, 40, 40);
    /*FDottedLine.setBounds(40, 315, 25, 25);
    FStreakLine.setBounds(40, 345, 25, 25);
    FQuestion.setBounds(40, 375, 25, 25);*/
    FFillOutline.isToggleable();

    FFill.setEnabled(false);
    FPipette.setEnabled(false);
    FText.setEnabled(false);
    FMove.setEnabled(false);

    //Cancel, Delete, Return, Save
    FCancelButton.setBounds(0, 5, 40, 40);
    FReturnButton.setBounds(40, 5, 40, 40);
    FDeleteAllButton.setBounds(0, 40, 40, 40);
    FSaveButton.setBounds(40, 40, 40, 40);

    /*FDottedLine.setEnabled(false);
    FStreakLine.setEnabled(false);
    FQuestion.setEnabled(false);*/
    // текст
    g.setColour(juce::Colours::black);
    g.setFont(juce::Font(16.0f, juce::Font::bold));
    auto bounds = getLocalBounds();
    float centerX = 20.0f;   // Отступ слева
    float centerY = bounds.getHeight() / 3.0f;
    g.addTransform(juce::AffineTransform::rotation(juce::MathConstants<float>::pi * 3 / 2.0f,
        centerX, centerY));
    juce::String text = juce::String::fromUTF8(u8"Инструменты");
    juce::Rectangle<float> textArea(centerX - 70, centerY - 10, 140, 20);
    g.drawText(text, textArea, juce::Justification::centred, true);
}


