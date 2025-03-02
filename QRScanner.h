#pragma once
#include <iostream>
#include <string>
#include  <chrono>

class QRScanner{
    public:
    QRScanner();
    std::string GetData()const;
};