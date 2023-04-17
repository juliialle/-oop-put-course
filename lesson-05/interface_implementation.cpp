#include <iostream>
#include <map>

using namespace std;

class Cantor {
public:
    Cantor() = default;
    virtual ~Cantor() = default;

    virtual double Rate(const std::string& abbreviation) const = 0;
};

class Currency {
public:
    Currency() = default;
    virtual ~Currency() = default;

    virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
    virtual std::string Abbreviation() const = 0;
    virtual double Amount() const = 0;
};

class FakeUsdCantor : public Cantor {
public:
    FakeUsdCantor() {
        // rates_ map with values for ten most popular currencies relative to USD
        rates_ = {
                {"EUR", 0.85},
                {"JPY", 110.66},
                {"GBP", 0.73},
                {"CHF", 0.91},
                {"CAD", 1.25},
                {"AUD", 1.34},
                {"CNY", 6.47},
                {"HKD", 7.78},
                {"NZD", 1.44},
                {"KRW", 1153.89}
        };
    }

    double Rate(const std::string& abbreviation) const override {
        auto it = rates_.find(abbreviation);
        if (it != rates_.end()) {
            return it->second;
        }
        // Handle error case when currency abbreviation is not found
        return 0.0;
    }

private:
    std::map<std::string, double> rates_;
};

class Euro : public Currency {
public:
    string abbreviation;
    double amount;

    Euro(std::string ab, double am);
    double ConvertedToDollars(const Cantor& cantor) const override;
    std::string Abbreviation() const override;
    double Amount() const override;
};

Euro::Euro(std::string ab, double am) {
   abbreviation = ab;
   amount = am;
}

double Euro::ConvertedToDollars(const Cantor &cantor) const {
    double eu = amount;
    return eu / cantor.Rate("EUR"); //rate zwraca wartosc jednego dolara w innej walucie
}

std::string Euro::Abbreviation() const {
    return abbreviation;
}

double Euro::Amount() const {
    return amount;
}

int main() {
    FakeUsdCantor to_usd;
    to_usd.Rate("EUR");
    Euro some_cash("EUR", 50);
    cout << some_cash.Amount();
    cout << " ";
    cout << some_cash.Abbreviation() << endl;
    cout << some_cash.ConvertedToDollars(to_usd);
    cout << " USD";

    return 0;
}

