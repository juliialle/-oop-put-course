#ifndef PROJECT_CART_H
#define PROJECT_CART_H

#include <list>
#include "clothes.h"
#include "accessories.h"

using namespace std;

class Cart {
protected:
    list<Clothes> list_of_clothes;
    list<Accessories> list_of_accessories;
public:
    Cart() = default;

    list<Clothes> &GetClothes();

    list<Accessories> &GetAccessories();

    static void ShowCart(Cart &cart);

    void AddCloth(Clothes &cloth);

    void AddAccessory(Accessories &accessory);
};

#endif
