#pragma once
#include "QRScanner.h"
#include "AQISensor.h"

class ConnectionManager{
    private:
    QRScanner qr_scanner;

    public:
    bool Connect(AQISensorConnection&_sensor);
};