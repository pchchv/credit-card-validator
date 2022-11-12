#include <iostream>

using namespace std;

bool isNumberString(const string &s)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main()
{
    string ccNum;

    cout << "You can enter 'exit' anytime to quit." << endl;

    while (true)
    {
        cout << "Please enter a CC number to validate: ";
        cin >> ccNum;

        if (ccNum == "exit")
        {
            break;
        }
        else if (!isNumberString(ccNum))
        {
            cout << "Bad input! ";
            continue;
        }
    }

    return 0;
}