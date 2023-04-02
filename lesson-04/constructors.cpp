#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class User {
public:
    User(char const *ptr);
private:
    char *login;
    size_t sizeOflogin;
};

User::User(char const *ptr) {
    sizeOflogin = strlen(ptr) + 1;
    login = new char[sizeOflogin];
    if(login)
        strcpy(login, ptr);
}

class Pin {
private:
    int number;
public:
    int ForgottenPin() { return this->number; };
    Pin() {this->number = 1234; }
    Pin(int nr) {this->number = nr; };
    Pin(double nr) : Pin(static_cast<int>(nr)) {};
    Pin(float nr) : Pin(static_cast<int>(nr)) {};
    Pin(std::string nr) : Pin(std::stod(nr)) {};
};

int main() {
    User newUser("JohnP");
    Pin assignedPin(4822);
    cout << "Your PIN is: ";
    cout << assignedPin.ForgottenPin() << endl;
}
