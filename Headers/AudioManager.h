#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class AudioManager {
private:
	// Array of sfx
	std::map<std::string, sf::Sound> sounds;

	sf::Music music;

public:
	// Add a sound from a file
	void loadSound(const std::string& name, const std::string& filename);

	// Translate an id into a reference
	sf::Sound& getSoundRef(const std::string& sound);

	void playMusic(bool loop, float volume, std::string musicFileName);

	AudioManager() {
	}
};