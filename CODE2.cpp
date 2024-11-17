#include <iostream>
#include <vector>
#include <iomanip> // For setting precision

using namespace std;

// Function to calculate the minimum number of units for a given value
int minUnits(int value, const vector<int>& denominations) {
    int count = 0; // Number of units
    for (int i = denominations.size() - 1; i >= 0; --i) {
        while (value >= denominations[i]) {
            value -= denominations[i];
            ++count;
        }
    }
    return count;
}

// Main function
int main() {
    vector<int> denominations = {1, 2, 5, 10, 20, 50}; // Available denominations
    int totalUnits = 0; // Sum of units used for all values

    cout << "Value\tUnits Used\tCombination\n";
    for (int value = 1; value < 100; ++value) {
        int remaining = value;
        int units = 0; // Number of units for the current value
        vector<int> combination; // Stores the denominations used

        // Find the combination using the greedy approach
        for (int i = denominations.size() - 1; i >= 0; --i) {
            while (remaining >= denominations[i]) {
                remaining -= denominations[i];
                combination.push_back(denominations[i]);
                ++units;
            }
        }

        // Add to total units and display the result for the current value
        totalUnits += units;
        cout << value << "\t" << units << "\t\t";
        for (int denom : combination) {
            cout << denom << " ";
        }
        cout << endl;
    }

    // Calculate and display the average number of units used
    double avgUnits = static_cast<double>(totalUnits) / 99.0;
    cout << fixed << setprecision(2);
    cout << "Average number of units used: " << avgUnits << endl;

    return 0;
}
  




//   Approach:
// Input Denominations:

// Given denominations are 
// 1
// ,
// 2
// ,
// 5
// ,
// 10
// ,
// 20
// ,
// 50
// 1,2,5,10,20,50.
// Optimization for Each Value:

// Use a greedy algorithm for each number 
// 𝑛
// n (from 1 to 99):
// Start with the largest denomination less than or equal to the remaining value.
// Subtract this denomination from the value and add it to the count.
// Repeat until the value becomes zero.
// Compute Units:

// For each value 
// 𝑛
// n, store the number of units required.
// Calculate the average number of units used over all numbers from 1 to 99.
// Output Results:

// For each value, display the combination of denominations and the number of units used.
// At the end, display the average number of units.


// Complexity:
// Time Complexity:
// 𝑂
// (
// 99
// ×
// 𝐷
// )
// O(99×D), where 
// 𝐷
// D is the number of denominations. Here 
// 𝐷
// =
// 6
// D=6, so the effective complexity is 
// 𝑂
// (
// 594
// )
// O(594), which is very efficient.
// Space Complexity:
// 𝑂
// (
// 𝐷
// )
// O(D) for the combination vector used to store denominations for each value. Total space usage is minimal.