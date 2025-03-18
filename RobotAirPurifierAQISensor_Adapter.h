#pragma once
#include "AQISensor.h"
#include "RobotAirPurifierAQISensor.h"

class RobotAirPurifierAQISensor_Adapter : public MobileAQISensor
{
    private:
    RobotAirPurifierAQISensor sensor_;

    public:
    bool Connect(std::string connectionData) override;
    std::string RoomName() const override;
    std::vector<AQIParameter> GetData() const override;
};