#pragma once
#include <SFML/Graphics.hpp>
#include "MenuScene.h"

class OptionsScene : public MenuScene {
private:
	void returnToPreviousScene();

	void createTitleText() override;
	void createMenuText() override;
	void selectMenuItem() override;

	void draw(const float dt) override;

	sf::Sprite sliderBG;
	sf::Sprite slider;
	void initSliderGraphics();
	void updateSliderGraphic();
	void changeVolumeSlider(bool increase);

	void handleInput() override;

	float max_volume;
	float min_volume;

public:
	OptionsScene(Game* game_);
};