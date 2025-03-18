#pragma once
#include <iostream>

class RobotAirPurifierAQISensor{
    public:
    RobotAirPurifierAQISensor();
    bool connect(std::string connection_data);
    std::string id() const;
    std::string roomName() const;
    int airQualityIndex() const;
    int PM2p5() const;

    private:
    bool connected_ {false};
};