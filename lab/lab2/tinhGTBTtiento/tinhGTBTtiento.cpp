#include <bits/stdc++.h>
using namespace std;
int calPrefix(string s) {
    int n = s.size();
    stack<int> st;
    for (int i = n - 1; i >= 0; i--){ 
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = 0;
            switch(s[i]) {
                case '+':
                    res = op1 + op2;
                    st.push(res);
                    break;
                case '-':
                    res = op1 - op2;
                    st.push(res);
                    break;
                case '*':
                    res = op1 * op2;
                    st.push(res);
                    break;
                case '/':
                    res = op1 / op2;
                    st.push(res);
                    break;
            }
        }
    }
    return st.top();
}
void testCase() {
    string s;
    cin >> s;
    cout << calPrefix(s);
}
int main() {
    // Write your code here
    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << endl;
    }
    return 0;
}
