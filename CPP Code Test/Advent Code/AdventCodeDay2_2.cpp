#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(string str, char delimiter)
{
    stringstream ss(str);
    string currStr;
    vector<string> spltStr;

    while (getline(ss, currStr, delimiter))
    {
        spltStr.push_back(currStr);
    }
    return spltStr;
}

string replaceCharacter(string str, char oldChar, char newChar)
{
    size_t found = str.find_first_of(oldChar);

    while (found != string::npos)
    {
        str[found] = newChar;
        found = str.find_first_of(oldChar);
    }

    return str;
}

int main()
{
    fstream myfile("E:\\password.txt", ios_base::in);
    fstream outputfile("E:\\validpassword.txt", ios_base::out);
    string line;

    int validPasword = 0;
    while (getline(myfile, line))
    {
        string currLine = line;
        currLine.erase(remove_if(currLine.begin(), currLine.end(), ::isspace), currLine.end());

        vector<string> sp = splitString(currLine, ':');
        string policy = sp[0];
        string password = sp[1];

        char validChar = policy.back();
        policy.pop_back();
        sp = splitString(policy, '-');

        int pos1 = stoi(sp[0]) - 1;
        int pos2 = stoi(sp[1]) - 1;

        if ((password[pos1] == validChar && password[pos2] != validChar) ||
            (password[pos1] != validChar && password[pos2] == validChar))
        {
            ++validPasword;
            outputfile << pos1 + 1 << " " << pos2 + 1 << " " << validChar << " " << password << endl;
        }
    }

    printf("Valid Password: %d", validPasword);

    myfile.close();
    outputfile.close();

    return 1;
}