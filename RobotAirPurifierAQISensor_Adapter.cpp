#include "RobotAirPurifierAQISensor_Adapter.h"

bool RobotAirPurifierAQISensor_Adapter::Connect(std::string connectionData) {
    return sensor_.connect(connectionData);
}

std::string RobotAirPurifierAQISensor_Adapter::RoomName() const {
    return sensor_.roomName();
}

std::vector<AQIParameter> RobotAirPurifierAQISensor_Adapter::GetData() const {
    std::vector<AQIParameter> data;
    
    AQIParameter air_quality_index;
    AQIParameter PM2p5;
    
    air_quality_index.name = "AQI";
    air_quality_index.value = sensor_.airQualityIndex();
    air_quality_index.unit = "";
    
    PM2p5.name = "PM2.5";
    PM2p5.value = sensor_.airQualityIndex();
    PM2p5.unit = "ug/m3";
    
    data.push_back(air_quality_index);
    data.push_back(PM2p5);

    return data;
}