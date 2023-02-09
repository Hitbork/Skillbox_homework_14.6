#include <iostream>

// Function to insert number to serpentine array
void serpentine_insert(int array[][5]) {
    int number = 0, multiplier = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][((4 * i) % 8) + multiplier * j] = number;
            number++;
        }
        multiplier *= -1;
    }
}


// Function to serpentine output array
void output(int array[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


int main() {
    // Greetings
    std::cout << "\nSerpentine passage\n\n\n";


    // Creating array to output it
    int array[5][5];

    serpentine_insert(array);


    // Output
    output(array);
}
