#include <iostream>
#include <limits>

using namespace std;

// all the functions used in this program
void Calc(void);
int menu(void);
double addNumbers(double num1, double num2);
double subtractNumbers(double num1, double num2);
double multiplyNumbers(double num1, double num2);
double divideNumbers(double num1, double num2);

int main()
{
    // function call for calculator
    Calc();
    return 0;
}

/* function to Calculate simple operations such as addition subtraction multiplication and division*/

void Calc(void)
{
    int operation;

    do
    {

        double num1, num2;

        // function to menu for selectiing operations;
        operation = menu();

        switch (operation)
        {
        case 1:
            cout << endl
                 << "\t\tEnter Two Numbers: ";

            // error handing for if the user enters a character instead of integer:
            while (!(cin >> num1 && cin >> num2))
            {
                cout << endl
                     << "\t\tInvalid Input. Enter Numbers again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << endl
                 << "\t\tAddition of Numbers is: " << addNumbers(num1, num2);
            break;

        case 2:
            cout << endl
                 << "\t\tEnter Two Numbers: ";

            // error handing for if the user enters a character instead of integer:
            while (!(cin >> num1 && cin >> num2))
            {
                cout << endl
                     << "\t\tInvalid Input. Enter Numbers again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << endl
                 << "\t\tSubtraction of Numbers is: " << subtractNumbers(num1, num2);
            break;

        case 3:
            cout << endl
                 << "\t\tEnter Two Numbers: ";

            // error handing for if the user enters a character instead of integer and if the denominator is 0
            while (!(cin >> num1 && cin >> num2))
            {
                cout << endl
                     << "\t\tInvalid Input. Enter Numbers again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << endl
                 << "\t\tMultiplication of Numbers is: " << multiplyNumbers(num1, num2);

            break;

        case 4:
            cout << endl
                 << "\t\tEnter Two Numbers: ";

            // error handing for if the user enters a character instead of integer:
            while (!(cin >> num1 && cin >> num2) || (num2 == 0))
            {
                cout << endl
                     << "\t\tInvalid Input. Enter Numbers again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << endl
                 << "\t\tDivision of Numbers is: " << divideNumbers(num1, num2);
            break;

        default:
            if (operation == 5)
            {
                break;
            }
            cout << endl
                 << "\t\tInvalid Input";
            cout << endl
                 << "\t\tTry Again";
        }
    } while (operation != 5);
}

// function for showing menu and selection from the menu

int menu(void)
{
    int opt;
    cout << endl
         << "\t\t     ---- Calculate Simple ----";

    cout << endl
         << "\t\t1.Addition\t\t2.Subtraction\n";
    cout << endl
         << "\t\t3.Multiplication\t4.Division\n"
         << "\n\t\t\t     5.exit()";

    cout << endl
         << "\t\tSelect from the above list(1-5): ";

    // error handing for if the user enters a character instead of integer:
    while (!(cin >> opt))
    {
        cout << endl
             << "\t\tInvalid Input. Please select from the list: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return opt;
}

// function for addition operation

double addNumbers(double num1, double num2)
{
    return num1 + num2;
}

// function for subtraction operation

double subtractNumbers(double num1, double num2)
{
    return num1 - num2;
}

// function for multiplication operation

double multiplyNumbers(double num1, double num2)
{
    return num1 * num2;
}

// function for division operation

double divideNumbers(double num1, double num2)
{
    return num1 / num2;
}
