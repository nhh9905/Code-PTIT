#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dem = 0;
typedef struct tn {
    string data;
    int cnt;
} tn;
tn x[1005];
bool check(string x) {
    if (x.size() == 1)
        return 0;
    int l = 0, r = x.size() - 1;
    while (l < r) {
        if (x[l] != x[r])
            return 0;
        ++l, --r;
    }
    return 1;
}
int pos(string s) {
    for (int i = 0; i < dem; i++) {
        if (x[i].data == s)
            return i;
    }
    return -1;
}
bool cmp(const tn &a, const tn &b) {
    if (a.data.size() > b.data.size())
        return 1;
    if (a.data.size() < b.data.size())
        return 0;
    for (int i = 0; i < a.data.size(); i++) {
        if (a.data[i] > b.data[i])
            return 1;
    }
    return 0;
}
int main() {
    // freopen("a.inp", "r", stdin);
    string s;
    while (cin >> s) {
        if (check(s)) {
            if (pos(s) == -1) {
                x[dem++].data = s;
                ++x[dem - 1].cnt;
            }
            else
                ++x[pos(s)].cnt;
        }
    }
    sort(x, x + dem, cmp);
    for (int i = 0; i < dem; i++)
        cout << x[i].data << " " << x[i].cnt << endl;
}