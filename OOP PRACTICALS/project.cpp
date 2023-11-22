#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Purchase {
public:
    void addPurchase(const string& item, double cost) {
        purchases.push_back({item, cost});
    }

    void viewPurchases() {
        cout << "Purchases:\n";
        for (const auto& purchase : purchases) {
            cout << purchase.first << " - $" << purchase.second << "\n";
        }
    }

    void savePurchasesToFile() {
        ofstream file("purchases.txt");
        if (file.is_open()) {
            for (const auto& purchase : purchases) {
                file << purchase.first << "," << purchase.second << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to save purchases to file.\n";
        }
    }

    void loadPurchasesFromFile() {
        ifstream file("purchases.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                string item = line.substr(0, pos);
                double cost = stod(line.substr(pos + 1));
                purchases.push_back({item, cost});
            }
            file.close();
        } else {
            cerr << "Unable to load purchases from file.\n";
        }
    }

private:
    vector<pair<string, double>> purchases;
};

class Sales {
public:
    void addSale(const string& item, double price) {
        sales.push_back({item, price});
    }

    void viewSales() {
        cout << "Sales:\n";
        for (const auto& sale : sales) {
            cout << sale.first << " - $" << sale.second << "\n";
        }
    }

    void saveSalesToFile() {
        ofstream file("sales.txt");
        if (file.is_open()) {
            for (const auto& sale : sales) {
                file << sale.first << "," << sale.second << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to save sales to file.\n";
        }
    }

    void loadSalesFromFile() {
        ifstream file("sales.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                string item = line.substr(0, pos);
                double price = stod(line.substr(pos + 1));
                sales.push_back({item, price});
            }
            file.close();
        } else {
            cerr << "Unable to load sales from file.\n";
        }
    }

private:
    vector<pair<string, double>> sales;
};

class EmployeeAttendance {
public:
    void recordAttendance(const string& employeeName) {
        attendance.push_back(employeeName);
    }

    void viewAttendance() {
        cout << "Employee Attendance:\n";
        for (const auto& employee : attendance) {
            cout << employee << "\n";
        }
    }

    void saveAttendanceToFile() {
        ofstream file("attendance.txt");
        if (file.is_open()) {
            for (const auto& employee : attendance) {
                file << employee << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to save attendance to file.\n";
        }
    }

    void loadAttendanceFromFile() {
        ifstream file("attendance.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                attendance.push_back(line);
            }
            file.close();
        } else {
            cerr << "Unable to load attendance from file.\n";
        }
    }

private:
    vector<string> attendance;
};

class Bills {
public:
    void addBill(const string& billName, double amount) {
        bills.push_back({billName, amount});
    }

    void viewBills() {
        cout << "Bills:\n";
        for (const auto& bill : bills) {
            cout << bill.first << " - $" << bill.second << "\n";
        }
    }

    void saveBillsToFile() {
        ofstream file("bills.txt");
        if (file.is_open()) {
            for (const auto& bill : bills) {
                file << bill.first << "," << bill.second << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to save bills to file.\n";
        }
    }

    void loadBillsFromFile() {
        ifstream file("bills.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                string billName = line.substr(0, pos);
                double amount = stod(line.substr(pos + 1));
                bills.push_back({billName, amount});
            }
            file.close();
        } else {
            cerr << "Unable to load bills from file.\n";
        }
    }

private:
    vector<pair<string, double>> bills;
};

void showMenuAdmin() {
    cout << "\nMenu (Admin):\n";
    cout << "1. Add Purchase\n";
    cout << "2. View Purchases\n";
    cout << "3. Add Sale\n";
    cout << "4. View Sales\n";
    cout << "5. Record Attendance\n";
    cout << "6. View Attendance\n";
    cout << "7. Add Bill\n";
    cout << "8. View Bills\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

void showMenuEmployee() {
    cout << "\nMenu (Employee):\n";
    cout << "1. Add Purchase\n";
    cout << "2. View Purchases\n";
    cout << "3. Add Sale\n";
    cout << "4. View Sales\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Purchase purchaseModule;
    Sales salesModule;
    EmployeeAttendance attendanceModule;
    Bills billsModule;

    purchaseModule.loadPurchasesFromFile();
    salesModule.loadSalesFromFile();
    attendanceModule.loadAttendanceFromFile();
    billsModule.loadBillsFromFile();

    string adminUsername = "admin";
    string adminPassword = "admin123";

    string employeeUsername = "employee";
    string employeePassword = "emp456";

    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if ((username == adminUsername && password == adminPassword) || (username == employeeUsername && password == employeePassword)) {
        int choice;
        if (username == adminUsername) {
            do {
                showMenuAdmin();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        string item;
                        double cost;
                        cout << "Enter item name: ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "Enter cost: ";
                        cin >> cost;
                        purchaseModule.addPurchase(item, cost);
                        purchaseModule.savePurchasesToFile();
                        cout << "Purchase added successfully.\n";
                        break;
                    }
                    case 2:
                        purchaseModule.viewPurchases();
                        break;
                    case 3: {
                        string item;
                        double price;
                        cout << "Enter item name: ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "Enter price: ";
                        cin >> price;
                        salesModule.addSale(item, price);
                        salesModule.saveSalesToFile();
                        cout << "Sale added successfully.\n";
                        break;
                    }
                    case 4:
                        salesModule.viewSales();
                        break;
                    case 5: {
                        string employeeName;
                        cout << "Enter employee name: ";
                        cin.ignore();
                        getline(cin, employeeName);
                        attendanceModule.recordAttendance(employeeName);
                        attendanceModule.saveAttendanceToFile();
                        cout << "Attendance recorded successfully.\n";
                        break;
                    }
                    case 6:
                        attendanceModule.viewAttendance();
                        break;
                    case 7: {
                        string billName;
                        double amount;
                        cout << "Enter bill name: ";
                        cin.ignore();
                        getline(cin, billName);
                        cout << "Enter amount: ";
                        cin >> amount;
                        billsModule.addBill(billName, amount);
                        billsModule.saveBillsToFile();
                        cout << "Bill added successfully.\n";
                        break;
                    }
                    case 8:
                        billsModule.viewBills();
                        break;
                    case 9:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 9);
        } else {
            do {
                showMenuEmployee();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        string item;
                        double cost;
                        cout << "Enter item name: ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "Enter cost: ";
                        cin >> cost;
                        purchaseModule.addPurchase(item, cost);
                        purchaseModule.savePurchasesToFile();
                        cout << "Purchase added successfully.\n";
                        break;
                    }
                    case 2:
                        purchaseModule.viewPurchases();
                        break;
                    case 3: {
                        string item;
                        double price;
                        cout << "Enter item name: ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "Enter price: ";
                        cin >> price;
                        salesModule.addSale(item, price);
                        salesModule.saveSalesToFile();
                        cout << "Sale added successfully.\n";
                        break;
                    }
                    case 4:
                        salesModule.viewSales();
                        break;
                    case 5:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 5);
        }
    } else {
        cout << "Invalid username or password. Exiting...\n";
    }

    return 0;
} 

