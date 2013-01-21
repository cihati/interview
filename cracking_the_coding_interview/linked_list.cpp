//unfinished
#include <iostream>

using namespace std;

class Node
{
	Node* next;
	int v;
};

Node* head = NULL;

bool InsertElement(int n)
{
	if (head == NULL)
	{
		head = new Node;
		if (head == NULL)
			return false;
		head->next = NULL;
		head->v = n;
	}
	else
	{
		Node* var = new Node;
		if (var == NULL)
			return false;
		var->next = head;
		var->v = n;
		head = var;
	}
	return true;
}

void
int main()
{
	InsertElement(5);
	return 0;
}
