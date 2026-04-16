#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Helper function to read entire file into a string
string readFile(const string& fileName) {
    ifstream file(fileName);
    if (!file) return "";
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    string sourceFile = "text.txt";
    string removeFile = "remove.txt";

    string mainText = readFile(sourceFile);
    string toRemove = readFile(removeFile);

    if (mainText.empty() || toRemove.empty()) {
        cerr << "Error: One of the files is empty or missing." << endl;
        return 1;
    }

    // --- The Global Search and Replace Logic ---
    size_t pos = mainText.find(toRemove);
    int count = 0;

    // While 'toRemove' is still found in the string...
    while (pos != string::npos) {
        mainText.erase(pos, toRemove.length());
        count++;
        // Look for the next occurrence starting from the current position
        pos = mainText.find(toRemove, pos);
    }

    if (count > 0) {
        // Overwrite the original file with the modified text
        ofstream outFile(sourceFile);
        if (outFile.is_open()) {
            outFile << mainText;
            outFile.close();
            cout << "Success: Removed " << count << " occurrence(s)." << endl;
        }
    } else {
        cout << "No matches found to remove." << endl;
    }

    return 0;
}