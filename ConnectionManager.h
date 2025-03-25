#pragma once
#include "QRScanner.h"
#include "AQISensor.h"

class ConnectionDataProvider{
    public:
    virtual std::string GetData() const = 0;
};

class ConnectionManager{
    private:
    ConnectionDataProvider& connection_data_provider_;

    public:
    ConnectionManager(ConnectionDataProvider& connection_data_provider);
    bool Connect(AQISensorConnection&_sensor);
};