#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct node {
    int data, level;
    node *left, *right, *par;

    node (int x, int lev) {
        data = x;
        level = lev;
        left = right = par = NULL;
    }
} node;

vector<node*> leaves;

void add(node* &root, int u, int v, char c) {
    if (root->data == u) {
        if (c == 'L') {
            root->left = new node(v, root->level + 1);
            root->left->par = root;
        }
        else {
            root->right = new node(v, root->level + 1);
            root->right->par = root;
        }
        return;
    }
    
    if (root->left)
        add(root->left, u, v, c);
    if (root->right)
        add(root->right, u, v, c);
}

void leaf(node *root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        leaves.push_back(root);

    leaf(root->left);
    leaf(root->right);
}

int path(node* root1, node* root2) {
    int sum = 0;

    while (root1 != root2) {
        if (root1->level < root2->level) {
            sum += root2->data;
            root2 = root2->par;
        }
        else {
            if (root1->level > root2->level) {
                sum += root1->data;
                root1 = root1->par;
            }
            else {
                sum += root1->data + root2->data;
                root1 = root1->par;
                root2 = root2->par;
            }
        }
    }

    return sum + root1->data;
}

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("a.inp", "r", stdin);

    int t; cin >> t;

    while (t--) {
        int ans = -1e9;
        node *head = NULL;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (head == NULL)
                head = new node(u, 0);

            add(head, u, v, c);
        }

        leaf(head);

        for (int i = 0; i < leaves.size() - 1; i++) {
            for (int j = i + 1; j < leaves.size(); j++) {
                ans = max(ans, path(leaves[i], leaves[j]));
            }
        }

        cout << ans << endl;

        leaves.clear();
    }

    return 0;
}