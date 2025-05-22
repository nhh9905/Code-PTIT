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

void postOrder(node *root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << " ";
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
            int x; cin >> x;
            add(head, x);
        }

        postOrder(head);
        cout << endl;
    }

    return 0;
}