#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        vector<string> v;
        while (ss >> tmp) {
            tmp[0] = (char)toupper(tmp[0]);
            for (int i = 1; i < tmp.size(); i++)
                tmp[i] = (char)tolower(tmp[i]);
            v.push_back(tmp);
        }
        if (n == 1) {
            cout << v[v.size() - 1] << " ";
            for (int i = 0; i < v.size() - 1; i++)
                cout << v[i] << " ";
            cout << endl;
        }
        else {
            for (int i = 1; i < v.size(); i++)
                cout << v[i] << " ";
            cout << v[0] << endl;
        }
    }
}