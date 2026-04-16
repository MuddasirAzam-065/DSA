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
        if (isFull())
            return false;
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (isEmpty())
            return false;
        top--;
        return true;
    }

    T getTop() {
        if (isEmpty())
            return T();
        return arr[top];
    }

    ~Stack() {
        delete[] arr;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '\\' || op == '%') return 2; // include \ and %
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\\' || ch == '%' || ch == '^');
}


bool isOperand(char ch) {
    return (isalnum(ch));
}

string infixToPostfix(string infix) {
    Stack<char> s(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.getTop() != '(') {
                postfix += s.getTop();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.isEmpty() &&
                   precedence(s.getTop()) >= precedence(ch)) {
                postfix += s.getTop();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.getTop();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

