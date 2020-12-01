#include <iostream>
#include <string>

using namespace std;

class TextInput
{
protected:
    string str;

public:
    virtual void add(char c)
    {
        str += c;
    }

    std::string getValue() { return str; }
};

class NumericInput : public TextInput
{
    void add(char c)
    {
        if (isdigit(c))
        {
            TextInput::add(c);
        }
    }
};

#ifndef RunTests
int main()
{
    TextInput *input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif