#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class AudioManager {
private:
	// Array of sfx
	std::map<std::string, sf::Sound> sounds;

	sf::Music music;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

public:
	// Add a sound from a file
	void loadSound(const std::string& filename);;

	void playMusic(bool loop, float volume, std::string musicFileName);
	void playSound(bool loop, float volume, std::string soundFileName);

	void pauseMusic();
	void resumeMusic();
	void stopMusic();
	void changeVolume(float vol);
};