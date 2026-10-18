
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username) {
    ifstream file("users.txt");
    string savedUsername, savedPassword;

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username) {
            return true;
        }
    }

    return false;
}

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username.length() < 3 || password.length() < 6) {
        cout << "Username must have at least 3 characters "
             << "and password at least 6 characters.\n";
        return;
    }

    if (userExists(username)) {
        cout << "Username already exists.\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "Error saving user details.\n";
        return;
    }

    file << username << " " << password << '\n';
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    string savedUsername, savedPassword;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> savedUsername >> savedPassword) {
        if (savedUsername == username &&
            savedPassword == password) {
            cout << "Login successful! Welcome, "
                 << username << ".\n";
            return;
        }
    }

    cout << "Invalid username or password.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LOGIN AND REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
