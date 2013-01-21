#include <cstdio>
#include <cassert>
using namespace std;

struct Node {
	Node *left, *right;
	int val;
	Node(int val, Node* left, Node* right) :
		val(val), left(left), right(right) {}
};

bool isSameStructure(Node *root1, Node *root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 != NULL && root2 != NULL) {
		return isSameStructure(root1->left, root2->left) &&
			    isSameStructure(root1->right, root2->right);
	} else return false;
}

bool isMirroredStructure(Node *root1, Node *root2) {
	if (root1 == NULL && root2 == NULL) return true;
	// if (((root1 == NULL) ^ (root2 == NULL))) return false;
	if (((root1 == NULL) && (root2 != NULL)) ||
		 ((root1 != NULL) && (root2 == NULL))) return false;
	return isMirroredStructure(root1->left, root2->left) && isMirroredStructure(root1->right, root2->right) ||
		    isMirroredStructure(root1->left, root2->right) && isMirroredStructure(root1->right, root2->left);	
}

void countMinMoves(Node *root1, Node *root2, int& count, bool& possible) {
	if (root1 == NULL && root2 == NULL) {
		count = 0;
		possible = true;
		return;
	}
	if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) {
		possible = false;
		return;
	}
	int moveCount1 = 0, moveCount2 = 0;
	bool possible1, possible2;
	countMinMoves(root1->left, root2->left, moveCount1, possible);
	countMinMoves(root1->right, root2->right, moveCount2, possible);

}

int minMoves(Node *root1, Node *root2) {
	int moveCount = 0;
	bool possible = false;
	countMinMoves(root1, root2, moveCount, possible);
	if (possible)
		return moveCount;
	else
		return INT_MAX;
}

int main() {

	return 0;
}
