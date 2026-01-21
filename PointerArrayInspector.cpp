#include<iostream>
using namespace std;

void FillArray(int* Arr, int& arrLength) {
    cout << "Please Enter The Array Length: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++) {
        cout << "Element [" << i << "]: ";
        cin >> *(Arr + i);
    }
}

void PrintArrayWithAddresses(int* Arr, int arrLength) {
    cout << "\n--- Array Details ---\n";
    for (int i = 0; i < arrLength; i++) {
        cout << "Value: " << *(Arr + i) << " \t Address: " << (Arr + i) << endl;
    }
}

int main() {
    int Arr[100];
    int ArrLength = 0;

    FillArray(Arr, ArrLength);
    PrintArrayWithAddresses(Arr, ArrLength);

    return 0;
}