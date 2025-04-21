#include <bits/stdc++.h>
#define ll long long
using namespace std;

int BS(vector<int> a, int l, int r, int k) {
    if (l <= r) {
        int mid = (l + r)/2;
        if (a[mid] == k)
            return mid;
        if (a[mid] < k)
            return BS(a, mid + 1, r, k);
        if (a[mid] > k)
            return BS(a, l, mid - 1, k);
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int &x:a)
            cin >> x;
        
        if (BS(a, 0, a.size() - 1, k) == -1)
            cout << "NO";
        else
            cout << BS(a, 0, a.size() - 1, k) + 1;
        cout << endl;
    }

    return 0;
}