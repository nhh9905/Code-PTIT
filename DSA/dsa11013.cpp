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

map<int, node*> nodes;

bool isLeaf(node *root) {
    return root->left == NULL && root->right == NULL;
}

ll sum = 0;
void duyet(node *root) {
    if (root == NULL)
        return;

    if (root->left != NULL) {
        if (root->left != NULL && isLeaf(root->left))
            sum += root->left->data;
    }

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
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (!nodes[u])
                nodes[u] = new node(u);

            if (head == NULL)
                head = nodes[u];

            node *child = new node(v);

            if (c == 'L')
                nodes[u]->left = child;
            else
                nodes[u]->right = child;

            nodes[v] = child;
        }

        duyet(head);
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}