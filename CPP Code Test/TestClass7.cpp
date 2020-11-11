#include <iostream>
using namespace std;

struct Base
{
    Base()
    {
        cout << "base" << endl;
    }
    virtual void execute() = 0;
    virtual ~Base(){};
};

class Derived : public Base
{
public:
    Derived(int a, int b) : mA(a), mB(b), mR(0)
    {
        cout << "derived" << endl;
    }

    int getResult() const { return mR; }

    void execute() override { mR = mA + mB; }

private:
    int mA, mB, mR;
};

int main(int argc, char *argv[])
{
    Base *derived = new Derived(1, 2);
    derived->execute();
    return 0;
} //