#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005], cnt = 0;

typedef struct node {
	int data;
	node *left, *right;

	node (int x) {
		data = x;
		left = right = NULL;
	}
} node;

node* createBST(int a[], int l, int r) {
	if (l > r)
		return NULL;
	int mid = (l + r)/2;

	node *root = new node(a[mid]);
	root->left = createBST(a, l, mid - 1);
	root->right = createBST(a, mid + 1, r);
	return root;
}

void duyet(node *root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		cnt++;
	}

	if (root->left)
		duyet(root->left);
	if (root->right)
		duyet(root->right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cnt = 0;
		node *head = NULL;

		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + 1 + n);

		head = createBST(a, 1, n);
		duyet(head);
		cout << cnt << endl;
	}

	return 0;
}