#include <bits/stdc++.h>
#define ll long long
using namespace std;
void get_min(int m, int s) {
    int k = m;
    stack<int> st;
    while (s) {
        if (s > 9) {
            st.push(9);
            s -= 9;
        }
        else {
            if (m == 1)
                st.push(s);
            else
                st.push(s - 1);
            s = 0;
        }
        --m;
    }
    --m;
    while (m > 0) {
        st.push(0);
        --m;
    }
    while (st.size() < k)
        st.push(1);
    while (st.size()) {
        cout << st.top();
        st.pop();
    }
    cout << " ";
}
void get_max(int m, int s) {
    while (s) {
        if (s > 9) {
            cout << 9;
            s -= 9;
        }
        else {
            cout << s;
            s = 0;
        }
        --m;
    }
    while (m > 0) {
        cout << 0;
        --m;
    }
}
int main() {
    int m, s;
    cin >> m >> s;
    if (s > 9*m || s < 1) {
        cout << "-1 -1";
        return 0;
    }
    get_min(m, s);
    get_max(m, s);
}