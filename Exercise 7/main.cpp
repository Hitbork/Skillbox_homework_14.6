#include <iostream>

// Function to quere data to the dimensonal array
void quering_data(bool array[][5][10]) {
    int temp[5][5];

    std::cout << "Insert matrix of heights:\n";
    for (int i = 0; i < 5;  i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> temp[i][j];
        }
    }

    std::cout << "\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < temp[i][j]; k++) {
                array[i][j][k] = true;
            }

            for (int k = temp[i][j]; k < 10; k++) {
                array[i][j][k] = false;
            }
        }
    }
}


// Function to check number
bool is_right_number(int &number) {
    if (number < 1 || number > 10) {
        return false;
    }

    return true;
}


// Function to output slice
void slice(bool array[][5][10], int &number) {
    std::cout << "Result of slice:\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << array[i][j][number-1] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}


int main() {
    // Greetings
    std::cout << "\nMinecraftIsMyLife = false;\n\n\n";


    // Creating three dimensional array
    bool array[5][5][10];


    // Quering data
    quering_data(array);


    // Endless cycle for slices
    int number;
    while (true) {
        std::cout << "Input slice:\n";
        std::cin >> number;

        std::cout << "\n";

        if (!is_right_number(number)) {
            std::cout << "Error! Wrong input.\n";
            std::cout << "Try again!\n\n";
            continue;
        }

        slice(array, number);

        std::cout << "\n";
    }
}
