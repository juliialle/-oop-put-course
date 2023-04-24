#include<iostream>
#include<memory>
#include<sstream>

class Sequence {
public:
    virtual int length() = 0;
};

class FakeSequence : public Sequence {
public:
    int length() override { return 100; }
};

class Gene {
private:
    std::string name_;
    std::shared_ptr<Sequence> sequence_;
public:
    Gene(std::string name, std::shared_ptr<Sequence> sequence) :
            sequence_(sequence), name_(name) {};
    std::string JSON() {
        std::stringstream ss; // umożliwia sklejanie kolejne łańcuchy znaków

        ss << "{" << "\"name\": \"," << "\":" << sequence_->length() << "}";
        return ss.str();
    }
};
int main()
{
    std::shared_ptr<Sequence> fake_seq = std::make_shared<FakeSequence>();
    Gene gene("BALF5", fake_seq);
    std::cout << gene.JSON() << std::endl;
    assert(fake_seq->length() == 100); // rzecz dodatkowa  // wymagane fake class i jego implementacja
    return 0;


}
