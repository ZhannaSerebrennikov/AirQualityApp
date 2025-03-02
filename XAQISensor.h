#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include  <chrono>

//Provided API from the XQAISensor manuacturer
class XAQISensor{
    public:
    XAQISensor();

    bool Connect(std::string connection_data);
    void SetRoomName(std::string room_name);
    std::string RoomName() const;
    int AirQualityIndex() const;

    private:
    std::string m_roomName{};
    bool m_connected {false};
};
