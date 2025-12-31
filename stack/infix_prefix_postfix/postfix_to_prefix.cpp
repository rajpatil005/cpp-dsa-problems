#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string expr = ch + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Prefix expression: "
         << postfixToPrefix(postfix) << endl;

    return 0;
}
