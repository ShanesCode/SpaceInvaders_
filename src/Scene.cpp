//#include "../Headers/Scene.h"
//
//Scene::Scene(std::string sceneName_, std::string musicString_, Config& config): 
//	sceneName(sceneName_),
//	musicString(musicString_)
//{
//	createTextElements(config);
//	playMusic(true, config.volume);
//}
//
//sf::Text Scene::createText(const sf::Font& font, int size, sf::Color color, std::string string, float xpos, float ypos) {
//	sf::Text text;
//	text.setFont(font);
//	text.setCharacterSize(size);
//	text.setFillColor(color);
//	text.setString(string);
//	text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
//	text.setPosition(xpos, ypos);
//
//	textVector.push_back(text);
//	return text;
//}
//
//void Scene::updateText(int textVectorIndex, const sf::Font& font, int size, sf::Color color, std::string string, float xpos, float ypos) {
//	textVector.at(textVectorIndex).setFont(font);
//	textVector.at(textVectorIndex).setCharacterSize(size);
//	textVector.at(textVectorIndex).setFillColor(color);
//	textVector.at(textVectorIndex).setString(string);
//	textVector.at(textVectorIndex).setPosition(xpos, ypos);
//}
//
//void Scene::createTextElements(Config& config) {}
//
//void Scene::playMusic(bool loop, float volume)
//{
//	if (!music.openFromFile(musicString)) {
//		std::cout << "Failed to open the MENU song.";
//	}
//	music.setVolume(volume);
//	music.play();
//	music.setLoop(loop);
//}