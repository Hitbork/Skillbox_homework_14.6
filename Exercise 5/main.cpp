#include <iostream>

// Function for cracking pimples
void crack(bool pimples[][12], int &counter, int &x1, int &y1, int &x2, int &y2) {

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

        crack(pimples, counter, x1, y1, x2, y2);
    }
}
