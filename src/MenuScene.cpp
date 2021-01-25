//#include "../Headers/MenuScene.h"
//// Rethink this. What do I want the MenuScene do as an instance of Scene? Where should these functions be called?
//// Scenes should be compositions of the building blocks: text objects, graphics, etc.
//MenuScene::MenuScene(std::string sceneName_, std::string musicString_, Config& config) :
//	Scene(sceneName_, musicString_, config),
//	menuIndex(6)
//{
//	selectedTextIndex = menuIndex;
//	createTextElements(config);
//}
//
//void MenuScene::createTextElements(Config &config) {
//	// Create text and fonts
//	createTitle(config);
//	createMenu(config);
//}
//
//void MenuScene::createTitle(Config& config) {
//	float title_offset = 108.0f;
//	float shadow_offset = 10.0f;
//
//	sf::Text spaceTextShadow2 = createText(config.titleFont, 108, sf::Color::Color(254, 51, 47, 150), "SPACE", config.screenWidth / 2, (config.screenHeight / 4) - (title_offset / 2));
//	sf::Text invadersTextShadow2 = createText(config.titleFont, 108, sf::Color::Color(254, 51, 47, 150), "INVADERS", config.screenWidth / 2, (config.screenHeight / 4) + (title_offset / 2));
//	sf::Text spaceTextShadow1 = createText(config.titleFont, 108, sf::Color::Color(248, 88, 66, 200), "SPACE", spaceTextShadow2.getPosition().x, spaceTextShadow2.getPosition().y + shadow_offset);
//	sf::Text invadersTextShadow1 = createText(config.titleFont, 108, sf::Color::Color(248, 88, 66, 200), "INVADERS", invadersTextShadow2.getPosition().x, invadersTextShadow2.getPosition().y + shadow_offset);
//	sf::Text spaceText = createText(config.titleFont, 108, sf::Color::Yellow, "SPACE", spaceTextShadow1.getPosition().x, spaceTextShadow1.getPosition().y + shadow_offset);
//	sf::Text invadersText = createText(config.titleFont, 108, sf::Color::Yellow, "INVADERS", invadersTextShadow1.getPosition().x, invadersTextShadow1.getPosition().y + shadow_offset);
//}
//
//void MenuScene::createMenu(Config& config) {
//	float menu_text_offset = 54.0f;
//
//	sf::Text startText = createText(config.normalFont, 36, sf::Color::Green, "START", config.screenWidth / 2, config.screenHeight / 2);
//	sf::Text hiscoresText = createText(config.normalFont, 36, sf::Color::White, "HISCORES", config.screenWidth / 2, (startText.getPosition().y + menu_text_offset));
//	sf::Text optionsText = createText(config.normalFont, 36, sf::Color::White, "OPTIONS", config.screenWidth / 2, (hiscoresText.getPosition().y + menu_text_offset));
//	sf::Text quitText = createText(config.normalFont, 36, sf::Color::White, "QUIT", config.screenWidth / 2, (optionsText.getPosition().y + menu_text_offset));
//}
//
//int MenuScene::navigateMenu(int input, Config& config) {
//	// Set currently selected text to white
//	updateText(
//		selectedTextIndex,
//		config.normalFont,
//		36,
//		sf::Color::White,
//		textVector.at(selectedTextIndex).getString(),
//		textVector.at(selectedTextIndex).getPosition().x,
//		textVector.at(selectedTextIndex).getPosition().y
//	);
//
//	if (input == 1) {
//		if (selectedTextIndex == menuIndex) {
//			selectedTextIndex = textVector.size() - 1;
//		}
//		else {
//			selectedTextIndex = selectedTextIndex - 1;
//		}
//	}
//	else if (input == 2) {
//		if (selectedTextIndex == textVector.size() - 1) {
//			selectedTextIndex = menuIndex;
//		}
//		else {
//			selectedTextIndex = selectedTextIndex + 1;
//		}
//	}
//	// Set new selected text to green
//	updateText(
//		selectedTextIndex, 
//		config.normalFont, 
//		36, 
//		sf::Color::Green, 
//		textVector.at(selectedTextIndex).getString(), 
//		textVector.at(selectedTextIndex).getPosition().x, 
//		textVector.at(selectedTextIndex).getPosition().y
//	);
//	return selectedTextIndex;
//}
//
//
