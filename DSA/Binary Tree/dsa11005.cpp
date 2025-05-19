#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;

typedef struct node {
	int data;
	node *left, *right;

	node (int x) {
		data = x;
		left = right = NULL;
	}
} node;

int index(vector<int> a, int l, int r, int x) {
	for (int i = l; i <= r; i++) {
		if (a[i] == x)
			return i;
	}
	return -1;
}

node* createBST(vector<int> a, vector<int> b, int l, int r) {
	if (l > r)
		return NULL;

	int rootIdx, rootVal;
	for (int x:b) {
		int idx = index(a, l, r, x);

		if (idx != -1) {
			rootIdx = idx;
			rootVal = x;
			break;
		}
	}

	node *root = new node(rootVal);

	set<int> leftIn(a.begin() + l, a.begin() + rootIdx);
	vector<int> leftLevel, rightLevel;

	for (int i = 1; i < b.size(); i++) {
		if (leftIn.count(b[i]))
			leftLevel.push_back(b[i]);
		else
			rightLevel.push_back(b[i]);
	}

	root->left = createBST(a, leftLevel, l, rootIdx - 1);
	root->right = createBST(a, rightLevel, rootIdx + 1, r);

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
		vector<int> a(n), b(n);
		for (int &x:a) {
			cin >> x;
		}
		for (int &x:b) {
			cin >> x;
		}

		head = createBST(a, b, 0, n - 1);
		postOrder(head);
		cout << endl;
	}

	return 0;
}