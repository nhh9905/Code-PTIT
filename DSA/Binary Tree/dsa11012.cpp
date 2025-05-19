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

vector<int> v1, v2;
void duyet(node *root, vector<int> &v) {
	if (root == NULL)
		return;

	v.push_back(root->data);
	duyet(root->left, v);
	duyet(root->right, v);
}

bool check(vector<int> v1, vector<int> v2) {
	if (v1.size() != v2.size())
		return 0;

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i])
			return 0;
	}

	return 1;
}

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		node *head = NULL, *head1 = NULL;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;

			if (head == NULL)
				head = new node(u);

			add(head, u, v, c);
		}

		cin >> m;
		for (int i = 1; i <= m; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;

			if (head1 == NULL)
				head1 = new node(u);

			add(head1, u, v, c);
		}

		duyet(head, v1);
		duyet(head1, v2);

		if (check(v1, v2))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}