#include <iostream>
#include <cmath>


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


// Function to check if line is empty for new ship (axis vertical)
bool are_fields_empty_for_ship_axis_vertical(bool field[][10], int &x1, int &y, int &x2) {
    for (int i = x1; i <= x2; i++) {
        if (field[i][y]) return false;
    }

    return true;
}

// Function to check if line is empty for new ship (axis horizontal)
bool are_fields_empty_for_ship_axis_horizontal(bool field[][10], int &x, int &y1, int &y2) {
    for (int i = y1; i <= y2; i++) {
        if (field[x][i]) return false;
    }

    return true;
}


// Function to fill empty fields with ships more than 1 cell (axis vertical)
void fill_fields_with_ship_axis_vertical(bool field[][10], int &x1, int &y, int &x2) {
    for (int i = x1; i <= x2; i++) {
        field[i][y] = true;
    }
}


// Function to fill empty fields with ships more than 1 cell (axis horizontal)
void fill_fields_with_ship_axis_horizontal(bool field[][10], int &x, int &y1, int &y2) {
    for (int i = y1; i <= y2; i++) {
        field[x][i] = true;
    }
}


// Overload function to check if current coordinates are right
bool are_coordinates_right(bool field[][10], int &x1, int &y1, int &x2, int &y2, int amount_of_fields) {
    if ((x1 < 0 || x1 > 9) ||
            (y1 < 0 || y1 > 9) ||
            (x2 < 0 || x2 > 9) ||
            (y2 < 0 || y2 > 9)) {
        return false;
    }

    if (!(((abs(x1-x2) == amount_of_fields - 1) && (y2-y1 == 0)) ||
            ((abs(y1-y2) == amount_of_fields - 1) && (x2-x1 == 0)))) {
        return false;
    }

    if (x2-x1 > 0) {
        return are_fields_empty_for_ship_axis_vertical(field, x1, y1, x2);
    } else if (x1-x2 > 0) {
        return are_fields_empty_for_ship_axis_vertical(field, x2, y1, x1);
    } else if (y2-y1 > 0) {
        return are_fields_empty_for_ship_axis_horizontal(field, x1, y1, y2);
    } else {
        return are_fields_empty_for_ship_axis_horizontal(field, x1, y2, y1);
    }
}


// Function to check how correct input ships more than 1 cell
void correct_input_of_ships(bool field[][10], int &x1, int &y1, int &x2, int &y2) {
    if (x2-x1 > 0) {
        fill_fields_with_ship_axis_vertical(field, x1, y1, x2);
    } else if (x1-x2 > 0) {
        fill_fields_with_ship_axis_vertical(field, x2, y1, x1);
    } else if (y2-y1 > 0) {
        fill_fields_with_ship_axis_horizontal(field, x1, y1, y2);
    } else {
        fill_fields_with_ship_axis_horizontal(field, x1, y2, y1);
    }
}


// Function to input ships on 1 cell on the field
void input_ships_1_cell(bool field[][10]) {
    int x, y, counter = 0;

    while (counter < 4) {
        std::cout << "Input coordinates of " << counter+1 << " ship on 1 cell:\n";
        std::cout << "[x] [y]\n";
        std::cin >> x >> y;
        std::cout << "\n";

        if (!are_coordinates_right(field, x, y)) {
            std::cout << "Coordinates are wrong.\n";
            std::cout << "Try again!\n\n";
            continue;
        }

        field[x][y] = true;
        counter++;
    }
}


// Function to input ships on 2 cells on the field
void input_ships_2_cells(bool field[][10]) {
    int x1, y1, x2, y2, counter = 0;

    while (counter < 3) {
        std::cout << "Input coordinates of " << counter+1 << " ship on 2 cells:\n";
        std::cout << "[x1] [y1] [x2] [y2]\n";
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << "\n";

        if (!are_coordinates_right(field, x1, y1, x2, y2, 2)) {
            std::cout << "Coordinates are wrong.\n";
            std::cout << "Try again!\n\n";
            continue;
        }

        correct_input_of_ships(field, x1, y2, x2, y2);
        counter++;
    }
}


// Function to input ships on 3 cells on the field
void input_ships_3_cells(bool field[][10]) {
    int x1, y1, x2, y2, counter = 0;

    while (counter < 2) {
        std::cout << "Input coordinates of " << counter+1 << " ship on 3 cells:\n";
        std::cout << "[x1] [y1] [x2] [y2]\n";
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << "\n";

        if (!are_coordinates_right(field, x1, y1, x2, y2, 3)) {
            std::cout << "Coordinates are wrong.\n";
            std::cout << "Try again!\n\n";
            continue;
        }

        correct_input_of_ships(field, x1, y2, x2, y2);
        counter++;
    }
}


// Function to input ships on 4 cells on the field
void input_ship_4_cells(bool field[][10]) {
    int x1, y1, x2, y2;
    bool input_correct = false;

    while (!input_correct) {
        std::cout << "Input coordinates of ship on 4 cells:\n";
        std::cout << "[x1] [y1] [x2] [y2]\n";
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << "\n";

        if (!are_coordinates_right(field, x1, y1, x2, y2, 4)) {
            std::cout << "Coordinates are wrong.\n";
            std::cout << "Try again!\n\n";
            continue;
        }

        correct_input_of_ships(field, x1, y2, x2, y2);
        input_correct = true;
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
    std::cout << "Player 1!\n";
    std::cout << "Fill field with ships:\n\n";
    fill_fields_with_ships(field_1);

    std::cout << "Player 2!\n";
    std::cout << "Fill field with ships:\n\n";
    fill_fields_with_ships(field_2);




}
