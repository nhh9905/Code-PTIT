#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // freopen("a.inp", "r", stdin);
    string s;
    while (getline(cin >> ws, s)) {
        stringstream ss(s);
        string tmp;
        vector<string> v;
        while (ss >> tmp) {
            int k = tmp.size() - 1;
            v.push_back(tmp);
            if (tmp[k] == '.' || tmp[k] == '?' || tmp[k] == '!') {
                v[0][0] = (char)toupper(v[0][0]);
                for (int i = 1; i < v[0].size(); i++)
                    v[0][i] = (char)tolower(v[0][i]);
                cout << v[0] << " ";
                for (int i = 1; i < v.size(); i++) {
                    for (int j = 0; j < v[i].size(); j++)
                        v[i][j] = (char)tolower(v[i][j]);
                    if (i == v.size() - 1) {
                        if (v[i].back() == '.' || v[i].back() == '?' || v[i].back() == '!')
                            v[i].pop_back();
                    }
                    cout << v[i] << " ";
                }
                v.clear();
                cout << endl;
            }
        }
    }
}