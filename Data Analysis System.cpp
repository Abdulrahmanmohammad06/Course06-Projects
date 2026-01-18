#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>  

using namespace std;

struct stNumberStats {
    int min = 0;
    int max = 0;
    double average = 0.0;
    int totalSum = 0;
};

void ReadNumbers(vector<int>& vNumbers) {
    int num;
    char addMore = 'Y';

    while (addMore == 'Y' || addMore == 'y') {
        cout << "Enter an integer: ";
        cin >> num;
        while (cin.fail()) {


            cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid integer." << endl;
			cin >> num;
        
        
        }
        vNumbers.push_back(num);

        cout << "Add another? (y/n): ";
        cin >> addMore;
    }
}

stNumberStats CalculateStats(const vector<int>& vNumbers) {
    stNumberStats stats;

    if (vNumbers.empty()) return stats;

    stats.min = vNumbers[0];
    stats.max = vNumbers[0];
    stats.totalSum = 0;

    for (int n : vNumbers) {
        if (n < stats.min) stats.min = n;
        if (n > stats.max) stats.max = n;
        stats.totalSum += n;
    }

    stats.average = (double)stats.totalSum / vNumbers.size();

    return stats;
}

void PrintResults(const vector<int>& vNumbers, stNumberStats stats) {
    cout << "\n========================================";
    cout << "\n          NUMBERS ANALYSIS              ";
    cout << "\n========================================\n";

    cout << "Numbers Entered: ";
    for (int n : vNumbers) cout << "[" << n << "] ";

    cout << "\n\n--- Statistics ---";
    cout << "\nTotal Count  : " << vNumbers.size();
    cout << "\nSum          : " << stats.totalSum;
    cout << "\nAverage      : " << stats.average;
    cout << "\nMaximum      : " << stats.max;
    cout << "\nMinimum      : " << stats.min;
    cout << "\n----------------------------------------\n";
}

int main() {
    vector<int> vNumbersList;

    ReadNumbers(vNumbersList);
    stNumberStats stats = CalculateStats(vNumbersList);
    PrintResults(vNumbersList, stats);
    

    return 0;
}

