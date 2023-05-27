#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H

#include <list>
#include "clothes.h"
#include "accessories.h"
#include "cart.h"

using namespace std;

class Order : protected Cart {
    int order_id;
    double total_price;
    list<Clothes> order_clothes;
    list<Accessories> order_accessories;
    string payment_method;
    string delivery_adress;
    string name;
public:
    Order() = default;

    Order(int nr, int prc) {
        order_id = nr;
        total_price = prc;
    }

    void MakeOrder(Cart &cart, int wanted_id, int type_product);

    void ShowOrder();

    void OrderDetails();

    void Total(double price);
};

#endif
