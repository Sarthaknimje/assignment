#include <iostream>
#include <vector>
using namespace std;

// Partition function for Quick Sort
int partition(vector<int> &marks, int low, int high) {
    int pivot = marks[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (marks[j] < pivot) {
            i++;
            swap(marks[i], marks[j]);
        }
    }
    swap(marks[i + 1], marks[high]);
    return (i + 1);
}

// Quick Sort algorithm
void quickSort(vector<int> &marks, int low, int high) {
    if (low < high) {
        int pi = partition(marks, low, high);

        quickSort(marks, low, pi - 1);
        quickSort(marks, pi + 1, high);
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<int> studentMarks(numStudents);

    cout << "Enter marks for each student:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> studentMarks[i];
    }

    quickSort(studentMarks, 0, numStudents - 1);

    cout << "\nLowest 5 student marks:\n";
    for (int i = 0; i < min(5, numStudents); ++i) {
        cout << "Mark: " << studentMarks[i] << endl;
    }

    return 0;
}