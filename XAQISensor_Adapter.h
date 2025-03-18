#include "AQISensor.h"
#include "XAQISensor.h"

class XAQISensor_Adapter : public StationaryAQISensor{
    private:
    XAQISensor sensor_;

    public:
    bool Connect(std::string connectionData) override;
    void SetRoomName(std::string roomName) override;
    std::string RoomName() const override;
    std::vector<AQIParameter> GetData() const override;
};