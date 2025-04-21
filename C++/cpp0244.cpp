#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    set<int> s;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int x:s)
        cout << x << " ";
}