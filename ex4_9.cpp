//Imagine a linked list where instead of the node storing a character, the node
//stores a digit: an int in the range 0–9. We could represent positive numbers
//of any size using such a linked list; the number 149, for example, would be a
//linked list in which the first node stores a 1, the second a 4, and the third and
//last a 9. Write a function intToList that takes an integer value and produces a
//linked list of this sort. Hint: You may find it easier to build the linked list
//backward, so if the value were 149, you would create the 9 node first.
//4-10. For the digit list of the previous exercise, write a function that takes two such
//lists and produces a new list representing their sum.

#include <iostream>
using namespace std;

struct listNode {
	int oneInteger;
	listNode* next;
};

typedef listNode* listInteger;

void intToList(listInteger& listInt, int number) {
	int dividend = number, remainder = 0;

	while (dividend != 0) {
		remainder = dividend % 10;
		dividend = dividend / 10;
		if (listInt == NULL) {
			listNode* newNode = new listNode;
			newNode->oneInteger = remainder;
			newNode->next = NULL;
			listInt = newNode;
		}
		else {
			listNode* loopPtr = listInt;
			while (loopPtr->next != NULL)
				loopPtr = loopPtr->next;

			listNode* newNode = new listNode;
			newNode->oneInteger = remainder;
			newNode->next = NULL;
			loopPtr->next = newNode;
		}
	}
}


void addNode(listInteger& listInt, int num) {
	if (listInt == NULL) {
		listNode* newNode = new listNode;
		newNode->oneInteger = num;
		newNode->next = NULL;
		listInt = newNode;
	}
	else {
		listNode* loopPtr = listInt;
		while (loopPtr->next != NULL)
			loopPtr = loopPtr->next;

		listNode* newNode = new listNode;
		newNode->oneInteger = num;
		newNode->next = NULL;
		loopPtr->next = newNode;
	}
}


listInteger addList(listInteger a, listInteger b) {
	if (a == NULL && b == NULL) return NULL;
	else {
		if (a == NULL) return b;
		if (b == NULL) return a;
	}
	
	listNode* aLoopPtr = a;
	listNode* bLoopPtr = b;
	listInteger sumPtr = NULL;
	int carry = 0, product = 0, remainder = 0;

	while (aLoopPtr != NULL || bLoopPtr != NULL) {
		if (aLoopPtr != NULL && bLoopPtr != NULL)
			product = carry + aLoopPtr->oneInteger + bLoopPtr->oneInteger;
		else if (aLoopPtr != NULL && bLoopPtr == NULL)
			product = carry + aLoopPtr->oneInteger;
		else if (aLoopPtr == NULL && bLoopPtr != NULL)
			product = carry + bLoopPtr->oneInteger;

		carry = product / 10;
		remainder = product % 10;
		addNode(sumPtr, remainder);
		if (aLoopPtr != NULL)
			aLoopPtr = aLoopPtr->next;
		else
			aLoopPtr = NULL;
		if (bLoopPtr != NULL)
			bLoopPtr = bLoopPtr->next;
		else
			bLoopPtr = NULL;
	}
	if (carry > 0)
		addNode(sumPtr, carry);

	return sumPtr;
}


void displayList(listInteger listInt) {
	if (listInt == NULL)
		return;

	listNode* loopPtr = listInt;
	while (loopPtr != NULL) {
		cout << loopPtr->oneInteger;
		loopPtr = loopPtr->next;
	}
	cout << endl;
}


int main() {
	listInteger aInteger = NULL;
	listInteger bInteger = NULL;
	listInteger sumInteger = NULL;

	intToList(aInteger, 1287);
	intToList(bInteger, 9999);
	sumInteger = addList(aInteger, bInteger);
	displayList(sumInteger);

	system("pause");
	return 0;
}
