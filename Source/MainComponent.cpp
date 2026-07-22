#include "../Include/MainComponent.h"
//topbar = 100(file -  1280x30(144 160 173), ToolsPanel - 1280x70(191 90 90))
//leftToolsBar(80x620)(144 160 173)
//buttons - 26x26, sliders - 120x6, перемычки - 13x70, перемычкиLeft - 13x80
// 1) сделать кисть и ластик 2) подписать панели 3) подставить иконки 3) 
MainComponent::MainComponent()
{
	//setSize(1280, 720); // задаём размер до добавления в окно
	canvas = new Canvas();
	buttonsPanelLeft = new ButtonsPanelLeft(canvas);
	buttonsPanel = new ButtonsPanel(canvas);
	colourPanel = new ColourPanel(canvas);
	sliderPanels = new SliderPanels(canvas);

	addAndMakeVisible(canvas);
	addAndMakeVisible(buttonsPanel);
	addAndMakeVisible(buttonsPanelLeft);
	addAndMakeVisible(colourPanel);
	addAndMakeVisible(sliderPanels);
	
}
MainComponent::~MainComponent() {}
void MainComponent::resized(void){
	int width = getWidth();
	int height = getHeight();

	// Панель кнопок сверху, высота 70 пикселей
	buttonsPanel->setBounds(0, 0, width, 70);
	buttonsPanelLeft->setBounds(0, 0, 80, height);
	sliderPanels->setBounds(398, 0, 300, 70);

	// Холст занимает всё остальное пространство
	canvas->setBounds(80, 70, width - 80, height - 70);
	colourPanel->setBounds(706, 20, 96, 32);
}