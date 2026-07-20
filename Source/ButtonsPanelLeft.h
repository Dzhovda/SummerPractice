#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class Canvas;
class ButtonsPanelLeft: public Component, public DrawableButton::Listener
{
public:
	ButtonsPanelLeft(Canvas* owner);
	~ButtonsPanelLeft();

	void paint(Graphics&) override;
	void resized(void) override;
	void buttonClicked(Button*) override;

private:
	Canvas* owner = nullptr;

	DrawableButton FBrush;
	DrawableButton FEraser;
	DrawableButton FFill;
	DrawableButton FPipette;
	DrawableButton FText;
	DrawableButton FFillOutline;
	DrawableButton FMove;
	/*DrawableButton FDottedLine;
	DrawableButton FStreakLine;
	DrawableButton FMirrow;*/

	//кнопки вперед, назад, сохранить, удалить
	DrawableButton FCancelButton;
	DrawableButton FReturnButton;
	DrawableButton FSaveButton;
	DrawableButton FDeleteAllButton;

	Label FInstrumentPanel;
};

