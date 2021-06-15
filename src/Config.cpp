#include "../Headers/Config.h"

Config::Config(const std::string& configFileName_) {
	configFileName = configFileName_;
	delimiter = " = ";
	getValsFromConfigFile();
	updateConfigVals();
}

void Config::getValsFromConfigFile() {
	std::string line;
	std::ifstream configFile(configFileName);
	int delim_len = delimiter.length();

	while (getline(configFile, line)) {
		std::string key = line.substr(0, line.find(delimiter));
		std::string val = line.substr(line.find(delimiter) + delim_len, line.length());
		configVals[key] = std::stof(val);
	}

	configFile.close();
}

void Config::updateConfig(std::string key, float val) {
	configVals[key] = val;
	updateConfigVals();
}

void Config::updateConfigFile() {
	// For each key-val pair in configVals, write a line of text of the format: "key = val"
	std::ofstream configFile;
	configFile.open(configFileName, std::ios::out | std::ios::trunc);
	std::string line;
	std::map<std::string, float>::iterator iter = configVals.begin();
	while (iter != configVals.end()) {
		line = iter->first + delimiter + std::to_string(iter->second);
		configFile << line << std::endl;
		iter++;
	}

	configFile.close();
}

void Config::updateConfigVals() {
	screenWidth = configVals["screenWidth"];
	screenHeight = configVals["screenHeight"];
	volume = configVals["volume"];
}