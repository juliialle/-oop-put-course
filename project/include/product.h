#ifndef PROJECT_PRODUCT_H
#define PROJECT_PRODUCT_H
#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string team;
    string name_product;
    double price{};
    int product_id{};
    int in_stock{};
public:
    Product() = default;

    virtual ~Product() = 0;

    virtual string GetDescription() const = 0;

    virtual int ShowAvailability() const = 0;

    virtual int ShowId() const = 0;

    virtual void StockUpdate() = 0;

    virtual double GivePrice() = 0;
};

#endif //PROJECT_PRODUCT_H
