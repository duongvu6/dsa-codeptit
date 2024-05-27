#include <bits/stdc++.h>
using namespace std;
int maxHeight;
int maxWeight;
int largestArea(vector<vector<int>> &a, int n, int m);
int calArea(vector<int> height);
int calArea(vector<int> height) {
    stack<int> st;
    int maxArea = 0;
    int n = height.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || height[i] < height[st.top()])) {
            int nowHeight = height[st.top()];
            st.pop();
            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            if (nowHeight * width > maxArea) {
                maxHeight = nowHeight;
                maxWeight = width;
                maxArea =nowHeight * width;
            } 
            
        }
        st.push(i);
    }
    return maxArea;
}
int largestArea(vector<vector<int>> &a, int n, int m) {
    vector<int> height(m, 0);
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        maxArea = max(maxArea, calArea(height));
    }
    return maxArea;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cout << largestArea(a, n, m);
        cout << "\n" << maxHeight << " " << maxWeight << endl;
    }
    
    return 0;
}
