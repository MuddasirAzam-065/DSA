#include <iostream>
using namespace std;

int main() {
    int marks[5], total = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    float percentage = total / 5.0;
    cout << "Total: " << total << ", Percentage: " << percentage << "%" << endl;

    if (percentage >= 90) 
		cout << "Grade: A";
    else if (percentage >= 80) 
		cout << "Grade: B";
    else if (percentage >= 70) 
		cout << "Grade: C";
    else 
		cout << "Grade: F";

    return 0;
}