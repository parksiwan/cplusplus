//Let’s create an implementation for strings that uses a linked list of characters
//instead of dynamically allocated arrays. So we’ll have a linked list where the
//data payload is a single char.
//append()
//characterAt()
//concatenate(s1, s2)
//removeChars(s1, 5, 3)

#include <iostream>
using namespace std;

struct listNode 
{
	char oneChar;
	listNode* next;
};

typedef listNode* listString;


char characterAt(listString str, int position) 
{
	if (str == NULL) return 0;

	int count = 1;
	listNode* loopPtr = str;

	while (loopPtr != NULL) 
	{
		if (position == count)
			return loopPtr->oneChar;
		else 
		{
			count++;
			loopPtr = loopPtr->next;
		}

	}
}


void append(listString& str, char c) 
{
	if (str == NULL) return;

	listNode* loopPtr = str;
	listNode* newNode = new listNode;

	while (loopPtr->next != NULL)
		loopPtr = loopPtr->next;

	newNode->oneChar = c;
	newNode->next = NULL;
	loopPtr->next = newNode;
}


void concatenate(listString& s1, listString& s2) 
{
	if ((s1 == NULL) || (s2 == NULL)) return;

	listNode* ptr1 = s1;
	listNode* ptr2 = s2;
	listNode* tempPtr = s2;

	while (ptr1->next != NULL)
		ptr1 = ptr1->next;

	while (ptr2 != NULL) {
		listNode* newNode = new listNode;
		newNode->oneChar = ptr2->oneChar;
		newNode->next = NULL;
		ptr1->next = newNode;
		ptr1 = newNode;

		ptr2 = ptr2->next;
		delete(tempPtr);
		tempPtr = ptr2;
	}
}


void removeChars(listString& str, int position, int length) 
{
	if (str == NULL) return;

	listNode* firstNode = str;
	listNode* loopPtr = str;
	listNode* prevPtr = str;
	
	int count = 1, numberChar = 1;
	while (loopPtr != NULL) 
	{
		if (count == position) 
		{
			while (numberChar <= length) 
			{
				if (loopPtr == prevPtr)     //Removing starts at first node
				{
					prevPtr = prevPtr->next;
					delete(loopPtr);
					loopPtr = prevPtr;
					str = loopPtr;    //Change first pointer to modified address
					numberChar++;
				}
				else 
				{
					prevPtr->next = loopPtr->next;
					delete(loopPtr);
					loopPtr = prevPtr->next;
					numberChar++;
				}
			}
     		return;
		}
		else 
		{
			prevPtr = loopPtr;
			loopPtr = loopPtr->next;
			count++;
		}
	}
}


int main() 
{
	listString str1, str2;

	listNode* node1 = new listNode;
	node1->oneChar = 's';


	listNode* node2 = new listNode;
	node2->oneChar = 'u';

	listNode* node3 = new listNode;
	node3->oneChar = 'b';

	str1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;


	append(str1, 'r');
	append(str1, 't');
	append(str1, 's');
	//cout << characterAt(str1, 2);
	
	listNode* node4 = new listNode;
	node4->oneChar = 'l';

	listNode* node5 = new listNode;
	node5->oneChar = 'i';

	listNode* node6 = new listNode;
	node6->oneChar = 'm';

	str2 = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;
	concatenate(str1, str2);

	listNode* loopPtr = str1;
	while (loopPtr != NULL) 
	{
		cout << loopPtr->oneChar;
		loopPtr = loopPtr->next;
	}
	cout << endl;
	
	removeChars(str1, 1, 2);
	
	listNode* Ptr = str1;
	while (Ptr != NULL) 
	{
		cout << Ptr->oneChar;
		Ptr = Ptr->next;
	}
	cout << endl;
	delete(str1);
	
	system("pause");
	return 0;
}
