#include <iostream>

// Function to check right of indexes
bool check_of_indexes(int &x1, int &y1, int &x2, int &y2) {
    if (((x1 < 0) || (x1 > 11))
        || ((y1 < 0) || (y1 > 11))
        || ((x2 < 0) || (x2 > 11))
        || ((y2 < 0) || (y2 > 11))) {
        return false;
    }

    return true;
}


// Function for showing pimples
void show_pimples(bool pimples[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (pimples[i][j]) {
                std::cout << "o";
            } else {
                std::cout << "x";
            }
        }

        std::cout << "\n";
    }
    std::cout << "\n";
}


// Function for cracking pimples
void crack(bool pimples[][12], int &counter, int &x1, int &y1, int &x2, int &y2) {
    std::cout << "\n";

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (pimples[i][j]) {
                pimples[i][j] = false;
                counter++;
                std::cout << "Pop!\n";
            }
        }
    }

    std::cout << "\n";
}


int main() {
    // Greetings
    std::cout << "\nPimples\n\n\n";


    // Creating var for pimples statuses
    bool pimples[12][12];

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            pimples[i][j] = true;
        }
    }


    //
    int counter = 0, x1, x2, y1, y2;
    while (counter < 144) {
        show_pimples(pimples);

        std::cout << "Insert indexes of field to pop:\n";
        std::cout << "[x1] [y1] [x2] [y2]\n";
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (check_of_indexes(x1, y1, x2, y2)) {
            crack(pimples, counter, x1, y1, x2, y2);
        } else {
            std::cout << "Wrong indexes of field!\n";
            std::cout << "Try again!\n\n";
        }
    }

    std::cout << "\nAll pimples are popped now!\n";
}
