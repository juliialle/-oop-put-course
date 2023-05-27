#ifndef PROJECT_CLOTHES_H
#define PROJECT_CLOTHES_H

#include "product.h"

using namespace std;


class Clothes : protected Product {
    char size;
    string gender;
public:
    Clothes(const std::string &tm, const std::string &nm_pr, double prc, int pr_id, int in_stck, char siz,
            const std::string &gndr);

    ~Clothes() override;

    string GetDescription() const override;

    int ShowAvailability() const override;

    int ShowId() const override;

    void StockUpdate() override;

    double GivePrice() override;
};

#endif
