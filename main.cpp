#include <iostream>
#include <memory>
#include <vector>
#include "AQISensorDisplay.h"
#include "ConnectionManager.h"

int main()
{
    AQISensorDisplay aqi_sensor_display;
    ConnectionManager connection_manager;

    std::vector<std::unique_ptr<XAQISensor>> sensors;

    std::unique_ptr<XAQISensor> sensor_living_room = std::make_unique<XAQISensor>();
    if(connection_manager.Connect(*sensor_living_room))
    {
        sensor_living_room->SetRoomName("LivingRoom");
        sensors.push_back(move(sensor_living_room));
    }


    std::unique_ptr<XAQISensor> sensor_bad_room = std::make_unique<XAQISensor>();
    if(connection_manager.Connect(*sensor_bad_room))
    {
        sensor_bad_room->SetRoomName("BadRoom");
        sensors.push_back(move(sensor_bad_room));
    }

    for(const auto& sensor : sensors)
    {
        aqi_sensor_display.RenderParameters(*sensor);
    }

    return 0;
}