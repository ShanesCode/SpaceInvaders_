#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class Config {
private:
	std::string configFileName;
	std::map<std::string, float> configVals;
	std::string delimiter;

	void getValsFromConfigFile();
	void updateConfigFile();
	void updateConfigVals();
public:
	float screenWidth;
	float screenHeight;
	float volume;

	Config(const std::string& configFileName);
	void updateConfig(std::string key, float val);
};