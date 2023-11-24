#include <iostream>
#include <algorithm>

struct Student {
    std::string name;
    int id;
    int marks;
};

// Quick Sort implementation
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high].marks;
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j].marks < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int numStudents = 10;

    // Student information input
    Student students[numStudents];
    std::cout << "Enter information for 10 students:\n";
    for (int i = 0; i < numStudents; i++) {
        std::cout << "Student " << i + 1 << ":\n";
        std::cout << "Name: ";
        std::cin >> students[i].name;
        std::cout << "ID: ";
        std::cin >> students[i].id;
        std::cout << "Marks: ";
        std::cin >> students[i].marks;
    }

    // Sort students based on marks using Quick Sort
    quickSort(students, 0, numStudents - 1);

    // Display the lowest 5 student marks
    std::cout << "Lowest 5 student marks:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << students[i].name << " (ID: " << students[i].id << ") - Marks: " << students[i].marks << std::endl;
    }

    return 0;
}