#pragma once
#include <iostream>
#include <vector>

struct AQIParameter{
    std::string name;
    int value;
    std::string unit;
};
class AQISensorInformation{
    public:
    virtual ~AQISensorInformation() = default;
    virtual std::string RoomName() const = 0;
    virtual std::vector<AQIParameter> GetData() const = 0;
};

class AQISensorConnection{
    public:
    virtual ~AQISensorConnection() = default;
    virtual bool Connect(std::string connection_data) = 0;
};

class AQISensor : public AQISensorInformation, public AQISensorConnection{
    public:
    virtual ~AQISensor() = default;
    virtual bool Connect(std::string connection_data) = 0;
    virtual std::string RoomName() const = 0;
    virtual std::vector<AQIParameter> GetData() const = 0;
};

class MobileAQISensor : public AQISensor{
    //
};

class StationaryAQISensor : public AQISensor
{
    public:
    virtual void SetRoomName(std::string room_name) = 0;
};