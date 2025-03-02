#include "AQISensorDisplay.h"

void AQISensorDisplay::RenderParameters(const XAQISensor& sensor)
{
        int air_quality_index = sensor.AirQualityIndex();

        //set the output collor
        if(air_quality_index<=50)
        {
            std::cout << "\033[32m"; // set output to green
        } 
        else if (air_quality_index <= 150) 
        {
            std::cout << "\033[33m"; // set output to yellow
        } 
        else 
        {
            std::cout << "\033[31m"; // set output to red
        }
                    // print the AQI
        std::cout << std::left << std::setw(10) << sensor.RoomName() << " : AQI  "
                 << air_quality_index;

        if (air_quality_index > 150) 
        {
            std::cout << "  - Open a window!";
        }     
        std::cout << "\033[0m" << std::endl; // default output colour
}
