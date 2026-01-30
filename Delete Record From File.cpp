#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadFileToVector(string filePath, vector<string>& contentVector) {

    fstream dataFile;
    dataFile.open(filePath, ios::in);

    if (dataFile.is_open()) {
        string currentLine;
        while (getline(dataFile, currentLine)) {
            if (currentLine != "") {
                contentVector.push_back(currentLine);
            }
        }
        dataFile.close();
    }
}

void SaveVectorToFile(string filePath, vector<string> contentVector) {

    fstream dataFile;
    dataFile.open(filePath, ios::out);

    if (dataFile.is_open()) {
        for (string& line : contentVector) {
            if (line != "") {
                dataFile << line << endl;
            }
        }
        dataFile.close();
    }
}

void RemoveRecordFromFile(string filePath, string targetRecord) {

    vector<string> fileRecords;
    LoadFileToVector(filePath, fileRecords);

    for (string& record : fileRecords) {
        if (record == targetRecord) {
            record = "";
        }
    }

    SaveVectorToFile(filePath, fileRecords);
}

void DisplayFileContent(string filePath) {

    fstream dataFile;
    dataFile.open(filePath, ios::in);

    if (dataFile.is_open()) {
        string currentLine;
        while (getline(dataFile, currentLine)) {
            cout << currentLine << endl;
        }
        dataFile.close();
    }
}

int main() {
    string myFileName = "DataStore.txt";

    cout << "--- File Content Before Deletion ---" << endl;
    DisplayFileContent(myFileName);

    RemoveRecordFromFile(myFileName, "Abd");

    cout << "\n--- File Content After Deletion ---" << endl;
    DisplayFileContent(myFileName);

    return 0;
}