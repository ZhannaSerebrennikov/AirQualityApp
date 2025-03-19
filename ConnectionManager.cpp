#include "ConnectionManager.h"

bool ConnectionManager::Connect(AQISensorConnection& _sensor)
{
    auto connection_data = qr_scanner.GetData();
    return _sensor.Connect(connection_data);
}