#include <bits/stdc++.h>
#define ll long long
using namespace std;
class GiangVien {
    private:
        string ma, ten, mon;
        static int dem;
    public:
        void nhap();
        string getMon() {
            return mon;
        }
        void in();
};
int GiangVien::dem = 0, n;
GiangVien a[105];
void GiangVien::nhap() {
    getline(cin >> ws, this->ten);
    getline(cin >> ws, this->mon);
    GiangVien::dem++;
    this->ma = "GV" + string("0", 2 - to_string(GiangVien::dem).size()) + to_string(GiangVien::dem);
}
void printInformation(string s) {
    cout << "DANH SACH GIANG VIEN BO MON ";
    stringstream ss(s);
    string tmp, res = "";
    while (ss >> tmp) {
        res += (char)toupper(tmp[0]);
    }
    cout << res << ":\n";
    for (int i = 0; i < n; i++) {
        if (a[i].getMon() == s) {
            a[i].in();
            cout << res << endl;
        }
    }
}
void GiangVien::in() {
    cout << this->ma << " " << this->ten << " ";
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].nhap();
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        printInformation(s);
    }
}
int main() {
    // freopen("a.inp", "r", stdin);
    solve();
    return 0;
}