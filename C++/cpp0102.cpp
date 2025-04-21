#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        if (c >= 'A' && c <= 'Z')
            cout << (char)tolower(c) << endl;
        else
            cout << (char)toupper(c) << endl;
    }
}