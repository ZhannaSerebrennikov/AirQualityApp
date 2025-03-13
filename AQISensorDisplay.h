#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "AQISensor.h"

class AQISensorDisplay{
    private:
    void renderAirQualityIndex(std::string roomName, int airQualityIndex) const;
    void renderAdditionalParameters(std::string paramName, int value, std::string unit) const;
    public:
    void RenderParameters(const AQISensor& sensor_, bool showDetails_ = true) const;
};