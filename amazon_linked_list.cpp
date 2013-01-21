// AWS Interview Question - find a common node of two linked lists.
// Asked by Gregory Ignatov.
// Solution coded by Cihat Imamoglu (cihat.imamoglu@gmail.com) November 7, 2012.
#include <cstdio>
#include <cassert>
#include <map>
using namespace std;

// Since the main aspect of the problem is algorithms, I use an extremely simple
// linked list implementation.
struct Node {
  Node *next;
  int val;

  Node(int value = 0, Node* next = NULL) : val(value), next(next) {}
};

int getLength(Node* head) {
  Node* node = head;
  int count = 0;
  while (node != NULL) {
    ++count;
    node = node->next;
  }
  return count;
}

/**
 * Finds the first common node of two linked lists.
 * 
 * The worst case time complexity of this method is
 * O(n * log(n) + m * log(n + m)), where n is the number of elements in the
 * first list, and m is the number of elements in the second list. The
 * logarithmic factor comes from the fact that STL uses red-black trees for
 * map implementation. If hash tables were used, log factors would vanish
 * in the average case, since lookups are constant time. The space extra
 * complexity is O(n).
 * @param list1 The pointer to the head of the first list.
 * @param list2 The pointer to the head of the second list.
 * @returns If a common node exists, a pointer to it. {@code NULL} otherwise.
 */
Node* findCommon1(Node* list1, Node* list2) {
  // Put all pointers to the nodes of list1 into a map. If a node from list2
  // has already been added before, return it.

  // For the sake of brevity, I allocate the map within the stack.
  // In production, it's better to allocate from the heap, since it is much
  // bigger and there is no risk of stack overflow.
  map<Node*, bool> nodeMap;
  while (list1 != NULL) {
    nodeMap[list1] = true;
    list1 = list1->next;
  }
  while (list2 != NULL) {
    if (nodeMap[list2]) {
      return list2;
    }
    list2 = list2->next;
  }
  return NULL;
}

/**
 * Finds the first common node of two linked lists.
 * 
 * The worst case time complexity of this method is O(n * m), where n is the
 * number of elements in the first list, and m is the number of elements in
 * the second list. The extra space complexity is O(1).
 * @param list1 The pointer to the head of the first list.
 * @param list2 The pointer to the head of the second list.
 * @returns If a common node exists, a pointer to it. {@code NULL} otherwise.
 */
Node* findCommon2(Node* list1, Node* list2) {
  // For each element of list1, check if it exists in list2.
  Node* list2Pos = list2;
  while (list1 != NULL) {
    while (list2 != NULL && list2 != list1) {
      list2 = list2->next;
    }
    if (list1 == list2) {
      return list1;
    }
    list1 = list1->next;
    list2 = list2Pos;
  }
  return NULL;
}

/**
 * Finds the first common node of two linked lists.
 * 
 * The worst case time complexity of this method is O(n + m), where n is the
 * number of elements in the first list, and m is the number of elements in
 * the second list. The extra space complexity is O(1).
 * @param list1 The pointer to the head of the first list.
 * @param list2 The pointer to the head of the second list.
 * @returns If a common node exists, a pointer to it. {@code NULL} otherwise.
 */
Node* findCommon3(Node* list1, Node* list2) {
  // This is the best solution I could come up. Let's say n = x + y, m = z + y.
  // In this equation, y is the number of elements common to the both lists.
  // If we start looking for the last min(n, m) elements by advancing
  // simultaneously two pointers, we can definitely find the first common element,
  // if one exists.
  int n = getLength(list1);
  int m = getLength(list2);
  while (n > m) {
    list1 = list1->next;
    --n;
  }
  while (m > n) {
    list2 = list2->next;
    --m;
  }
  while (list1 != NULL and list2 != NULL) {
    if (list1 == list2) {
      return list1;
    } else {
      list1 = list1->next;
      list2 = list2->next;
    }
  }
  return NULL;
}

/////////////////////////// TESTS ///////////////////////////

/*
 * Tests {@code findCommon} with two lists without a common element.
 */
void testFindCommonWithTwoListsWithoutCommonElement(
    Node* (*func) (Node*, Node*)) {
  Node* list1 = new Node(5, new Node(8));
  Node* list2 = new Node(4, new Node(8, new Node(9)));
  assert(NULL == func(list1, list2));
}

/*
 * Tests {@code findCommon} with two lists with a common element, and the
 * common element has a next node.
 */
void testFindCommonWithTwoListsWithCommonElement2(
    Node* (*func) (Node*, Node*)) {
  Node* commonNode = new Node(66, new Node(99));
  Node* list1 = new Node(5, new Node(8, commonNode));
  Node* list2 = new Node(4, commonNode);
  assert(commonNode == func(list1, list2));
}

/*
 * Tests {@code findCommon} with two lists with a common element.
 */
void testFindCommonWithTwoListsWithCommonElement(
    Node* (*func) (Node*, Node*)) {
  Node* commonNode = new Node(66);
  Node* list1 = new Node(5, new Node(8, commonNode));
  Node* list2 = new Node(4, commonNode);
  assert(commonNode == func(list1, list2));
}

/*
 * Tests {@code findCommon} with one empty and one non-empty list.
 */
void testFindCommonWithOneEmptyList(Node* (*func) (Node*, Node*)) {
  Node* list1 = NULL;
  Node* list2 = new Node(4, new Node(6));
  assert(NULL == func(list1, list2));
}

/*
 * Tests {@code findCommon} with two empty lists.
 */
void testFindCommonWithTwoEmptyLists(Node* (*func) (Node*, Node*)) {
  Node* list1 = NULL;
  Node* list2 = NULL;
  assert(NULL == func(list1, list2));
}

void testFindCommon(Node* (*func) (Node*, Node*)) {
  testFindCommonWithOneEmptyList(func);
  testFindCommonWithTwoEmptyLists(func);
  testFindCommonWithTwoListsWithCommonElement(func);
  testFindCommonWithTwoListsWithCommonElement2(func);
  testFindCommonWithTwoListsWithoutCommonElement(func);
}

int main() {
  testFindCommon(findCommon1);
  testFindCommon(findCommon2);
  testFindCommon(findCommon3);
  return 0;
}
