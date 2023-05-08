#include <iostream>
#include <cmath>
#include <stdexcept>

class Logarithm {
private:
    double base_;
    double argument_;
public:
    Logarithm(double base, double argument) {
        if(base_ <= 0 || argument_ <= 0) {
            throw std::invalid_argument("Base and number must be greater than 0!");
        }

        this->base_ = base;
        this->argument_ = argument;
    }

    double Calculate() const {
            return std::log(argument_) / std::log(base_);
    }
};

int main() {
    try {
        Logarithm log(10, 100);
        double result = log.Calculate();
        std::cout << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}