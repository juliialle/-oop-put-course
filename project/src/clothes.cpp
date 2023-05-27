#include <string>
#include <list>
#include "product.h"
#include "clothes.h"

using namespace std;

Clothes::Clothes(const std::string &tm, const std::string &nm_pr, double prc, int pr_id, int in_stck, char siz,
                 const std::string &gndr) {
    this->team = tm;
    this->name_product = nm_pr;
    this->price = prc;
    this->product_id = pr_id;
    this->in_stock = in_stck;
    this->size = siz;
    this->gender = gndr;
}

Clothes::~Clothes() = default;

string Clothes::GetDescription() const {
    return "Team: " + team + ", Product Name: " + name_product + ", Details: " + gender + " " + size + ", Price: $" +
           to_string(price) + ", ID: " +
           to_string(product_id);
}

int Clothes::ShowAvailability() const {
    return this->in_stock;
}

int Clothes::ShowId() const {
    return this->product_id;
}

void Clothes::StockUpdate() {
    in_stock--;
}

double Clothes::GivePrice() {
    return this->price;
}
