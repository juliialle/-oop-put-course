#include <iostream>
#include <list>
using namespace std;

class Product {
    string name_p;
    float price;
    int id_product;
public:
    Product (string nam, float pric, int id) {
        name_p = nam;
        price = pric;
        id_product = id;
    }
    float see_price () { return this->price; }
    virtual ~Product();
};

class Customer {
    string name_c;
    string email;
    int id_customer;
    friend float get_sum();
    friend int get_id();
public:
    Customer (string customer_name, string customer_email, int customer_id) {
        this->name_c = customer_name;
        this->email = customer_email;
        this->id_customer = customer_id;
    }

    void see_total (float get_sum()) {
        cout << get_sum();
    }
};

class Order {
    int id_order;
    float sum;
    list <Product> list_of_products;
public:
    Order (int id) {
        id_order = id;
    }
    void add_product(Product& item, Order& new_order) {
        this->list_of_products.push_back(item);
        this->sum += item.see_price();
    }
    float get_sum() { return sum; }
    int get_id() { return id_order; }

};

int main() {
    Customer john123("John", "johntart@gmail.com", 345);
    Product shirt("Black T-Shirt", 35, 887);
    Product jeans("Blue Straight Jeans", 99, 421);
    Product socks("White Nike Socks", 40, 679);
    Order order_(11);

    order_.add_product(shirt, order_);
    order_.add_product(jeans, order_);
    order_.add_product(shirt, order_);

    // dokonczyc ta funkcje john123.see_total(order_);
}