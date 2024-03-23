#include <iostream>
#include <string>

using namespace std;

struct Pokemon {
    string name;
    string type;
    int level;
    Pokemon* next;
};

void displayMenu() {
    cout << "Menu:\n"
         << "1. Type Sorting\n"
         << "2. Catch\n"
         << "3. Inventory Pokémon\n"
         << "4. Build Team\n"
         << "5. Exit\n"
         << "Choose an option: ";
}

void typeSorting() {
    // Implement type sorting functionality here
    cout << "Type Sorting\n";
}

void catchPokemon(Pokemon*& inventory) {
    // Implement catching a Pokémon and adding it to the inventory
    string name, type;
    int level;
    cout << "Enter the name of the Pokémon: ";
    cin >> name;
    cout << "Enter the type of the Pokémon: ";
    cin >> type;
    cout << "Enter the level of the Pokémon: ";
    cin >> level;

    Pokemon* newPokemon = new Pokemon;
    newPokemon->name = name;
    newPokemon->type = type;
    newPokemon->level = level;
    newPokemon->next = nullptr;

    if (!inventory) {
        inventory = newPokemon;
    } else {
        Pokemon* current = inventory;
        while (current->next) {
            current = current->next;
        }
        current->next = newPokemon;
    }

    cout << "You caught a " << name << "!\n";
}

void displayInventory(Pokemon* inventory) {
    if (!inventory) {
        cout << "Inventory is empty.\n";
        return;
    }

    Pokemon* earthList = nullptr;
    Pokemon* fireList = nullptr;
    Pokemon* waterList = nullptr;

    // Separate Pokémon into three different lists based on their types
    Pokemon* current = inventory;
    while (current) {
        Pokemon* next = current->next;

        if (current->type == "earth") {
            current->next = earthList;
            earthList = current;
        } else if (current->type == "fire") {
            current->next = fireList;
            fireList = current;
        } else if (current->type == "water") {
            current->next = waterList;
            waterList = current;
        }

        current = next;
    }

    // Display Pokémon in the order of earth, fire, water
    int count = 1;
    current = earthList;
    while (current) {
        cout << count << ". Name: " << current->name << ", Type: " << current->type << ", Level: " << current->level << "\n";
        current = current->next;
        count++;
    }

    current = fireList;
    while (current) {
        cout << count << ". Name: " << current->name << ", Type: " << current->type << ", Level: " << current->level << "\n";
        current = current->next;
        count++;
    }

    current = waterList;
    while (current) {
        cout << count << ". Name: " << current->name << ", Type: " << current->type << ", Level: " << current->level << "\n";
        current = current->next;
        count++;
    }
}

void buildTeam(Pokemon* inventory) {
    if (!inventory) {
        cout << "Inventory is empty. Cannot build a team.\n";
        return;
    }

    cout << "Select 5 Pokémon for your team:\n";

    // Display the inventory to choose from
    displayInventory(inventory);

    // Create an array to store the team
    Pokemon* team[5] = {nullptr};

    for (int i = 0; i < 5; ++i) {
        int choice;
        cout << "Select Pokémon " << i + 1 << ": ";
        cin >> choice;

        // Find the selected Pokémon in the inventory
        int count = 1;
        Pokemon* current = inventory;
        while (current && count < choice) {
            current = current->next;
            count++;
        }

        if (!current) {
            cout << "Invalid selection. Try again.\n";
            --i;  // Decrement i to try selecting again
            continue;
        }

        // Add the selected Pokémon to the team
        team[i] = current;
    }

    cout << "Your team has been selected:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". Name: " << team[i]->name << ", Type: " << team[i]->type << ", Level: " << team[i]->level << "\n";
    }
}

int main() {
    Pokemon* inventory = nullptr;  // Linked list to store Pokémon

    bool exit = false;
    while (!exit) {
        displayMenu();

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                typeSorting();
                break;
            case 2:
                catchPokemon(inventory);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                buildTeam(inventory);
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    // Cleanup inventory linked list
    Pokemon* current = inventory;
    while (current) {
        Pokemon* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
