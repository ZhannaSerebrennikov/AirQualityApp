#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "XAQISensor.h"

class AQISensorDisplay{
    public:
    void RenderParameters(const XAQISensor& sensor_);
};