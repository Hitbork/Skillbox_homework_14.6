#include <iostream>

void output_matrice(float matrice[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << matrice[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


int main() {
    // Greetings
    std::cout << "Are matrices equal?\n\n\n";


    // Creating array for matrice
    float matrice[4][4];

    std::cout << "Input numbers of first matrice:\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrice[i][j];
        }
    }


    // Checking if second matrice is equal
    float temp;

    std::cout << "\n\nInput numbers of second matrice:\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> temp;

            if (temp != matrice[i][j]) {
                std::cout << "\nMatrices are not equal!\n";
                return 1;
            }

            if (i != j) {
                matrice[i][j] = 0;
            }
        }
    }


    // Output diagonal matrice
    std::cout << "\n\nMatrices are equal.\n";
    std::cout << "Cites matrice to diagonal type:\n";
    output_matrice(matrice);
}
