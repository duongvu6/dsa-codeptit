#include <bits/stdc++.h>
using namespace std;
void testCase();
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
void testCase() {
    int n;
    cin >> n;
    queue<string> q;
    vector<string> v;
    q.push("");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s != "") {
            v.push_back(s);
        }
        if (s.size() == n) {
            continue;
        }
        q.push(s + "6");
        q.push(s + "8");
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout<< v[i] << " ";
    }

}