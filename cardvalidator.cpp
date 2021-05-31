/*
	@author https://github.com/Butterski
	@create date 2021-05-30 22:52:53
	@modify date 2021-05-31 13:33:14
	@desc with this program you can easly validate your cc number or generate fake cc number
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
//check if all characters are numbers
bool isNumber(const string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return true;
    }
    return false;
}
//validating cc number using Luhn Algorithm https://en.wikipedia.org/wiki/Luhn_algorithm
bool validate_cc(string ccNumber)
{
    int doubleEvenSum = 0;

    for (int i = ccNumber.length() - 2; i >= 0; i = i - 2)
    {
        int dbl = ((ccNumber[i] - 48) * 2);
        if (dbl > 9)
        {
            dbl = (dbl / 10) + (dbl % 10);
        }
        doubleEvenSum += dbl;
    }

    for (int i = ccNumber.length() - 1; i >= 0; i = i - 2)
    {
        doubleEvenSum += (ccNumber[i] - 48);
    }

    if (doubleEvenSum % 10 == 0)
        return true;
    else
        return false;
}

// since im lazy and stupid im gonna generate random numbers and validate it :)
string gen_cc_number()
{
    srand(time(NULL));
    bool want = true;
    bool not_found = true;
    string yes_no;

    while (not_found)
    {
        string str_randomCCNumber = "";

        for (int i = 0; i < 4; i++)
        {
            int temp = (rand() % 8999 + 1000);
            str_randomCCNumber += to_string(temp);
        }

        if (validate_cc(str_randomCCNumber))
        {
            cout << str_randomCCNumber << endl;
            cout << endl;
            not_found = false;
        }
    }
    return "";
}

int main()
{
    bool running = true;
    string ccNumber;
    string option;

    while (running)
    {
        cout << "1 - Validate CC Number" << endl;
        cout << "2 - Generate CC Number" << endl;
        cout << "3 - Exit" << endl;
        cout << "Option: ";
        cin >> option;
        cout << endl;

        if (option == "1")
        {
            cout << "Enter CC number:";
            cin >> ccNumber;
            if (!isNumber)
                cout << "Bad input" << endl;
            else if (ccNumber.length() <= 12)
                cout << "Number is too short";
            else if (validate_cc(ccNumber))
                cout << "Valid!" << endl;
            else if (!validate_cc(ccNumber))
                cout << "Invalid" << endl;

            cout << endl;
        }

        else if (option == "2")
        {
            cout << "Generating valid CC number..." << endl;
            cout << gen_cc_number();
        }

        else if (option == "3")
        {
            running = false;
        }

        else
        {
            cout << "bad input!" << endl;
        }
        continue;
    }
    return 0;
}
