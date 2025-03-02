#include "XAQISensor.h"

XAQISensor::XAQISensor()
{
    srand(time(NULL));
}

bool XAQISensor::Connect(std::string connection_data)
{
    //the connection data can be taken by QR Scan
    auto password = connection_data.substr(connection_data.length() - 3);
    
    if(password != "123")
    {
        std::cout << "Connection refused: " << connection_data << std::endl;
        return false;
    }
    bool is_sensor_reachable = true;
    if(is_sensor_reachable)
    {
        m_connected = true;
    }
    return true;
}

void XAQISensor::SetRoomName(std::string room_name)
{
    if(m_connected == false)
    {
        return;
    }
    m_roomName = room_name;
}

std::string XAQISensor::RoomName() const
{
    return m_roomName;
}

int XAQISensor::AirQualityIndex() const
{
    if(m_connected == false)
    {
        return -1;
    }
    int air_quallity_index = 10 +rand() % 200;// pseudo-random number between 10 and 209
    return air_quallity_index;
}