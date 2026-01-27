#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void displayWishlist(vector<string>& destinations) {
    if (destinations.empty()) {
        cout << "\nYour wishlist is empty. Time to dream big!" << endl;
        return;
    }
    cout << "\n--- My Dream Destinations ---" << endl;
    vector<string>::iterator it;
    for (it = destinations.begin(); it != destinations.end(); ++it) {
        cout << " -> " << *it << endl;
    }
}

void addDestination(vector<string>& destinations) {
    string city;
    cout << "Enter the city or country: ";
    getline(cin >> ws, city);
    destinations.push_back(city);
    cout << "Added to your dreams!" << endl;
}

int main() {
    vector<string> myWishlist;
    int choice;

    cout << "Welcome to your Travel Wishlist App!" << endl;

    do {
        cout << "\n1. Add a Destination";
        cout << "\n2. View My Wishlist";
        cout << "\n3. Exit";
        cout << "\nChoice: ";

        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        if (choice == 1) {
            addDestination(myWishlist);
        }
        else if (choice == 2) {
            displayWishlist(myWishlist);
        }

    } while (choice != 3);

    cout << "Safe travels!" << endl;
    return 0;
}