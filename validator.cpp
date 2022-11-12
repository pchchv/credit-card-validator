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

bool validator(string ccNum)
{
    int len = ccNum.length();
    int doubleEvenSum = 0;

    // Double every second digit, starting from the right
    // If the result is a two-digit number,
    // add both digits to get one single-digit number
    // Finally, sum all the answers to obtain 'doubleEvenSum'

    for (int i = len - 2; i >= 0; i -= 2)
    {
        int digit = ((ccNum[i] - 48) * 2);
        if (digit > 9)
        {
            digit = (digit / 10) + (digit % 10);
        }
        doubleEvenSum += digit;
    }

    // Add every odd digit from the right to the 'doubleEvenSum'

    for (int i = len - 1; i >= 0; i -= 2)
    {
        doubleEvenSum += (ccNum[i] - 48);
    }

    // Check if 'doubleEvenSum' is a multiple of 10
    // If yes, it is a valid credit card number

    return doubleEvenSum % 10 == 0 ? true : false;
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
            cout << "Bad input!" << endl;
            continue;
        }

        cout << (validator(ccNum) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}