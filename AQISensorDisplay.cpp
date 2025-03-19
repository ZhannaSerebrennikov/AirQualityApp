#include "AQISensorDisplay.h"

void AQISensorDisplay::renderAirQualityIndex(std::string roomName, int airQualityIndex) const
{
    std::cout <<"\n";

    //set the output collor
    if(airQualityIndex<=50)
    {
        std::cout << "\033[32m"; // set output to green
    } 
    else if (airQualityIndex <= 150) 
    {
        std::cout << "\033[33m"; // set output to yellow
    } 
    else 
    {
        std::cout << "\033[31m"; // set output to red
    }
                        // print the AQI
    std::cout << std::left << std::setw(10) << roomName << " : AQI  "
    << airQualityIndex;

    if (airQualityIndex > 150) 
    {
        std::cout << "  - Open a window!";
    }     
    std::cout << "\033[0m" << std::endl; // default output colour

}

void AQISensorDisplay::renderAdditionalParameters(std::string paramName, int value, std::string unit) const
{

    std::cout << "\n" << "             " << std::left << std::setw(13) << paramName

    << std::left << std::setw(6) << value

    << std::left << unit;
}


void AQISensorDisplay::RenderParameters(const AQISensorInformation& sensor_, bool showDetails_) const
{
    std::cout<<"\n";
    std::vector<AQIParameter> sensor_data = sensor_.GetData();
    auto air_quality_index_parameter = sensor_data.front();
    if(air_quality_index_parameter.name == "AQI")
    {
        renderAirQualityIndex(sensor_.RoomName(), air_quality_index_parameter.value);
    }
    else{
        std::cout<<"Wrong Data formatting.\n\n";
    }
    if(showDetails_)
    {
        for (auto parameter_iterator = sensor_data.begin() + 1; parameter_iterator != sensor_data.end(); ++parameter_iterator)
        {
            renderAdditionalParameters(parameter_iterator->name, parameter_iterator->value, parameter_iterator->unit);
        }
    }
}