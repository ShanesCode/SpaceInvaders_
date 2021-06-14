#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class AudioManager {
private:
	std::map<std::string, sf::SoundBuffer> soundBuffers;
	sf::Music music;

public:
	// Add a soundBuffer from a file
	void loadSoundBuffer(const std::string& name, const std::string& filename);

	// Translate an id into a reference
	sf::SoundBuffer& getRef(const std::string& sound);

	void playMusic(const bool& loop, const float& volume, const std::string& musicFileName);
	void playSound(const bool& loop, const float& volume, sf::Sound& sound, const std::string& soundRef);

	void pauseMusic();
	void resumeMusic();
	void stopMusic();
	void stopSound(sf::Sound& sound);
	void changeVolume(const float& vol);
};