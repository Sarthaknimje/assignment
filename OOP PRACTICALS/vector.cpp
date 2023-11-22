#include <iostream>

template <typename T, size_t N>
class Vector {
private:
    T elements[N];

public:
    void set(T (&elems)[N]) {
        for (size_t i = 0; i < N; ++i) {
            elements[i] = elems[i];
        }
    }

    void modify(size_t index, T& value) {
        if (index < N) {
            elements[index] = value;
        } else {
            std::cout << "Index out of range." << std::endl;
        }
    }

    void scale(T& factor) {
        for (size_t i = 0; i < N; ++i) {
            elements[i] *= factor;
        }
    }

    void display() {
        std::cout << "(";
        for (size_t i = 0; i < N; ++i) {
            std::cout << elements[i];
            if (i != N - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    void inputValues() {
        std::cout << "Enter " << N << " values for the vector:\n";
        for (size_t i = 0; i < N; ++i) {
            std::cout << "Value " << i + 1 << ": ";
            std::cin >> elements[i];
        }
    }
};

int main() {
    Vector<int, 5> intVector;
    intVector.inputValues();
    intVector.display();

    int index, value;
    std::cout << "Enter index to modify (0-" << 5 - 1 << "): ";
    std::cin >> index;
    std::cout << "Enter value to set: ";
    std::cin >> value;

    intVector.modify(index, value);
    intVector.display();

    int scalar;
    std::cout << "Enter scalar value to scale: ";
    std::cin >> scalar;

    intVector.scale(scalar);
    intVector.display();

    return 0;
}