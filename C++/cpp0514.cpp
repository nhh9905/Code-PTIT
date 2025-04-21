#include <bits/stdc++.h>
using namespace std;
typedef struct SinhVien {
	string ten, lop, ns;
	float gpa;
} SinhVien;
void nhap(SinhVien ds[], int n) {
	for (int i = 1; i <= n; i++) {
		cin.ignore();
		getline(cin, ds[i].ten);
		cin >> ds[i].lop >> ds[i].ns >> ds[i].gpa;
	}
}
void in(SinhVien ds[], int n) {
	for (int i = 1; i <= n; i++) {
		int dem = 0;
		cout << "B20DCCN";
		if (to_string(i).size() == 1)
			cout << "00" << to_string(i) << " ";
		else
			cout << "0" << to_string(i) << " ";
		stringstream ss(ds[i].ten);
		string tmp;
		while (ss >> tmp) {
			cout << (char)toupper(tmp[0]);
			for (int i = 1; i < tmp.size(); i++)
				cout << (char)tolower(tmp[i]);
			cout << " ";
		}
		cout << ds[i].lop << " ";
		for (int j = 0; j < ds[i].ns.size(); j++) {
			if (ds[i].ns[j] != '/')
				++dem;
			else {
				if (dem == 1)
					ds[i].ns.insert(j - 1, "0");
				dem = 0;
			}
		}
		cout << ds[i].ns << " " << fixed << setprecision(2) << ds[i].gpa << endl;
	}
}
int main() {
//	freopen("a.inp", "r", stdin);
	struct SinhVien ds[50];
    int N;
    cin >> N;
    nhap(ds, N);
    in(ds, N);
    return 0;
}
