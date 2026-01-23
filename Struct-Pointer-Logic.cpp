#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct stServer {
    string Name = "";
    string ipAdress = "";
    bool isOnline = false;
};

void Fill(stServer* ptr) {
    cout << "========================================" << endl;
    cout << "       SERVER CONFIGURATION MENU        " << endl;
    cout << "========================================" << endl;

    cout << "Enter Server Name: ";
    cin >> ptr->Name;

    cout << "Enter IP Address: ";
    cin >> ptr->ipAdress;

    cout << "Status (1: Online, 0: Offline): ";
    cin >> ptr->isOnline;
}

void PrintStatus(stServer* ptr) {
    string status = (ptr->isOnline) ? "ONLINE" : "OFFLINE";

    cout << endl;
    cout << "========================================" << endl;
    cout << "             SERVER REPORT              " << endl;
    cout << "========================================" << endl;

    cout << setw(15) << "Field" << "| " << "Value" << endl;
    cout << "----------------------------------------" << endl;

    cout << left << setw(15) << "Server Name" << ": " << ptr->Name << endl;
    cout << left << setw(15) << "IP Address" << ": " << ptr->ipAdress << endl;
    cout << left << setw(15) << "Status" << ": " << status << endl;

    cout << "========================================" << endl;
}

int main() {
    stServer Serv;
    stServer* ptr = &Serv;

    Fill(ptr);
    PrintStatus(ptr);

    return 0;
}