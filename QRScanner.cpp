#include "QRScanner.h"

QRScanner::QRScanner(){
    // init pseudo-random number generator
    srand(time(NULL));
}

std::string QRScanner::GetData() const{
    // Mocking the return of data by scanning the QR Code on the label on the Sensor.
    int random_two_mac_address_digits = rand() % 100;// pseudo-random number between 0 and 99 
    return "00:11:22:33:44:" + std::to_string(random_two_mac_address_digits) + "pwd123";
}