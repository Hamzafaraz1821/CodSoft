#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Board
{
public:
    Board()
    {
        // Initialize the board with empty cells
        board = vector<vector<char>>(3, vector<char>(3, '.'));
    }

    // Function to print the board
    void printAll()
    {
        cout << "   0 | 1 | 2 " << endl;
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i << " ";
            for (int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " ";
                if (j < 2)
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "-------------" << endl;
        }
    }

    // Place a character on the board at the specified position
    bool placeCharacter(int row, int column, char sign)
    {
        if (board[row][column] != '.')
        {
            cout << "Place already occupied";
            return false;
        }
        board[row][column] = sign;
        return true;
    }

    // Check if the board is full, indicating a draw
    bool checkDraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '.')
                {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if a player has won
    bool checkWin(char sign)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == sign && board[i][1] == sign && board[i][2] == sign)
                return true;
            if (board[0][i] == sign && board[1][i] == sign && board[2][i] == sign)
                return true;
        }
        if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign)
            return true;
        if (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)
            return true;
        return false;
    }

private:
    vector<vector<char>> board;
};

class Player
{
public:
    Player(const string &name, char character, Board &board) : name(name), character(character), gameBoard(board) {}

    // Perform the player's turn
    bool playTurn()
    {

        int row, column;
        cout << endl
             << name << "'s turn" << endl;

        // Get valid row and column inputs
        row = getValidInput("Enter row (0-2): ", 0, 2);
        column = getValidInput("Enter column (0-2): ", 0, 2);

        if (gameBoard.placeCharacter(row, column, character))
        {
            gameBoard.printAll();
            return true;
        }
        else
        {
            cout << endl
                 << "Cell already occupied. Try again." << endl;
            return false;
        }
    }

    // Check if the player has won
    bool checkWin()
    {
        if (gameBoard.checkWin(character))
        {
            cout << endl
                 << name << " Wins!" << endl;
            return true;
        }
        return false;
    }

private:
    string name;
    char character;
    Board &gameBoard;

    // Get valid input within a specified range
    int getValidInput(const string &prompt, int min, int max)
    {
        int input;
        while (true)
        {
            cout
                << prompt;
            if (cin >> input && input >= min && input <= max)
                break;
            cout << "Invalid input. Please enter a valid number between " << min << " and " << max << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return input;
    }
};

// Get a valid character choice (X or O)
char getValidCharacter(const string &prompt, char excludedChar = '\0')
{
    char character;
    while (true)
    {
        cout << endl
             << prompt;
        cin >> character;

        character = toupper(character);
        if (character == 'X' || character == 'O')
        {
            if (character != excludedChar)
                break;
            else
                cout << endl
                     << endl
                     << "This character is already taken. Please choose a different one." << endl;
        }
        else
        {
            cout << endl
                 << endl
                 << "Invalid character. Please choose 'X' or 'O'." << endl;
        }
    }
    return character;
}

int main()
{
    Board gameBoard;

    string name;
    char character;

    cout << "--- Welcome to Tic-Tac-Toe ---" << endl;

    cout << "Player 1 Name: ";
    getline(cin, name);

    character = getValidCharacter("Player 1, choose your character (X/O): ");
    Player player1(name, character, gameBoard);

    cout << endl
         << "Player 2 Name: ";
    cin.ignore();
    getline(cin, name);

    character = getValidCharacter("Player 2, choose your character (X/O): ", character);
    Player player2(name, character, gameBoard);

    Player *currentPlayer = &player1;
    Player *opponent = &player2;

    gameBoard.printAll();

    while (true)
    {
        if (currentPlayer->playTurn())
        {
            if (currentPlayer->checkWin())
                break;

            if (gameBoard.checkDraw())
            {
                cout << "Game is a draw!" << endl;
                break;
            }

            swap(currentPlayer, opponent);
        }
    }

    return 0;
}
