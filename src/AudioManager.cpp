#include "..\Headers\AudioManager.h"
#include <iostream>

void AudioManager::loadSoundBuffer(const std::string& name, const std::string& filename) {
	// Load the sound
	sf::SoundBuffer soundBuffer;
	soundBuffer.loadFromFile(filename);

	soundBuffers[name] = soundBuffer;
}

sf::SoundBuffer& AudioManager::getRef(const std::string& sound) {
	return soundBuffers.at(sound);
}

void AudioManager::playMusic(const bool& loop, const float& volume, const std::string& musicFileName)
{
	sf::SoundBuffer soundBuffer;
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

void AudioManager::changeVolume(const float& vol) {
	music.setVolume(vol);
}

void AudioManager::playSound(const bool& loop, const float& volume, sf::Sound& sound, const std::string& soundRef)
{
	sound.setBuffer(getRef(soundRef));
	sound.setVolume(volume);
	sound.play();
	sound.setLoop(loop);
}

void AudioManager::stopSound(sf::Sound& sound) {
	sound.stop();
}