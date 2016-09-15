//Tracking an unknown quantity of student records
#include <iostream>
using namespace std;

struct listNode 
{
	int studentNum;
	int grade;
	listNode* next;
};
typedef listNode* studentCollection;


void addRecord(studentCollection& sc, int stuNum, int gr) 
{
	listNode* newNode = new listNode;
	
	newNode->studentNum = stuNum;
	newNode->grade = gr;
	newNode->next = sc;
	sc = newNode;
}


double averageRecord(studentCollection sc) 
{
	int count = 0;
	double sum = 0;

	if (sc == NULL)
		return 0;

	listNode* loopPtr = sc;
	while (loopPtr != NULL) 
	{
		sum += loopPtr->grade;
		count++;
		loopPtr = loopPtr->next;
	}
	double average = sum / count;
	return average;
}

void displayRecord(studentCollection sc) 
{
	if (sc == NULL)
		return;

	listNode* loopPtr = sc;
	while (loopPtr != NULL) 
	{
		cout << "\t" << loopPtr->studentNum << "\t" << loopPtr->grade << endl;
		loopPtr = loopPtr->next;
	}
}


int main() 
{
	studentCollection sc;
	listNode* node1 = new listNode;
	node1->studentNum = 1001;
	node1->grade = 78;

	listNode* node2 = new listNode;
	node2->studentNum = 1012;
	node2->grade = 93;

	listNode* node3 = new listNode;
	node3->studentNum = 1076;
	node3->grade = 85;

	sc = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	node1 = node2 = node3 = NULL;
	addRecord(sc, 1123, 99);
	displayRecord(sc);
	cout << endl << "The average of grades is " << averageRecord(sc) << endl;

	system("pause");
	return 0;
}

