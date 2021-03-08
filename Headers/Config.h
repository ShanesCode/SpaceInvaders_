#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Config {
private:
	std::string getConfigFromFile(const std::string& configFileName, const std::string& key);
public:
	const float screenWidth;
	const float screenHeight;
	
	float volume;

	Config(const std::string& configFileName);
	void updateConfig(const std::string& configFileName, const std::string& key);
};

//extern const Config config;