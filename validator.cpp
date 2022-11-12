#include <iostream>

using namespace std;

int main()
{
    string ccNum;

    cout << "You can enter 'exit' anytime to quit." << endl;

    while (true)
    {
        cout << "Please enter a CC number to validate: ";
        cin >> ccNum;

        if (ccNum == "exit")
            break;
    }

    return 0;
}