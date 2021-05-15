#include "..\Headers\AudioManager.h"
#include <iostream>

void AudioManager::loadSound(const std::string& filename) {
	// Load the sound
	sf::Sound sound;
	soundBuffer.loadFromFile(filename);
	sound.setBuffer(soundBuffer);
	sounds.emplace_back(sound);
}

void AudioManager::playMusic(bool loop, float volume, std::string musicFileName)
{
	soundBuffer.loadFromFile(musicFileName);
	if (!music.openFromFile(musicFileName)) {
		std::cout << "Failed to open the song:\t" << musicFileName << std::endl;
	}
	music.setVolume(volume);
	music.play();
	music.setLoop(loop);
}

void AudioManager::pauseMusic() {
	music.pause();
}

void AudioManager::resumeMusic() {
	music.play();
}

void AudioManager::stopMusic() {
	music.stop();
}

void AudioManager::changeVolume(float vol) {
	music.setVolume(vol);
}

void AudioManager::playSound(bool loop, float volume, std::string soundFileName)
{
	soundFileName = "Resource/" + soundFileName;
	loadSound(soundFileName);
	sounds.back().setVolume(volume);
	sounds.back().play();
	sounds.back().setLoop(loop);
	eraseFinishedSounds();
}

void AudioManager::eraseFinishedSounds() {
	for (int i = 0; i < sounds.size(); i++) {
		std::cout << "looping: " << sounds[i].getLoop() << '\t' << "status: " << sounds[i].getStatus() << std::endl;
		if (sounds[i].getStatus() == sf::Sound::Stopped) {
			//sounds.erase(sounds.begin() + i);
			//--i;
		}
	}
}