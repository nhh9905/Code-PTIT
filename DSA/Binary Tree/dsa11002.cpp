#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

typedef struct node {
	string data;
	node *left, *right;

	node (string x) {
		data = x;
		left = right = NULL;
	}
} node;

int n;
string s[1005];
vector<string> v;

node* buildTree(string s[], int n) {
	vector<node*> nodes;

	for (int i = 0; i < n; i++)
		nodes.push_back(new node(s[i]));

	for (int i = 0; i < n; i++) {
		int leftIdx = 2*i + 1, rightIdx = 2*i + 2;

		if (leftIdx < n)
			nodes[i]->left = nodes[leftIdx];
		if (rightIdx < n)
			nodes[i]->right = nodes[rightIdx];
	}

	return nodes[0];
}

void duyet(node *root) {
	if (root == NULL)
		return;

	duyet(root->left);
	duyet(root->right);
	v.push_back(root->data);
}

bool check(string x) {
	return x != "+" && x != "-" && x != "*" && x != "/";
}

ll calc(ll a, ll b, string c) {
	if (c == "+")
		return a + b;
	if (c == "-")
		return a - b;
	if (c == "*")
		return a * b;
	if (c == "/")
		return a / b;
	return 0;
}

void postfix() {
	stack<ll> st;

	for (string x:v) {
		if (check(x)) {
			ll k = stoll(x);
			st.push(k);
		}

		else {
			ll tmp1 = st.top(); st.pop();
			ll tmp2 = st.top(); st.pop();
			st.push(calc(tmp2, tmp1, x));
		}
	}

	cout << st.top() << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	int t; cin >> t;
	
	while (t--) {
		node *head = NULL;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		head = buildTree(s, n);

		duyet(head);
		postfix();
	}

	return 0;
}