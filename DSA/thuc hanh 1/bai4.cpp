#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, x[25];
char c;

bool check(char c) {
    int cnt = 1, cnt1 = 1, max_cnt = INT_MIN, max_cnt_1 = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (!x[i] && !x[i + 1])
            ++cnt;
        else
            cnt = 1;
        max_cnt = max(max_cnt, cnt);
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 1 && x[i + 1] == 1)
            ++cnt1;
        else
            cnt1 = 1;
        max_cnt_1 = max(max_cnt_1, cnt1);
    }

    if (c == 'O') {
        if (max_cnt >= 5 && max_cnt > max_cnt_1)
            return 1;
        return 0;
    }
    if (c == 'X') {
        if (max_cnt_1 >= 5 && max_cnt_1 > max_cnt)
            return 1;
        return 0;
    }
    return 1;
}

void print() {
    for (int i = 1; i <= n; i++) {
        if (!x[i])
            cout << "O";
        else
            cout << "X";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            if (check(c))
                print();
        }
        else
            Try(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> c;
        Try(1);
    }

    return 0;
}