#include <vector>
#include "RobotAirPurifierAQISensor.h"

RobotAirPurifierAQISensor::RobotAirPurifierAQISensor(){
    srand(time(NULL));
}

bool RobotAirPurifierAQISensor::connect(std::string connection_data)
{
    auto password = connection_data.substr(connection_data.length() - 3);
    if(password != "123")
    {
        std::cout <<"connection refused: " << connection_data << std::endl;
        return false;
    }
    bool is_sensor_reachable = true;
    if(is_sensor_reachable)
    {
        connected_ = true;
    }
    return true;
}

std::string RobotAirPurifierAQISensor::id() const{
    if(connected_ == false)
    {
        return {""};
    }
    return "AA:BB:CC:DD:EE:FF";
}

std::string RobotAirPurifierAQISensor::roomName() const{
    if(connected_ == false)
    {
        return {""};
    }
    static std::vector<std::string> rooms {"KidsRoom1", "KidsRoom2", "Office"};
    int random_room_number = rand() % 3;
    std::string roomName = rooms.at(random_room_number);
    return roomName;
}

int RobotAirPurifierAQISensor::airQualityIndex() const{
    if(connected_ == false)
    {
        return -1;
    }
    int air_quality_index = 10 + rand() %100;
    return air_quality_index;
}

int RobotAirPurifierAQISensor::PM2p5() const{
    if(connected_ == false)
    {
        return -1;
    }
    int pm2p5_ = 10 + rand() %100;
    return pm2p5_;
}