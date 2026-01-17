#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stJobInfo {
    string companyName = "";
    float salary = 0.0;
    int officeNumber = 0;
};

struct stEmployeeInfo {
    string firstName = "";
    string lastName = "";
    string phoneNumber = "";
    stJobInfo jobDetails;
};

void ReadEmployeesData(vector<stEmployeeInfo>& vEmployees) {
    stEmployeeInfo tempEmployee;
    char addMore = 'Y';

    while (addMore == 'Y' || addMore == 'y') {
        cout << "\n--- Enter Employee Details ---\n";

        cout << "First Name: ";
        cin >> tempEmployee.firstName;

        cout << "Last Name: ";
        cin >> tempEmployee.lastName;

        cout << "Phone Number: ";
        cin >> tempEmployee.phoneNumber;

        cout << "Company Name: ";
        cin >> tempEmployee.jobDetails.companyName;

        cout << "Salary: ";
        cin >> tempEmployee.jobDetails.salary;

        cout << "Office Number: ";
        cin >> tempEmployee.jobDetails.officeNumber;

        vEmployees.push_back(tempEmployee);

        cout << "\nDo you want to add another employee? (Y/N): ";
        cin >> addMore;
    }
}

void PrintEmployeesData(const vector<stEmployeeInfo>& vEmployees) {
    cout << "\n========================================";
    cout << "\n       REGISTERED EMPLOYEES LIST        ";
    cout << "\n========================================\n";

    for (const stEmployeeInfo& emp : vEmployees) {
        cout << "Full Name      : " << emp.firstName << " " << emp.lastName << endl;
        cout << "Phone          : " << emp.phoneNumber << endl;
        cout << "Company        : " << emp.jobDetails.companyName << endl;
        cout << "Salary         : $" << emp.jobDetails.salary << endl;
        cout << "Office No.     : " << emp.jobDetails.officeNumber << endl;
        cout << "----------------------------------------" << endl;
    }
}

int main() {
    vector<stEmployeeInfo> vEmployeesList;

    ReadEmployeesData(vEmployeesList);
    PrintEmployeesData(vEmployeesList);

    return 0;
}