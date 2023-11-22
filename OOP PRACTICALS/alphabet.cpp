#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    int asciiValue = static_cast<int>(ch);

    if (asciiValue >= 65 && asciiValue <= 90) {
        cout << ch << " is an uppercase letter." << endl;
    } else if (asciiValue >= 97 && asciiValue <= 122) {
        cout << ch << " is a lowercase letter." << endl;
    } else if (asciiValue >= 48 && asciiValue <= 57) {
        cout << ch << " is a digit." << endl;
    } else {
        cout << ch << " is a special character." << endl;
    }

    return 0;
}
