#include "..\Headers\AudioManager.h"
#include <iostream>

void AudioManager::loadSound(const std::string& name, const std::string& filename) {
	// Load the texture
	sf::SoundBuffer soundBuffer;
	soundBuffer.loadFromFile(filename);
	
	sf::Sound sound;
	sound.setBuffer(soundBuffer);

	sounds[name] = sound;
}

sf::Sound& AudioManager::getSoundRef(const std::string& sound) {
	return sounds.at(sound);
}

void AudioManager::playMusic(bool loop, float volume, std::string musicFileName)
{
	if (!music.openFromFile(musicFileName)) {
		std::cout << "Failed to open the MENU song.";
	}
	music.setVolume(volume);
	music.play();
	music.setLoop(loop);
}