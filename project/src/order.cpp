#include <list>
#include "clothes.h"
#include "accessories.h"
#include "cart.h"
#include "order.h"

using namespace std;

void Order::Total(double price) {
    this->total_price += price;
}

void Order::MakeOrder(Cart &cart, int wanted_id, int type_product) { // 1-cloth, 2-accessory
    if (type_product == 1) {
        for (auto &cloth: cart.GetClothes()) {
            if (cloth.ShowId() == wanted_id) {
                order_clothes.push_back(cloth);
                cloth.StockUpdate();
                Total(cloth.GivePrice());
                break;
            }
        }
    } else if (type_product == 2) {
        for (auto &accessory: cart.GetAccessories()) {
            if (accessory.ShowId() == wanted_id) {
                order_accessories.push_back(accessory);
                accessory.StockUpdate();
                Total(accessory.GivePrice());
                break;
            }
        }
    }
}

void Order::ShowOrder() {
    cout << "Order number: " << this->order_id << endl;
    cout << "Your order" << endl;
    for (const auto &cloth: order_clothes) {
        cout << cloth.GetDescription() << endl;
    }
    for (const auto &accessory: order_accessories) {
        cout << accessory.GetDescription() << endl;
    }
    cout << "Total: $" << this->total_price << endl;
}

void Order::OrderDetails() {
    string n, a, m;
    int p;
    cout << "Enter your name: ";
    cin >> n;
    cout << endl;
    cout << "Enter your delivery adress: ";
    cin >> a;
    cout << endl;
    cout << "Choose your payment method:" << endl;
    cout << "1 - PayPal  2 - Credit/debit card" << endl;
    cin >> p;
    if (p == 1) {
        this->payment_method = "PayPal";
    } else if (p == 2) {
        this->payment_method = "Credit/debit card";
    }
    this->name = n;
    this->delivery_adress = a;
    cout << "Entered details: " << endl;
    cout << this->name << endl;
    cout << this->delivery_adress << endl;
    cout << this->payment_method << endl;

    order_accessories.clear();
    order_clothes.clear();
}
