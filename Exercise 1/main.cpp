#include <iostream>

int main() {
    // Greetings
    std::cout << "Welcome to the banquet\n\n\n";


    // Creating array for amount of cutlery for each person
    int cutlery[2][6] = {{4, 4, 3, 3, 3, 3},
                       {3, 3, 3, 3, 3, 3}};


    // Creating array for amount of plates for each person
    int plates[2][6] = { {3, 3, 2, 2, 2, 2},
                         {2, 2, 2, 2, 2, 2}};


    // Creating array for amount of chairs for each person
    int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1}};


    // Adding chair for kid
    chairs[0][4]++;


    // The spoon was stolen from 3rd place in 2nd row
    cutlery[1][2]--;


    // VIP-person gave someone the spoon
    cutlery[0][0]--;


    // Waiter took away desert from VIP-person because spoon was given to someone
    plates[0][0]--;

    // I really have no idea how to create text interface for this program, so i decided to not do that
}
