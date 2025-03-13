#include <iostream>
#include <memory>
#include <vector>
#include "AQISensorDisplay.h"
#include "ConnectionManager.h"
#include "XAQISensor_Adapter.h"
#include "JAQISensor_Adapter.h"

int main()
{
    AQISensorDisplay aqi_sensor_display;
    ConnectionManager connection_manager;

    std::vector<std::unique_ptr<AQISensor>> sensors;

    std::unique_ptr<XAQISensor_Adapter> sensor_living_room = std::make_unique<XAQISensor_Adapter>();
    if(connection_manager.Connect(*sensor_living_room))
    {
        sensor_living_room->SetRoomName("LivingRoom");
        sensors.push_back(move(sensor_living_room));
    }

    std::unique_ptr<XAQISensor_Adapter> sensor_bad_room = std::make_unique<XAQISensor_Adapter>();
    if(connection_manager.Connect(*sensor_bad_room))
    {
        sensor_bad_room->SetRoomName("BadRoom");
        sensors.push_back(move(sensor_bad_room));
    }

    std::unique_ptr<JAQISensor_Adapter> sensor_children_room = std::make_unique<JAQISensor_Adapter>();
    if(connection_manager.Connect(*sensor_children_room))
    {
        sensor_children_room->SetRoomName("ChildrenRoom");
        sensors.push_back(move(sensor_children_room));
    }

    std::unique_ptr<JAQISensor_Adapter> sensor_office = std::make_unique<JAQISensor_Adapter>();
    if(connection_manager.Connect(*sensor_office))
    {
        sensor_office->SetRoomName("Office");
        sensors.push_back(move(sensor_office));
    }

    for(const auto& sensor : sensors)
    {
        aqi_sensor_display.RenderParameters(*sensor);
    }

    return 0;
}