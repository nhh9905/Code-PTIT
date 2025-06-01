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

int n;

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

void duyet(node *root) {
    if (root == NULL)
        return;
    
    cout << root->data << " ";
    
    duyet(root->left);
    duyet(root->right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        node *head = NULL;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;

            add(head, x);
        }

        duyet(head);
        cout << endl;
    }

    return 0;
}