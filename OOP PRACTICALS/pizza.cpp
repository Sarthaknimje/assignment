#include <iostream>
using namespace std;

int main() {
    int maxSize;
    cout << "Enter the number of customers: ";
    cin >> maxSize;

    bool likesPizza[maxSize];
    bool likesBurger[maxSize];

    // Taking user input for customer preferences
    cout << "Enter 1 if the customer likes pizza, 0 otherwise:" << endl;
    for (int i = 0; i < maxSize; ++i) {
        cout << "Customer " << i << ": ";
        cin >> likesPizza[i];
    }

    cout << "Enter 1 if the customer likes burger, 0 otherwise:" << endl;
    for (int i = 0; i < maxSize; ++i) {
        cout << "Customer " << i << ": ";
        cin >> likesBurger[i];
    }

    // a. Set of customers who like either pizza or burger or both
    cout << "Customers who like either pizza or burger or both: ";
    for (int i = 0; i < maxSize; ++i) {
        if (likesPizza[i] || likesBurger[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // b. Set of customers who like both pizza and burger
    cout << "Customers who like both pizza and burger: ";
    for (int i = 0; i < maxSize; ++i) {
        if (likesPizza[i] && likesBurger[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // c. Set of customers who like only pizza, not burger
    cout << "Customers who like only pizza, not burger: ";
    for (int i = 0; i < maxSize; ++i) {
        if (likesPizza[i] && !likesBurger[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // d. Set of customers who like only burger, not pizza
    cout << "Customers who like only burger, not pizza: ";
    for (int i = 0; i < maxSize; ++i) {
        if (!likesPizza[i] && likesBurger[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // e. Number of customers who like neither pizza nor burger
    int neitherCount = 0;
    for (int i = 0; i < maxSize; ++i) {
        if (!likesPizza[i] && !likesBurger[i]) {
            neitherCount++;
        }
    }
    cout << "Number of customers who like neither pizza nor burger: " << neitherCount << endl;

    return 0;
}
