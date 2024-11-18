#include <iostream>
#include <ncurses.h>

using namespace std;

// Function to display the menu
void displayMenu(const string options[], int optionCount, int selected)
{
    cout << "\033[2J\033[1;1H"; // Clear screen and move cursor to top-left
    for (int i = 0; i < optionCount; ++i) {
        if (i == selected) {
            cout << " > " << options[i] << " <" << endl; // Highlight selected option
        } else {
            cout << "   " << options[i] << endl;
        }
    }
    cout << "Use Up/Down Arrow keys to navigate and Enter to select." << endl;
}

// Main function
int main()
{
    // Menu options
    const string options[] = { "Option 1", "Option 2", "Option 3", "Exit" };
    const int optionCount = sizeof(options) / sizeof(options[0]);
    int selected = 0;
    char input;

    while (true) {
        // Display the menu
        displayMenu(options, optionCount, selected);

        // Get a single character input
        input = cin.get();

        if (input == '\033') { // Escape sequence for arrow keys
            cin.get(); // Skip the '['
            switch (cin.get()) {
            case 'A': // Up arrow
                selected = (selected - 1 + optionCount) % optionCount; // Wrap around
                break;
            case 'B': // Down arrow
                selected = (selected + 1) % optionCount; // Wrap around
                break;
            }
        } else if (input == '\n') { // Enter key
            cout << "You selected: " << options[selected] << endl;
            if (options[selected] == "Exit") {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }
    return 0;
}
