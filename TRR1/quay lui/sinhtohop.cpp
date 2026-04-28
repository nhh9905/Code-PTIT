#include <bits/stdc++.h>
#define ll long long
using namespace std;
void generateCombinations(int n, int k, int start, vector<int>& current) {
    if (current.size() == k) {
        for (int num:current)
            cout << num << " ";
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        generateCombinations(n, k, i + 1, current);
        current.pop_back();
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> current;
    generateCombinations(n, k, 1, current);
}
int main() {
    solve();
}
