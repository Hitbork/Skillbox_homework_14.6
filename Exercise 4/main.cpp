#include <iostream>

// Function for multipling matrice on vector
void multipling_matrice_on_vector(float matrice[][4], float vector[], float result[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += (matrice[i][j] * vector[j]);
        }
    }
}


int main() {
    // Greetings
    std::cout << "\nMultiple matrice on vector\n\n\n";


    // Creating var for matrice and quering data for it
    float matrice[4][4];

    std::cout << "Input numbers of matrice:\n";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrice[i][j];
        }
    }


    // Creating var for vector and quering numbers for it
    float vector[4];

    std::cout << "\nInput number of vector:\n";

    for (int i = 0; i < 4; i++) {
        std::cin >> vector[i];
    }


    // Multipling matrice on vector
    float result[4] = {0, 0, 0, 0};
    multipling_matrice_on_vector(matrice, vector, result);


    // Outputing result
    std::cout << "\nResult:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << result[i] << std::endl;
    }
}
