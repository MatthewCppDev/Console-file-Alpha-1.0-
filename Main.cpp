#include <iostream>   // For input and output operations (cin, cout)
#include <fstream>    // For file stream operations (ifstream, ofstream)
#include <string>     // For using the string class

using namespace std;

// Function to create a new file with the given file name
void createFile(const string& fileName) {
    ofstream file(fileName); // Create and open file for writing
    if (file.is_open()) {    // Check if the file was created successfully
        cout << "File '" << fileName << "' created!\n";
        file.close();        // Close the file
    }
    else {
        cout << "Error creating file.\n";
    }
}

// Function to open an existing file and display its contents
void openFile(const string& fileName) {
    ifstream file(fileName); // Open file for reading
    if (file.is_open()) {    // Check if file exists and is open
        cout << "Content of '" << fileName << "':\n";
        string line;
        // Read the file line by line and display each line
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();        // Close the file after reading
    }
    else {
        cout << "File not found.\n";
    }
}

// Function to append new text to an existing file
void editFile(const string& fileName) {
    ofstream file(fileName, ios::app); // Open file in append mode (keep old content)
    if (file.is_open()) {
        cout << "Type text to add (type 'END' to stop):\n";
        string line;
        cin.ignore(); // Clear the input buffer (in case there are leftover characters)
        while (true) {
            getline(cin, line); // Read a line from user input
            if (line == "END") break; // If user types 'END', stop adding
            file << line << endl;     // Write the line to the file
        }
        file.close(); // Close the file after editing
        cout << "Text added to file!\n";
    }
    else {
        cout << "Error opening file for editing.\n";
    }
}

// Main function with a menu for the user
int main() {
    int choice;         // Store user menu choice
    string fileName;    // Store the file name entered by the user

    while (true) {      // Infinite loop to keep showing the menu until user exits
        // Display menu options
        cout << "\n--- Simple Text Editor ---\n";
        cout << "1. Create new file\n";
        cout << "2. Open file\n";
        cout << "3. Edit file\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;  // Get user's menu choice

        // Handle user choice using switch-case
        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            cin >> fileName;
            createFile(fileName); // Call function to create file
            break;
        case 2:
            cout << "Enter file name: ";
            cin >> fileName;
            openFile(fileName);   // Call function to open file
            break;
        case 3:
            cout << "Enter file name: ";
            cin >> fileName;
            editFile(fileName);   // Call function to edit file
            break;
        case 4:
            cout << "Exiting...\n"; // Exit the program
            return 0;
        default:
            cout << "Invalid option.\n"; // Handle invalid menu choices
        }
    }
    return 0;
}
