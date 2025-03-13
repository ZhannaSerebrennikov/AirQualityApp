#include "AQIJSONParser.h"

int AQIJSONParser::getValueFromKey(std::string key, const std::string& jsonData) const
{
    std::string start_string{key};
    std::string json_syntax_connector{"\" : \""};
    auto start_index = jsonData.find(start_string) + start_string.length() + json_syntax_connector.length();
    auto end_index = jsonData.find(",", start_index);
    std::string return_value = jsonData.substr(start_index - 1, end_index - start_index + 1);

    return stoi(return_value);
}

int AQIJSONParser::AirQualityIndex(const std::string& jsonData) const {
    return getValueFromKey("AirQualityIndex", jsonData);
}

int AQIJSONParser::Co2Level(const std::string& jsonData) const {
    return getValueFromKey("CO2Level", jsonData);
}

int AQIJSONParser::Temperature(const std::string& jsonData) const {
    return getValueFromKey("Temperature", jsonData);
}

int AQIJSONParser::Humidity(const std::string& jsonData) const {
    return getValueFromKey("Humidity", jsonData);
}