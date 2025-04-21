#include <bits/stdc++.h>
#define ll long long
using namespace std;
class SinhVien {
    private:
        string id, ten, lop, ns;
        double gpa;
        static int dem;
    public:
        friend istream& operator >> (istream &in, SinhVien &a); 
        friend ostream& operator << (ostream &out, SinhVien a);
        double getGpa() {
        	return gpa;
		}
};
int SinhVien::dem = 0;
istream& operator >> (istream &in, SinhVien &a) {
    scanf("\n");
    getline(in, a.ten);
    in >> a.lop >> a.ns >> a.gpa;
    ++SinhVien::dem;
    a.id = "B20DCCN" + string(3 - to_string(SinhVien::dem).size(), '0') + to_string(SinhVien::dem);
    return in;
}
bool cmp(SinhVien a, SinhVien b) {
	return a.getGpa() > b.getGpa();
}
void sapxep(SinhVien a[], int n) {
	sort(a, a + n, cmp);
}
ostream& operator << (ostream &out, SinhVien a) {
    out << a.id << " ";
    stringstream ss(a.ten);
    string tmp;
    while (ss >> tmp) {
        cout << (char)toupper(tmp[0]);
        for (int i = 1; i < tmp.size(); i++)
            cout << (char)tolower(tmp[i]);
        cout << " ";
    }
    out << a.lop << " ";
    int cnt = 0;
    for (int i = 0; i < a.ns.size(); i++) {
        if (a.ns[i] != '/')
            ++cnt;
        else {
            if (cnt == 1)
                a.ns.insert(i - 1, "0");
            cnt = 0;
        }
    }
    out << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}
int main() {
//    freopen("a.inp", "r", stdin);
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    sapxep(ds, N);
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}
