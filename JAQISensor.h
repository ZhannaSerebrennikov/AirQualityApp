#include <iostream>

class JAQISensor{
    public:
    JAQISensor();

    bool Connect(std::string connection_data);
    void SetRoomName(std::string room_name);
    std::string RoomName() const;
    std::string jsonData() const;

    private:
    std::string room_name_{};
    bool connected_{false};
};