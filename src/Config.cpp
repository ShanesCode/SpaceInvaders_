#include "..\Headers\Config.h"

Config::Config(const std::string& configFileName):
	screenWidth(std::stof(getValFromConfigFile(configFileName, "screenWidth"))),
	screenHeight(std::stof(getValFromConfigFile(configFileName, "screenHeight"))),
	volume(std::stof(getValFromConfigFile(configFileName, "volume")))
{
}

std::string Config::getValFromConfigFile(const std::string& configFileName, const std::string& key)
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