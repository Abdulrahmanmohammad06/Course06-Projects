#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadFileToVector(string filePath, vector<string>& dataVector) {
    fstream dataFile;
    dataFile.open(filePath, ios::in);

    if (dataFile.is_open()) {
        string currentLine;
        while (getline(dataFile, currentLine)) {
            if (currentLine != "") {
                dataVector.push_back(currentLine);
            }
        }
        dataFile.close();
    }
}

void SaveVectorToFile(string filePath, vector<string> dataVector) {
    fstream dataFile;
    dataFile.open(filePath, ios::out);

    if (dataFile.is_open()) {
        for (string& line : dataVector) {
            if (line != "") {
                dataFile << line << endl;
            }
        }
        dataFile.close();
    }
}

void UpdateRecordInFile(string filePath, string oldData, string newData) {
    vector<string> fileContent;
    LoadFileToVector(filePath, fileContent);

    for (string& line : fileContent) {
        if (line == oldData) {
            line = newData;
        }
    }

    SaveVectorToFile(filePath, fileContent);
}

void DisplayData(string filePath) {
    fstream dataFile;
    dataFile.open(filePath, ios::in);

    if (dataFile.is_open()) {
        string currentLine;
        while (getline(dataFile, currentLine)) {
            cout << "- " << currentLine << endl;
        }
        dataFile.close();
    }
}

int main() {
    string myStorageFile = "Database.txt";

    cout << "--- Data Before Update ---" << endl;
    DisplayData(myStorageFile);

 
    UpdateRecordInFile(myStorageFile, "Abdullah", "Abdulrahman");

    cout << "\n--- Data After Update ---" << endl;
    DisplayData(myStorageFile);

    return 0;
}