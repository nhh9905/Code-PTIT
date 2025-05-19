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

bool check = 1;

void duyet(node *root) {
	if (root == NULL || !check)
		return;

	if (root->left != NULL) {
		if (root->right == NULL) {
			check = 0;
			return;
		}
	}

	if (root->right != NULL) {
		if (root->left == NULL) {
			check = 0;
			return;
		}
	}

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

		duyet(head);

		cout << check << endl;
		check = 1;
	}

	return 0;
}