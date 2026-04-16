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
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
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

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isValidExpression(string expr) {
    Stack<char> s(expr.length());

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false;
            }

            char topChar = s.getTop();
            s.pop();

            if (!isMatchingPair(topChar, ch)) {
                return false; 
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isValidExpression(expression)) {
        cout << "Expression is VALID (Balanced Parentheses)\n";
    } else {
        cout << "Expression is INVALID (Unbalanced Parentheses)\n";
    }

    return 0;
}
