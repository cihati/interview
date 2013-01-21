#include <cstdio>
#include <cassert>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val, Node* next) : val(val), next(next) { }
};

void insertToHead(Node **root, int val) {
	*root = new Node(val, *root);
}

void printNodes(Node* root) {
	while (root) {
		printf("%d ", root->val);
		root = root->next;
	}
	printf("\n");
}

// Assume single linked list with no cycles.
// k should be a positive integer, where k == 1 returns the tail element.
// empty list OR invalid list, k pairs return NULL
Node* kthLast(Node *forward, int k) {
	if (forward == NULL || k <= 0) return NULL;
	Node *back = forward;
	while (--k) {
		forward = forward->next;
		if (forward == NULL) return NULL;
	}
	while (forward->next != NULL) {
		forward = forward->next;
		back = back->next;
	}
	return back;
}

void testKthLast() {
	Node *root = NULL;
	assert(kthLast(root, 0) == NULL);
	assert(kthLast(root, 1) == NULL);
	assert(kthLast(root, -1) == NULL);

	insertToHead(&root, 5);
	assert(kthLast(root, 0) == NULL);
	assert(kthLast(root, 2) == NULL);
	assert(kthLast(root, 1) == root);
	assert(kthLast(root, -1) == NULL);

	insertToHead(&root, 4);
	insertToHead(&root, 3);
	insertToHead(&root, 2);
	assert(kthLast(root, 0) == NULL);
	assert(kthLast(root, -1) == NULL);
	assert(kthLast(root, 5) == NULL);
	assert(kthLast(root, 4) == root);
	assert(kthLast(root, 3) == root->next);
	assert(kthLast(root, 2) == root->next->next);
	assert(kthLast(root, 1) == root->next->next->next);
}

int main() {
	testKthLast();
	return 0;
}
