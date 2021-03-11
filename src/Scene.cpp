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
//void Scene::playMusic(bool loop, float volume)
//{
//	if (!music.openFromFile(musicString)) {
//		std::cout << "Failed to open the MENU song.";
//	}
//	music.setVolume(volume);
//	music.play();
//	music.setLoop(loop);
//}