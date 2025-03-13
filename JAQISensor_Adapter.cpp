#include "JAQISensor_Adapter.h"

bool JAQISensor_Adapter::Connect(std::string connectionData)
{
    return sensor_.Connect(connectionData);   
}

void JAQISensor_Adapter::SetRoomName(std::string roomName)
{
    return sensor_.SetRoomName(roomName);
}

std::string JAQISensor_Adapter::RoomName() const
{
    return sensor_.RoomName();
}

std::vector<AQIParameter> JAQISensor_Adapter::GetData() const 
{
    std::string jsonData = sensor_.jsonData();
    //cout << jsonData << endl;
    AQIParameter air_quality_index;
    AQIParameter co2level;
    AQIParameter temperature;
    AQIParameter humidity;
   
    air_quality_index.name = "AQI";
    air_quality_index.value = parser_.AirQualityIndex(jsonData);
    air_quality_index.unit = "";

    co2level.name = "CO2";
    co2level.value = parser_.Co2Level(jsonData);
    co2level.unit = "ppm";


    temperature.name = "Temperature";
    temperature.value = parser_.Temperature(jsonData);
    temperature.unit = "Celsius";

    humidity.name = "Humidity";
    humidity.value = parser_.Humidity(jsonData);
    humidity.unit = "%";

    std::vector<AQIParameter> data;

    data.push_back(air_quality_index);
    data.push_back(co2level);
    data.push_back(temperature);
    data.push_back(humidity);

    return data;
}