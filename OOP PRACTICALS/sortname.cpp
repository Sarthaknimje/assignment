#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int numNames;
    cout << "Enter the number of names: ";
    cin >> numNames;

    vector<string> namesList(numNames);

    cout << "Enter " << numNames << " names:\n";
    for (int i = 0; i < numNames; ++i) {
        cin >> namesList[i];
    }

    // Sorting names in alphabetical order
    sort(namesList.begin(), namesList.end());

    // Displaying names in alphabetical order
    cout << "\nNames in alphabetical order:\n";
    for (const auto &name : namesList) {
        cout << name << endl;
    }

    return 0;
}