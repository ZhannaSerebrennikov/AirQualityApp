#include "ConnectionManager.h"

ConnectionManager::ConnectionManager(ConnectionDataProvider& connection_data_provider) : connection_data_provider_(connection_data_provider){};

bool ConnectionManager::Connect(AQISensorConnection& _sensor)
{
    auto connection_data = connection_data_provider_.GetData();
    return _sensor.Connect(connection_data);
}