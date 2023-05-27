#include "product.h"
#include "accessories.h"

using namespace std;

Accessories::Accessories(const std::string &tm, const std::string &nm_pr, double prc, int pr_id, int in_stck) {
    this->team = tm;
    this->name_product = nm_pr;
    this->price = prc;
    this->product_id = pr_id;
    this->in_stock = in_stck;
}

Accessories::~Accessories() = default;

string Accessories::GetDescription() const {
    return "Team: " + team + ", Product Name: " + name_product + ", Price: $" + to_string(price) + ", ID: " +
           to_string(product_id);
}

int Accessories::ShowAvailability() const {
    return this->in_stock;
}

int Accessories::ShowId() const {
    return this->product_id;
}

void Accessories::StockUpdate() {
    in_stock--;
}

double Accessories::GivePrice() {
    return this->price;
}