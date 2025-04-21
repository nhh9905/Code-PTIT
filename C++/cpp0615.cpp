#include <bits/stdc++.h>
using namespace std;
int cnt=1;
void chuanhoa(string &s){
	if(s[2] != '/') s="0"+s;
	if(s[5] != '/' ) s.insert(3,"0");
}
void chuanhoaTen(string &s) {
    stringstream ss(s);
    string word, result = "";
    while (ss >> word) {
        word[0] = toupper(word[0]);
        for (size_t i = 1; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        result += word + " ";
    }
    s = result.substr(0, result.size() - 1);
}
class SinhVien{
	private:
		string stt,ten,ma,ns;
		float gpa;
	public:
		SinhVien(){}
		SinhVien(string stt,string ten,string ma,string ns,float gpa){
			this->ten=ten;
			this->ma=ma;
			this->ns=ns;
			this->gpa=gpa;
		}
		float getGPA() const {
            return gpa;
        }
		friend istream& operator>>(istream& is,SinhVien& a){
			string t=to_string(cnt);
			cnt++;
			a.stt="B20DCCN"+string(3-t.size(),'0')+t;
			getline(is>>ws,a.ten);
			getline(is,a.ma);
			getline(is,a.ns);
			cin>>a.gpa;
			chuanhoa(a.ns);
			chuanhoaTen(a.ten);
			return is;
		}
		friend ostream& operator<<(ostream& os,SinhVien a){
			os<<a.stt<<" "<<a.ten<<" "<<a.ma<<" "<<a.ns<<" "<<fixed<<setprecision(2)<<a.gpa<<endl;
			return os;
		}
};
void sapxep(SinhVien ds[], int N) {
    sort(ds, ds + N, [](const SinhVien &a, const SinhVien &b) {
        return a.getGPA() > b.getGPA();
    });
}
int main(){
    freopen("a.inp", "r", stdin);
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