#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SinhVien {
    private:
        string id, ten, lop, email;
    public:
        friend istream& operator >> (istream &in, SinhVien &a);
        friend ostream& operator << (ostream &out, SinhVien a);
        string getClass() {
            return lop;
        }
};
istream& operator >> (istream &in, SinhVien &a) {
    in >> a.id;
    scanf("\n");
    getline(in, a.ten);
    in >> a.lop >> a.email;
    return in;
}
bool cmp(SinhVien a, SinhVien b) {
    return a.getClass() < b.getClass();
}
void sapxep(SinhVien a[], int n) {
    sort(a, a + n, cmp);
}
ostream& operator << (ostream &out, SinhVien a) {
    out << a.id << " " << a.ten << " " << a.lop << " " << a.email << endl;
    return out;
}
int main() {
    // freopen("a.inp", "r", stdin);
    int n;
    cin >> n;
    SinhVien a[1005];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sapxep(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i];
}