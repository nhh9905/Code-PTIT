#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

struct node {
    int data;
    node *left, *right;

    node (int x) {
        data = x;
        left = right = NULL;
    }
};
typedef struct node node;

void buildTree(node *&head, int u, int v, char c) {
    if (head == NULL)
        return;
    
    if (head->data == u) {
        if (c == 'L')
            head->left = new node(v);
        else
            head->right = new node(v);
        return;
    }

    if (head->left)
        buildTree(head->left, u, v, c);
    if (head->right)
        buildTree(head->right, u, v, c);
}

void duyet(node *root, vector<int> &v) {
    if (root == NULL)
        return;
    
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        node *top = q.front(); q.pop();

        v.push_back(top->data);

        if (top->right)
            q.push(top->right);
        if (top->left)
            q.push(top->left);
    }
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        cin >> n;
        node *head = NULL;

        for (int i = 1; i <= n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (head == NULL)
                head = new node(u);
            
            buildTree(head, u, v, c);
        }

        vector<int> v;
        duyet(head, v);

        reverse(begin(v), end(v));
        for (int x:v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}