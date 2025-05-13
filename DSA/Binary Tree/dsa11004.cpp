#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct node {
	int data;
	struct node *left, *right;
} *Tree;

// Khoi tao cay nhi phan
void init(Tree *T) {
	*T = NULL;
}

// Cap phat mien nho cho 1 node
Tree getNode() {
	Tree p;
	p = new node;
	return p;
}

// Tao 1 node cho cay T
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

void levelOrder(Tree T) {
	if (T == NULL)
		return;
	queue<Tree> q;
	q.push(T);

	while (!q.empty()) {
		Tree x = q.front(); q.pop();
		cout << x->data << " ";

		if (x->left != NULL)
			q.push(x->left);
		if (x->right != NULL)
			q.push(x->right);
	}
}

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		cin >> n;
		Tree T;
		init(&T);
		
		for (int i = 1; i <= n; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;

			if (T == NULL)
				T = makeNode(u);
			
			if (c == 'L')
				addLeft(T, u, v);
			else
				addRight(T, u, v);
		}

		levelOrder(T);
		cout << endl;
	}

	return 0;
}