#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
vector<int> v;
struct node {
	int num;
	node *next;
};
typedef struct node node;

node *makeNode(int x) {
	node *newNode = new node();
	newNode->num = x;
	newNode->next = NULL;
	return newNode;
}

void pushBack(node **head, int x) {
	node *newNode = makeNode(x);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	node *tmp = *head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

void popFront(node **head) {
	if (*head == NULL)
		return;

	node *tmp = *head;
	*head = (*head)->next;
	delete tmp;
	tmp = NULL;
}

int count(node *head) {
	int cnt = 0;

	while (head != NULL) {
		++cnt;
		head = head->next;
	}

	return cnt;
}

void duyet(node **head) {
	while ((*head) != NULL) {
		if (find(v.begin(), v.end(), (*head)->num) != v.end()) {
			popFront(head);
		}
		else {
			cout << (*head)->num << " ";
			v.push_back((*head)->num);
			*head = (*head)->next;
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen("a.inp", "r", stdin);

	cin >> n;
	node *head = NULL;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pushBack(&head, x);
	}

	duyet(&head);

	return 0;
}