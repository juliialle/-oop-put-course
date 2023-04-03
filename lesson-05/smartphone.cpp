#include "device.h"

class Smartphone : public Device {
public:
    Smartphone *SerialNumber(int id) override;
    std::string Number() override;
    explicit Smartphone(int passcode);
private:
    int passcode;
};