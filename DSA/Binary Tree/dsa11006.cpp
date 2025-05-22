#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct node {
    int data;
    node *left, *right;

    node (int x) {
        data = x;
        left = right = NULL;
    }
} node;

void add(node* &root, int u, int v, char c) {
    if (root->data == u) {
        if (c == 'L')
            root->left = new node(v);
        else
            root->right = new node(v);
        
        return;
    }

    if (root->left)
        add(root->left, u, v, c);
    if (root->right)
        add(root->right, u, v, c);
}

void spiralOrder(node *root) {
    map<int, vector<int>> ans;
    queue<pair<node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        node *tmp = q.front().fi;
        int level = q.front().se;
        q.pop();

        ans[level].push_back(tmp->data);

        if (tmp->left)
            q.push({tmp->left, level + 1});
        if (tmp->right)
            q.push({tmp->right, level + 1});
    }

    for (auto e:ans) {
        if (e.fi % 2) {
            for (int x:e.se)
                cout << x << " ";
        }
        else {
            for (int i = e.se.size() - 1; i >= 0; i--)
                cout << e.se[i] << " ";
        }
    }
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        node *head = NULL;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (head == NULL)
                head = new node(u);
            
            add(head, u, v, c);
        }

        spiralOrder(head);
        cout << endl;
    }

    return 0;
}