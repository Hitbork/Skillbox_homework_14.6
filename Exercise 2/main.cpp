#include <iostream>

//  Function to show the field
void show_field(char field[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (field[i][j] == ' ') {
                std::cout << '_';
            } else {
                std::cout << field[i][j];
            }
        }
        std::cout << std::endl;
    }
}

// Function to define if there is a winner
bool did_it_win(char field[][3]) {
    if (    // Conditions for rows
            (field[0][0] != ' ' &&(field[0][0] == field[0][1]) && (field[0][1] == field[0][2]) && (field[0][0] == field[0][2])) ||
            (field[1][0] != ' ' &&(field[1][0] == field[1][1]) && (field[1][1] == field[1][2]) && (field[1][0] == field[1][2])) ||
            (field[2][0] != ' ' &&(field[2][0] == field[2][1]) && (field[2][1] == field[2][2]) && (field[2][0] == field[2][2])) ||
            // Conditions for columns
            (field[0][0] != ' ' && (field[0][0] == field[1][0]) && (field[0][0] == field[2][0]) && (field[1][0] == field[2][0])) ||
            (field[0][1] != ' ' && (field[0][1] == field[1][1]) && (field[0][1] == field[2][1]) && (field[1][1] == field[2][1])) ||
            (field[0][2] != ' ' && (field[0][2] == field[1][2]) && (field[0][2] == field[2][2]) && (field[1][2] == field[2][2])) ||
            // Conditions for diagonals
            (field[0][0] != ' ' && (field[0][0] == field[1][1]) && (field[0][0] == field[2][2]) && (field[1][1] == field[2][2])) ||
            (field[0][2] != ' ' && (field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && (field[0][2] == field[2][0]))) {
        return true;
    }

    return false;
}

int main() {
    // Greetings
    std::cout << "Tic-tac-toe 2.0\n\n\n";


    // Creating array for empty field
    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};


    int amountOfMoves = 0;
    int i, j;
    bool somebodyWon = false;
    bool XWon = false, OWon = false;

    while ((amountOfMoves < 9) && (!somebodyWon)) {
        // Show field before game
        show_field(field);
        std::cout << std::endl;

        // Input coordinates of move
        std::cout << "Input coordinates:\n";
        std::cin >> i >> j;

        // Check if this field is empty
        if (i < 0 || i > 2
                || j < 0 || j > 2
                || (field[i][j] != ' ')) {
            std::cout << "Incorrect coordinates!\n";
            std::cout << "Try again\n\n";
            continue;
        }

        if (amountOfMoves % 2 == 0) {
            field[i][j] = 'X';
        } else {
            field[i][j] = 'O';
        }

        if (amountOfMoves >= 4) {
            somebodyWon = did_it_win(field);

            if (somebodyWon) {
                XWon = field[i][j] == 'X';
                OWon = field[i][j] == 'O';
            }
        }

        std::cout << "\n\n";

        amountOfMoves++;
    }

    std::cout << "\n\n";

    show_field(field);
    std::cout << "\n";

    if (XWon) {
        std::cout << "X won\n";
        return 0;
    }

    if (OWon) {
        std::cout << "O won\n";
        return 0;
    }

    std::cout << "Nobody won";
    return 0;
}
