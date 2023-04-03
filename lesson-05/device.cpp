#pragma once
#include <string>
#include <sstream>

class Device {
public:
    Device() {};
    virtual ~Device(){}
    virtual Device *SerialNumber(int id) = 0;
    virtual std::string Number() = 0;
};

class Computer : public Device {
public:
    Computer *SerialNumber(int id) override;
    std::string Number() override;
    explicit Computer(int password);
private:
    int password;
};

std::string Computer::Number() {
    std::stringstream stream;
    stream << password;
    std::string s = stream.str();
    return s;
}
Computer *Computer::SerialNumber(int id) {
    Computer *another = new Computer(id * 1);
    return another;
}
Computer::Computer(int password) {this -> password = password; }