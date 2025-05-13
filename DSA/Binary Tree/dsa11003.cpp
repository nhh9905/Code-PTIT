#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, a[1005], b[1005], len;

typedef struct node {
	int data;
	struct node *left, *right;
} *Tree;

void init(Tree *T) {
	*T = NULL;
}

Tree getNode() {
	Tree p;
	p = new node;
	return p;
}

Tree makeNode(int x) {
	Tree p;
	p = getNode();
	p->data = x;
	p->left = p->right = NULL;
	return p;
}

// Tim node p co noi dung la x tren cay
Tree search(Tree T, int x) {
	if (T == NULL)
		return NULL;

	if (T->data == x)
		return T;

	Tree p = search(T->left, x);
	if (p == NULL)
		p = search(T->right, x);
	return p;
}

// Tao node la ben trai node x
void addLeft(Tree T, int x, int y) {
	Tree p, q;
	p = search(T, x);
	if (p == NULL) {
		cout << "Khong tim thay node " << x << endl;
		return;
	}
	else {
		if ((p->left) != NULL) {
			cout << "Node " << x << " co nhanh cay con trai\n";
			return;
		}
		else {
			q = makeNode(y);
			p->left = q;
		}
	}
}

// Tao node la ben phai node x
void addRight(Tree T, int x, int y) {
	Tree p, q;
	p = search(T, x);
	if (p == NULL) {
		cout << "Khong tim thay node " << x << endl;
		return;
	}
	else {
		if ((p->right) != NULL) {
			cout << "Node " << x << " co nhanh cay con phai\n";
			return;
		}
		else {
			q = makeNode(y);
			p->right = q;
		}
	}
}

void LRN(Tree T) {
	if (T != NULL) {
		LRN(T->left);
		LRN(T->right);
		cout << T->data << " ";
	}
}

int Size(Tree T) {
	if (T == NULL)
		return 0;
	return Size(T->left) + 1 + Size(T->right);
}

void makeTree(Tree *T, int u, int cnt) {
	int idx = 0;

	while (cnt != len) {
		++idx;
		addLeft(*T, u, b[idx]);
		if (cnt != len)
			makeTree(T, b[idx], ++cnt);
		else
			return;
	}

	while (cnt != len) {
		++idx;
		addRight(*T, u, b[idx]);
		if (cnt != len)
			makeTree(T, b[idx], ++cnt);
		else
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n;
		Tree T;
		init(&T);

		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];

		len = (int)sqrt(n);

		if (T == NULL)
			T = makeNode(b[1]);

		makeTree(&T, b[1], 0);

		LRN(T);
	}

	return 0;
}