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
};
int SinhVien::dem = 0;
istream& operator >> (istream &in, SinhVien &a) {
    in.ignore();
    getline(in, a.ten);
    in >> a.lop >> a.ns >> a.gpa;
    return in;
}
ostream& operator << (ostream &out, SinhVien a) {
    ++SinhVien::dem;
    a.id = "B20DCCN" + string(3 - to_string(SinhVien::dem).size(), '0') + to_string(SinhVien::dem);
    out << a.id << " " << a.ten << " " << a.lop << " ";
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
int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}