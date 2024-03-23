void typeSorting(Pokemon* inventory) {
    if (!inventory) {
        cout << "Inventory is empty.\n";
        return;
    }

    string type;
    cout << "Enter the type of Pokémon you want to display (earth, fire, water): ";
    cin >> type;

    // Display only the selected type of Pokémon
    int count = 1;
    Pokemon* current = inventory;
    while (current) {
        if (current->type == type) {
            cout << count << ". Name: " << current->name << ", Type: " << current->type << ", Level: " << current->level << "\n";
            count++;
        }
        current = current->next;
    }

    if (count == 1) {
        cout << "No " << type << " type Pokémon found in inventory.\n";
    }
}
