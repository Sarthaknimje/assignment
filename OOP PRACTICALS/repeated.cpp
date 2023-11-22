#include <iostream>
#include <vector>

void printRepeatingElements(std::vector<int>& arr) {
    std::cout << "Repeated numbers with their frequencies:\n";

    int n = arr.size();
    bool repeated = false;

    for (int i = 0; i < n; ++i) {
        if (arr[abs(arr[i])] >= 0) {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            repeated = true;
            std::cout << abs(arr[i]) << " occurs more than once\n";
        }
    }

    if (!repeated) {
        std::cout << "No numbers are repeated.\n";
    }
}

int main() {
    std::vector<int> numbers = {4, 2, 4, 5, 2, 3, 1, 3, 4, 5}; // Example array

    printRepeatingElements(numbers);

    return 0;
}
