#include <iostream>
#include <time.h>
#include <limits>
#include <cstdlib>
using namespace std;

// functions used in this program
int randomNum(void);

// Main function
int main()
{
    int random = randomNum();
    int guess;

    cout << endl
         << endl
         << endl
         << "--- Welcome to Guessing Game ---";

    do
    {
        cout << endl
             << endl
             << "Enter your Guess (1-100): ";

        // this is implemented for handling typos
        while (!(cin >> guess))
        {
            cout << endl
                 << endl
                 << endl
                 << "--- Invalid Input ---";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (guess > random)
        {
            cout << endl
                 << endl
                 << endl
                 << "Guess is higher. Enter a little low: ";
        }
        else if (guess < random)
        {
            cout << endl
                 << endl
                 << endl
                 << "Guess is lower. Enter a little higher: ";
        }
        else
        {
            cout << endl
                 << endl
                 << endl
                 << "--- Hurrah! You Guessed it ---";
            cout << endl
                 << endl
                 << endl
                 << "--- Play Again? ---";
            cout << endl
                 << endl
                 << endl
                 << "Enter -1 to exit or Any Number to continue: ";

            // this is implemented for handling typos
            while (!(cin >> guess))
            {
                cout << endl
                     << endl
                     << endl
                     << "--- Invalid Input ---";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (guess == -1)
            {
                break;
            }
        }
    } while (true);

    return 0;
}

// a function which generates a random number
int randomNum(void)
{
    srand(time(0));
    int random = rand() % 100 + 1;
    return random;
}
