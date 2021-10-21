#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    // Your code goes here.
    char status;
    int children;
    float exemption;
    float salary;
    float pension;
    float deduction;
    float taxincome;
    float federaltax;
    float bracket1;
    float bracket2;
    int federaltaxes;
    cout << "Are you married? (M/S): ";
    cin >> status;
    if (status == 'M' || status == 'm') {
        cout << "How many chilren do you have under the age of 14?: ";
        cin >> children;
        if (children < 0) children = 0;
        exemption = 7000 + 3000 + (1500 * children);
        cout << "Enter your gross salary: ";
        cin >> salary;
        if (salary < 0) salary = 0;
        cout << "Enter pension amount: ";
        cin >> pension;
        if (pension > 6) {
            pension = 6;
        } else if (pension < 0) {
            pension = 0;
        }
    } else if ((status != 'M' || status != 'm' )) {
        exemption = 5500;
        cout << "Enter your gross salary: ";
        cin >> salary;
        if (salary < 0) salary = 0;
        cout << "Enter pension amount: ";
        cin >> pension;
        if (pension > 6) {
            pension = 6;
        } else if (pension < 0) {
            pension = 0;
        }
    }
    pension = (salary / 100) * pension;
    deduction = exemption + pension;
    taxincome = salary - deduction;
    if (taxincome >= 0 && taxincome <= 15000) {
        federaltax = (taxincome / 100) * 15;
    } else if (taxincome >= 15000 && taxincome <= 40000) {
        bracket1 = taxincome - 15000;
        federaltax = 2250 + (bracket1 / 100) * 25;
    } else if (taxincome >= 40000) {
        bracket2 = taxincome - 40000;
        federaltax = 8500 + (bracket2 / 100) * 35;
    }
    federaltaxes = federaltax;
    if (federaltaxes < 0) federaltaxes = 0;
    cout << "Your federal tax is $" << federaltaxes << ".";
    return 0;
}
