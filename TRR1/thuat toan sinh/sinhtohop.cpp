#include <bits/stdc++.h>
#define ll long long
using namespace std;
void generateCombinations(int n, int k) {
    vector<int> v(k);
    for (int i = 0; i < k; i++)
        v[i] = i + 1;
    while (1) {
        for (int num:v)
            cout << num << " ";
        cout << endl;
        int i = k - 1;
        while (i >= 0 && v[i] == n - k + i + 1)
            --i;
        if (i < 0)
            break;
        ++v[i];
        for (int j = i + 1; j < k; j++)
            v[j] = v[j - 1] + 1;
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    generateCombinations(n, k);
}
int main() {
    solve();
}