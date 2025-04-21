#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
struct NhanVien {
    string ten, gt, ns, dc, mst, nkhd, manv;
};
typedef struct NhanVien NhanVien;
void nhap(NhanVien &x) {
	++cnt;
    cin.ignore();
    getline(cin, x.ten);
    cin >> x.gt;
    cin >> x.ns;
    cin.ignore();
    getline(cin, x.dc);
    cin >> x.mst;
    cin >> x.nkhd;
    if (cnt <= 9)
        x.manv = "0000" + to_string(cnt);
    else
        x.manv = "000" + to_string(cnt);
}
void inds(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ds[i].manv << " " << ds[i].ten << " " << ds[i].gt << " " << ds[i].ns << " " << ds[i].dc << " " << ds[i].mst << " " << ds[i].nkhd << endl;
    }
}
int main() {
    //freopen("a.inp", "r", stdin);
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}
