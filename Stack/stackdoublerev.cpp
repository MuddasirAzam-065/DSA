#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    bool push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return false;
        }
        top--;
        return true;
    }

    T getTop() {
        if (isEmpty()) {
            return T();
        }
        return arr[top];
    }

    ~Stack() {
        delete[] arr;
    }
};

template <class T>
void reverseArray(T arr[], int size) {
    Stack<T> s(size);

    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = s.getTop();
        s.pop();
    }
}

void reverseStringChars(string& str) {
    int len = str.length();
    char* temp = new char[len];
    for (int i = 0; i < len; i++) {
        temp[i] = str[i];
    }
    reverseArray<char>(temp, len);
    for (int i = 0; i < len; i++) {
        str[i] = temp[i];
    }
    delete[] temp;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    string* arr = new string[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        reverseStringChars(arr[i]);
    }
    reverseArray<string>(arr, n);
    cout << "\nReversed stack and characters:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}
