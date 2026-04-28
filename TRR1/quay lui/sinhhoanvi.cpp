#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
vector<bool> used;
void genPermutation(int n, int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = 1;
            v.push_back(j);
            if (v.size() == n) {
                for (int num:v)
                    cout << num;
                cout << endl;
            }
            else
                genPermutation(n, i + 1);
            used[j] = 0;
            v.pop_back();
        }
    }
}
void solve() {
    int n;
    cin >> n;
    used.resize(n + 1, 0);
    genPermutation(n, 1);
}
int main() {
    solve();
}