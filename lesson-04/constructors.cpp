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
    double number;
public:
    Pin(double nr);
    double ForgottenPin() { return this->number; };
};

Pin::Pin(double nr) {
    this -> number = nr;
}

int main() {
    User newUser("JohnP");
    Pin assignedPin(4822);
    cout << "Your PIN is: ";
    cout << assignedPin.ForgottenPin() << endl;
}
