#include "..\Headers\AudioManager.h"
#include <iostream>

void AudioManager::loadSound(const std::string& filename) {
	// Load the sound
	soundBuffer.loadFromFile(filename);
	sound.setBuffer(soundBuffer);
}

void AudioManager::playMusic(bool loop, float volume, std::string musicFileName)
{
	loadSound(musicFileName);
	if (!music.openFromFile(musicFileName)) {
		std::cout << "Failed to open the song:\t" << musicFileName << std::endl;
	}
	music.setVolume(volume);
	music.play();
	music.setLoop(loop);
}

void AudioManager::pauseMusic() {
	sound.pause();
}

void AudioManager::resumeMusic() {
	sound.play();
}

void AudioManager::stopMusic() {
	sound.stop();
}

void AudioManager::changeVolume(float vol) {
	music.setVolume(vol);
}

void AudioManager::playSound(bool loop, float volume, std::string soundFileName)
{
	soundFileName = "Resource/" + soundFileName;
	loadSound(soundFileName);
	sound.setVolume(volume);
	sound.play();
	sound.setLoop(loop);
}