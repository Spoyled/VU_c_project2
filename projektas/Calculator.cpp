#include <iostream>
#include <limits>
#include <cmath>
#include "Calculator.h"

double Calculator::calculate()
{
    clean(0);
    string mainResponse, topicSelection;
    double firstResponse, secondResponse;

    cout << "CHAT BOT: (1) Please choose: " << endl << "Multiplication" << endl << "Division" << endl << "Addition" << endl << "Substraction" << endl << "Root" << endl << endl;
    cout << username << ": "; cin >> topicSelection;

    if (topicSelection == "Multiplication" || topicSelection == "Division" || topicSelection == "Addition" || topicSelection == "Substraction")
    {
        cout << endl << "CHAT BOT: (2)Please type your first number: " << endl;
        cout << username << ": ";
        while (!(cin >> firstResponse))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "CHAT BOT: Please enter a valid number: ";
        }

        cout << "CHAT BOT: Please enter the second number: " << endl;
        cout << username << ": ";

        while (true)
        {
            while (!(cin >> secondResponse))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "CHAT BOT: Please enter a valid number: ";
            }

            if (topicSelection == "Division" && secondResponse == 0)
            {
                cout << "CHAT BOT: Cannot divide by zero. Please enter a non-zero number: " << endl;
                cout << username << ": ";
            }
            else
                break;
        }
    }
    
    else if (topicSelection == "Root")
    {
        cout << "CHAT BOT: (2)Please type your number: " << endl;
        cout << username << ": ";
        while (true)
        {
            while (!(cin >> firstResponse))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "CHAT BOT: Please enter a valid number: ";
            }

            if (firstResponse < 0)
            {
                cout << "CHAT BOT: Cannot take root from negative numbers. Please enter a non negative number: " << endl;
                cout << username << ": ";
            }
            else
                break;
        }
    }

    else
    {
        cout << "CHAT BOT: I didn't understand your Input... Please try again." << endl;
        calculate();
    }

    double result;

    if (topicSelection == "Multiplication")
        result = firstResponse * secondResponse;
    
    else if (topicSelection == "Division")
        result = firstResponse / secondResponse;
    
    else if (topicSelection == "Addition")
        result = firstResponse + secondResponse;
    
    else if (topicSelection == "Substraction")
        result = firstResponse - secondResponse;

    else if (topicSelection == "Root")
        result = sqrt(firstResponse);

    cout << "\n" << endl;

    return result;
}

void Calculator::clean(int time) {
    _sleep(time);
    system("cls");
}

Calculator::Calculator(string _username)
{
    username = _username;
}