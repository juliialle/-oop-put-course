#ifndef PROJECT_ACCESSORIES_H
#define PROJECT_ACCESSORIES_H

#include "product.h"

using namespace std;

class Accessories : protected Product {
public:
    Accessories(const std::string &tm, const std::string &nm_pr, double prc, int pr_id, int in_stck);

    virtual ~Accessories();

    string GetDescription() const override;

    int ShowAvailability() const override;

    int ShowId() const override;

    void StockUpdate() override;

    double GivePrice() override;
};

#endif
