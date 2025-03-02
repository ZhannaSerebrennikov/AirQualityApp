#pragma once
#include "QRScanner.h"
#include "XAQISensor.h"

class ConnectionManager{
    private:
    QRScanner qr_scanner;

    public:
    bool Connect(XAQISensor&_sensor);
};