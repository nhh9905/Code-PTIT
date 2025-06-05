#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define endl "\n"
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

int val(node *root) {
    if (root == NULL)
        return 0;
    return root->data;
}

bool check(node *root) {
    if (root == NULL)
        return 0;

    int data = root->data;
    int sum_l = val(root->left), sum_r = val(root->right);

    if (sum_l + sum_r == data)
        return 1;

    return check(root->left) && check(root->right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        node *head = NULL;
        int n; cin >> n;

        for (int i = 1; i <= n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (head == NULL)
                head = new node(u);
            add(head, u, v, c);
        }

        cout << check(head) << endl;
    }

    return 0;
}