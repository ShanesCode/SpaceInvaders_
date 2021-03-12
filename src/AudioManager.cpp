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
		std::cout << "Failed to open the MENU song.";
	}
	music.setVolume(volume);
	music.play();
	music.setLoop(loop);
}

void AudioManager::pauseMusic() {
	// pause playback
	sound.pause();
}

void AudioManager::resumeMusic() {
	// resume playback
	sound.play();
}

void AudioManager::stopMusic() {
	// stop playback and rewind
	sound.stop();
}