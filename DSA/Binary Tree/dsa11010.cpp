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

int n, cnt[10005], depth = 0;

void add(node* &root, int u, int v, int c) {
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

void duyet(node *root, int level) {
	if (root == NULL)
		return;

	++cnt[level];
	depth = max(depth, level);

	duyet(root->left, level + 1);
	duyet(root->right, level + 1);
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

		bool check = 1;
		depth = 0;
		duyet(head, 0);

		for (int i = 0; i <= depth; i++) {
			if (cnt[i] != pow(2, i)) {
				check = 0;
				break;
			}
		}

		cout << (check ? "Yes" : "No") << endl;

		check = 1;
		memset(cnt, 0, sizeof cnt);
	}

	return 0;
}