#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

string prefixToPostfix(string prefix) {
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            st.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expr = op1 + op2 + ch;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "Postfix expression: "
         << prefixToPostfix(prefix) << endl;

    return 0;
}
