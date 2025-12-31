#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

string prefixToInfix(string prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            st.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "Infix expression: "
         << prefixToInfix(prefix) << endl;

    return 0;
}
