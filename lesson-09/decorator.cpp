#include <iostream>
#include <vector>
using namespace std;

class IntegerSequence {
public:
    virtual ~IntegerSequence() = default;
    virtual vector<int> Numbers() = 0;
};

class VectorSequence : public IntegerSequence {
public:
    vector<int> Numbers() override {
        vector<int> a;
        return a;
    }

    void Read(vector<int> a) {
        for(auto i: a) {
            cout << i << " ";
        }
    }
};

class PositiveSequence : public IntegerSequence {
    vector<int> Numbers() override {
        vector<int> c;
        for (auto it = c.begin(); it != c.end();)
        {
            if (*it < 0)
                it = c.erase(it);
            else
                ++it;
        }
        return c;
    }
};

class EvenSequence : public IntegerSequence {
    vector<int> Numbers() override {
        vector<int> c;
        for (auto it = c.begin(); it != c.end();)
        {
            if (*it % 2 == 1)
                it = c.erase(it);
            else
                ++it;
        }
        return c;
    }
};

class SortedSequence : public IntegerSequence {
    vector<int> Numbers() override {
        vector<int> a;
        sort(a.begin(), a.end());
        return a;
    }
};

int main() {

}