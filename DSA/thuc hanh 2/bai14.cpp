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

void duyet(node *root) {
	map<int, vector<int>> res;
	queue<pair<node*, int>> q;
	q.push({root, 0});

	while (!q.empty()) {
		node* tmp = q.front().fi;
		int level = q.front().se;
		q.pop();

		res[level].push_back(tmp->data);

		if (tmp->left)
			q.push({tmp->left, level + 1});
		if (tmp->right)
			q.push({tmp->right, level + 1});
	}

	for (auto e:res) {
		for (int i = e.se.size() - 1; i >= 0; i--)
			cout << e.se[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		node *head = NULL;
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			add(head, x);
		}

		duyet(head);
	}

	return 0;
}