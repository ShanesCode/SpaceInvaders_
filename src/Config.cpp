#include "..\Headers\Config.h"

Config::Config(const std::string& configFileName):
	screenWidth(std::stof(getConfigFromFile(configFileName, "screenWidth"))),
	screenHeight(std::stof(getConfigFromFile(configFileName, "screenHeight"))),
	volume(std::stof(getConfigFromFile(configFileName, "volume")))
{
}

std::string Config::getConfigFromFile(const std::string& configFileName, const std::string& key)
{
	std::string data;
	std::ifstream configFile(configFileName);

	while (getline(configFile, data)) {
		// Output the text from the file
		if (data.find(key) != std::string::npos) {
			return data.substr(key.length() + 3);
		}
	}

	configFile.close();
}

void Config::updateConfig(const std::string& configFileName, const std::string& key)
{
	//TODO
}