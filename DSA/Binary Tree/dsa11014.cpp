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

int n;
map<int, node*> nodes;

int sumRightLeaves(node *root) {
	if (root == NULL)
		return 0;

	int sum = 0;
	if (root->right) {
		if (root->right != NULL && root->right->left == NULL && root->right->right == NULL)
			sum += root->right->data;
		else
			sum += sumRightLeaves(root->right);
	}

	sum += sumRightLeaves(root->left);

	return sum;
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

		cout << sumRightLeaves(head) << endl;
	}

	return 0;
}