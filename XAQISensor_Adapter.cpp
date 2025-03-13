#include "XAQISensor_Adapter.h"

bool XAQISensor_Adapter::Connect(std::string connectionData)
{
    return sensor_.Connect(connectionData);   
}

void XAQISensor_Adapter::SetRoomName(std::string roomName)
{
    return sensor_.SetRoomName(roomName);
}

std::string XAQISensor_Adapter::RoomName() const
{
    return sensor_.RoomName();
}

std::vector<AQIParameter> XAQISensor_Adapter::GetData() const 
{
    std::vector<AQIParameter> data;
    AQIParameter air_quality_index;

    air_quality_index.name = "AQI";
    air_quality_index.value = sensor_.AirQualityIndex();
    air_quality_index.unit = "";

    data.push_back(air_quality_index);

    return data;
}