#pragma once
#include <iostream>
#include <vector>

struct AQIParameter{
    std::string name;
    int value;
    std::string unit;
};

class AQISensor{
    public:
    virtual ~AQISensor() = default;
    virtual bool Connect(std::string connection_data) = 0;
    virtual void SetRoomName(std::string room_name) = 0;
    virtual std::string RoomName() const = 0;
    virtual std::vector<AQIParameter> GetData() const = 0;
};