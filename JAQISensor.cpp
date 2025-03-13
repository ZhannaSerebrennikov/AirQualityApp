#include "iostream"
#include "JAQISensor.h"

JAQISensor::JAQISensor()
{
    srand(time(NULL));
}

bool JAQISensor::Connect(std::string connection_data)
{
    auto password = connection_data.substr(connection_data.length() - 3);
    if(password != "123")
    {
        std::cout << "connection refused: " << connection_data << std::endl;
        return false;
    }

    bool is_sensor_reachable = true;
    if(is_sensor_reachable)
    {
        connected_ = true;
    }

    return true;
}

void JAQISensor::SetRoomName(std::string room_name)
{
    if(connected_ == false)
    {
        return;
    }
    room_name_ = room_name;
}

std::string JAQISensor::RoomName() const
{
    return room_name_;
}

std::string JAQISensor::jsonData() const
{
    if(connected_ == false)
    {
        return {};
    }
    int air_quality_index = 10 + rand() % 100;
    int co2_level = 400 + rand() % 2000;
    int temperature = 16 +rand() % 10;
    int humidity = 20 + rand() % 40;

    return "{\n"
    "\"SensorType\" : \"BrandJAirQualitySensor\",\n"
    "\"AirQualityIndex\" : " + std::to_string(air_quality_index) + ",\n"
    "\"CO2Level\" : " + std::to_string(co2_level) + ",\n"
    "\"Temperature\" : " + std::to_string(temperature) + ",\n"
    "\"Humidity\" : " + std::to_string(humidity) + "\n"
    "}"
    ;
}