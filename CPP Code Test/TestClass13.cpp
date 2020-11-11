#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        cout << left << hex << showbase << nouppercase << (long long)A << endl;
        cout << setw(15) << dec << right << setfill('_') << showpos << setprecision(2) << fixed << B << endl;
        cout << setprecision(9) << noshowpos << scientific << uppercase << C << endl;
    }
    return 0;
}