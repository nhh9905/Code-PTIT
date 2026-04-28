#include <bits/stdc++.h>
#define ll long long
using namespace std;
void genPermutation(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    while (1) {
        for (int num:v)
            cout << num << " ";
        cout << endl;
        int i = n - 2;
        while (i >= 0 && v[i] > v[i + 1])
            --i;
        if (i < 0)
            break;
        int j = n - 1;
        while (v[j] <= v[i])
            --j;
        swap(v[i], v[j]);
        reverse(v.begin() + i + 1, v.end());
    }
}
void solve() {
    int n;
    cin >> n;
    genPermutation(n);
}
int main() {
    solve();
}