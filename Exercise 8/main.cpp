#include <iostream>

// Function to fill empty fields
void fill_empty_field(bool field[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[i][j] = false;
        }
    }
}

// Function to check if current coordinates are right
bool are_coordinates_right(bool field[][10], int &x, int &y) {
    if ((x < 0 || x > 9) ||
            (y < 0 || y > 9)) {
        return false;
    }

    if (field[x][y]) {
        return false;
    }

    return true;
}

// Function to input ships on 1 cell on the field
void input_ships_1_cell(bool field[][10]) {
    int x, y;

    for (int i = 0; i < 4; i++) {
        std::cout << "Input coordinates of " << i+1 << " ship on 1 cell:\n";
        std::cout << "[x] [y]\n";
        std::cin >> x >> y;
        std::cout << "\n";

        if (are_coordinates_right(field, x, y)) {

        }

    }
}

// Function to fill fields with ships
void fill_fields_with_ships(bool field[][10]) {
    std::cout << "Fill field with ships on 1 cell:\n\n";
    input_ships_1_cell(field);

    std::cout << "Fill field with ships on 2 cells:\n\n";
    input_ships_2_cells(field);

    std::cout << "Fill field with ships on 3 cells:\n\n";
    input_ships_3_cells(field);

    std::cout << "Fill field with ship on 4 cells:\n\n";
    input_ship_4_cells(field);
}


int main() {
    // Greetings
    std::cout << "\nSea battle 0.5\n\n\n";


    // Creating vars for fields
    bool field_1[10][10], field_2[10][10];

    fill_empty_field(field_1);
    fill_empty_field(field_2);


    // Filling fields with ships

}
