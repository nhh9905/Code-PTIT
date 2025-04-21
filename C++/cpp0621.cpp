#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SinhVien {
    private:
        string ma, ten, lop, email;
    public:
        int nhap() {
            if (!(cin >> ma))
                return -1;
            getline(cin >> ws, ten);
            if (!(cin >> lop >> email))
                return -1;
            return 0;
        }
        string getMa() {
            return ma;
        }
        void in() {
            cout << ma << " " << ten << " " << lop << " " << email << endl;
        }
};
vector<SinhVien> v;
bool cmp(SinhVien a, SinhVien b) {
    return a.getMa() < b.getMa();
}
void solve() {
    SinhVien a;
    while (a.nhap() != -1) {
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    for (SinhVien x:v)
        x.in();
}
int main() {
    // freopen("a.inp", "r", stdin);
    solve();
    return 0;
}