#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert postfix to prefix
string postfixToPrefix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } 
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            
            // Concatenate them in prefix order and push back to the stack
            string prefix = c + op2 + op1;
            s.push(prefix);
        }
    }
    
    // The final prefix expression will be at the top of the stack
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);
    cout << "The prefix expression is: " << prefix << endl;

    return 0;
}
