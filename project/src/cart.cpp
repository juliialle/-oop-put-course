#include <iostream>
#include <list>
#include "clothes.h"
#include "accessories.h"
#include "cart.h"

using namespace std;

std::list<Clothes> &Cart::GetClothes() {
    return list_of_clothes;
}

std::list<Accessories> &Cart::GetAccessories() {
    return list_of_accessories;
}

void Cart::AddCloth(Clothes &cloth) {
    this->list_of_clothes.push_back(cloth);
}

void Cart::AddAccessory(Accessories &accessory) {
    this->list_of_accessories.push_back(accessory);
}

void Cart::ShowCart(Cart &cart) {
    cout << "Clothes in the cart:" << endl;
    for (const auto &cloth: cart.GetClothes()) {
        cout << cloth.GetDescription() << endl;
    }

    cout << "Accessories in the cart:" << endl;
    for (const auto &accessory: cart.GetAccessories()) {
        cout << accessory.GetDescription() << endl;
    }
}