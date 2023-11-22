#include <iostream>
using namespace std;

class SHAPE {
protected:
    double base;
    double height;

public:
    void get_data() {
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
    }

    virtual void display_area() = 0;
};

class TRIANGLE : public SHAPE {
public:
    void display_area() override {
        cout << "Area of the triangle: " << 0.5 * base * height << endl;
    }
};

class RECTANGLE : public SHAPE {
public:
    void display_area() override {
        cout << "Area of the rectangle: " << base * height << endl;
    }
};

int main() {
    SHAPE* shapePtr;

    int choice;
    cout << "Enter 1 for Triangle or 2 for Rectangle: ";
    cin >> choice;

    if (choice == 1) {
        shapePtr = new TRIANGLE();
    } else if (choice == 2) {
        shapePtr = new RECTANGLE();
    } else {
        cout << "Invalid choice!";
        return 1;
    }

    shapePtr->get_data();
    shapePtr->display_area();

    delete shapePtr;

    return 0;
}
