#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, cntLeft = 0, cntRight = 0;

typedef struct node {
	int data;
	node *left, *right;

	node (int x) {
		data = x;
		left = right = NULL;
	}
} node;

void add(node* &root, int u, int v, char c) {
	if (root == NULL) {
		return;
	}

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

int Size(node* root) {
	if (root == NULL)
		return 0;
	return Size(root->left) + 1 + Size(root->right);
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
			int u, v;
			char c;
			cin >> u >> v >> c;

			if (head == NULL)
				head = new node(u);

			add(head, u, v, c);
		}

		if (Size(head->left) == Size(head->right))
			cout << "1\n";
		else
			cout << "0\n";

		// cout << Size(head->left) << " " << Size(head->right) << endl;
	}

	return 0;
}