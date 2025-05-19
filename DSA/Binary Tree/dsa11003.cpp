#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005], b[1005], idx[10005], curIdx;

typedef struct node {
	int data;
	node *left, *right;

	node (int x) {
		data = x;
		left = right = NULL;
	}
} node;

node* createBST(int b[], int l, int r) {
	if (l > r)
		return NULL;

	node *root = new node(b[curIdx]);
	
	int mid = idx[b[curIdx]];
	++curIdx;

	root->left = createBST(b, l, mid - 1);
	root->right = createBST(b, mid + 1, r);
	return root;
}

void postOrder(node *root) {
	if (root == NULL)
		return;

	if (root->left)
		postOrder(root->left);
	if (root->right)
		postOrder(root->right);
	cout << root->data << " ";
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
			cin >> a[i];
			idx[a[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}

		curIdx = 1;
		head = createBST(b, 1, n);
		postOrder(head);
		cout << endl;
	}

	return 0;
}