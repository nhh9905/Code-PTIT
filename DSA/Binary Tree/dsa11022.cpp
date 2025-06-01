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

void add(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }

    if (root->data > x)
        add(root->left, x);
    if (root->data < x)
        add(root->right, x);
}

bool isLeaf(node *root) {
    return root->left == NULL && root->right == NULL;
}

int cnt = 0;

void duyet(node *root) {
    if (root == NULL)
        return;

    if (!isLeaf(root))
        ++cnt;
    
    duyet(root->left);
    duyet(root->right);
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        cnt = 0;
        node *head = NULL;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            add(head, x);
        }

        duyet(head);
        cout << cnt << endl;
    }

    return 0;
}