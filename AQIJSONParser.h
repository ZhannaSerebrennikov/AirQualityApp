#include <iostream>

class AQIJSONParser{
    public:
    int AirQualityIndex(const std::string& jsonData) const;
    int Co2Level(const std::string& jsonData) const;
    int Temperature(const std::string& jsonData) const;
    int Humidity(const std::string& jsonData) const;

    private:
    int getValueFromKey(std::string key, const std::string& jsonData) const;
};