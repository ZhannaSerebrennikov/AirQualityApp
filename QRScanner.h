#pragma once
#include <iostream>
#include <string>
#include  <chrono>

class QRScanner : public ConnectionDataProvider{
    public:
    QRScanner();
    std::string GetData()const;
};