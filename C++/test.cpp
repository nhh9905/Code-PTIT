//CPP0319
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void get_min(int m, int s) {
    vector<int> v(m, 0);
    s -= 1;
    for (int i = m - 1; i >= 0; i--) {
        if (s > 9) {
            v[i] = 9;
            s -= 9;
        }
        else {
            v[i] = s;
            s = 0;
        }
    }
    v[0] += 1;
    for (int x:v)
        cout << x;
    cout << " ";
}
void get_max(int m, int s) {
    while (s) {
        if (s > 9) {
            cout << 9;
            s -= 9;
        }
        else {
            cout << s;
            s = 0;
        }
        --m;
    }
    while (m > 0) {
        cout << 0;
        --m;
    }
}
int main() {
    int m, s;
    cin >> m >> s;
    if (s > 9*m || s < 1) {
        cout << "-1 -1";
        return 0;
    }
    get_min(m, s);
    get_max(m, s);
}