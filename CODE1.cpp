#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to apply a special cipher (Caesar Cipher + Run-Length Encoding)
string specialCipher(const string& input, int rotation) {
    string caesarResult;

    // Step 1: Apply Caesar Cipher
    // Rotating each alphabetic character by the specified rotation number
    for (char ch : input) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a'; // Determine base for uppercase or lowercase
            caesarResult += (ch - base + rotation) % 26 + base; // Apply rotation
        } else {
            caesarResult += ch; // Non-alphabetic characters remain unchanged
        }
    }

    // Step 2: Apply Run-Length Encoding (RLE)
    string result; // To store the final output after encoding
    int n = caesarResult.length();

    for (int i = 0; i < n; ++i) {
        char currentChar = caesarResult[i]; // Current character in the transformed string
        int count = 1; // Initialize count for RLE

        // Count consecutive occurrences of the current character
        while (i + 1 < n && caesarResult[i + 1] == currentChar) {
            ++count; // Increment count for each match
            ++i;     // Move to the next character
        }

        // Append character and its count to the result
        result += currentChar;
        if (count > 1) {
            result += to_string(count); // Only add the count if it's greater than 1
        }
    }

    return result; // Return the final encoded string
}

// Main function to test the special cipher function
int main() {
    string input = "AABCCC";  // Input string
    int rotation = 3;         // Rotation for Caesar Cipher

    // Displaying the input and rotation
    cout << "Input: " << input << endl;
    cout << "Rotation: " << rotation << endl;

    // Calling the special cipher function
    string output = specialCipher(input, rotation);

    // Displaying the output
    cout << "Output: " << output << endl;

    return 0;
}
               /***    APPROACH    **/


// Input Handling:

// Receive the input string and the rotation number as parameters. The input string can contain uppercase and lowercase alphabetic characters, and possibly non-alphabetic characters.
// Ensure the rotation is applied only to alphabetic characters.
// Caesar Cipher:

// Traverse through each character in the string.
// For alphabetic characters:
// Determine the base ASCII value ('A' for uppercase, 'a' for lowercase).
// Apply the formula (ch - base + rotation) % 26 + base to calculate the rotated character.
// For non-alphabetic characters, keep them unchanged.
// Store the result in a temporary string (caesarResult).
// Run-Length Encoding (RLE):

// Traverse the caesarResult string.
// Count consecutive occurrences of each character.
// Append the character and its count (if count > 1) to the final result string (result).
// If a character appears only once, append it without any count.
// Return the Final Output:

// The output combines the Caesar Cipher transformation with the RLE compression.
// Time Complexity:
// Caesar Cipher Step: 
// 𝑂
// (
// 𝑛
// )
// O(n), where 
// 𝑛
// n is the length of the input string. Each character is processed once.
// Run-Length Encoding Step: 
// 𝑂
// (
// 𝑛
// )
// O(n). Again, each character is visited once for counting consecutive occurrences.
// Overall Time Complexity: 
// 𝑂
// (
// 𝑛
// )
// O(n).
// Space Complexity:
// Caesar Result String: Requires 
// 𝑂
// (
// 𝑛
// )
// O(n) space to store the intermediate transformation.
// Final Result String: Requires 
// 𝑂
// (
// 𝑛
// )
// O(n) space for the compressed output.
// Overall Space Complexity: 
// 𝑂
// (
// 𝑛
// )
// O(n), as we are storing two strings proportional to the input size.
// This approach ensures efficient handling of both operations with minimal overhead, making it optimal for practical usage.




//    Second question 



