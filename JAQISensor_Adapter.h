#include "AQISensor.h"
#include "JAQISensor.h"
#include "AQIJSONParser.h"

class JAQISensor_Adapter : public AQISensor{
    private:
    JAQISensor sensor_;
    AQIJSONParser parser_;
    
    public:
    bool Connect(std::string connectionData) override;
    void SetRoomName(std::string roomName) override;
    std::string RoomName() const override;
    std::vector<AQIParameter> GetData() const override;
};