#include <iostream>

using namespace std;

// Define a structure for employee record
struct Employee {
    int id;
    double salary;
    Employee* next;
};

// Function to create a linked list of employee records
Employee* createEmployeeList() {
    Employee* head = nullptr;
    Employee* prev = nullptr;
    int id;
    double salary;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Salary: $";
        cin >> salary;
        Employee* newEmployee = new Employee{ id, salary, nullptr };
        if (head == nullptr) {
            head = newEmployee;
        } else {
            prev->next = newEmployee;
        }
        prev = newEmployee;
    }
    return head;
}

// Function to find the sum of all salaries in the linked list
double sumSalaries(Employee* head) {
    double total = 0;
    Employee* temp = head;
    while (temp != nullptr) {
        total += temp->salary;
        temp = temp->next;
    }
    return total;
}

// Function to increase all salaries in the linked list by a certain percentage
void increaseSalaries(Employee* head, double percentage) {
    Employee* temp = head;
    while (temp != nullptr) {
        temp->salary *= (1 + percentage / 100);
        temp = temp->next;
    }
}

// Function to print the linked list of employee records
void printEmployeeList(Employee* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        cout << "Employee Records:" << endl;
        Employee* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Salary: $" << temp->salary << endl;
            temp = temp->next;
        }
    }
}

int main() {
    // Create linked list of employee records
    Employee* head = createEmployeeList();

    // Print the employee records
    printEmployeeList(head);

    // Find and print the sum of all salaries
    double totalSalary = sumSalaries(head);
    cout << "Total salary of all employees: $" << totalSalary << endl;

    // Increase all salaries by 10%
    increaseSalaries(head, 10);
    cout << "Salaries increased by 10%." << endl;

    // Print the updated employee records
    printEmployeeList(head);

    // Free dynamically allocated memory
    Employee* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
