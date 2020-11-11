#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {

        string result = "";

        int sum = 0;
        int positionA = a.length() - 1;
        int positionB = b.length() - 1;

        while ((positionA >= 0 && positionB >= 0) || sum == 1)
        {
            sum += positionA >= 0 ? a[positionA--] - '0' : 0;
            sum += positionB >= 0 ? b[positionB--] - '0' : 0;

            result = (char)(sum % 2 + '0') + result;

            sum /= 2;
        }

        return result;
    }
};

int main(void)
{
    Solution s;
    cout << s.addBinary("1", "1");
    return 1;
}