#include "studentrecord.h"
#include <cstdlib>
#include <ctime>
using namespace std;


class studentCollection 
{
private:
    struct studentNode 
    {
        studentRecord studentData;
        studentNode* next;
    };
public:
    studentCollection();
    studentCollection(const studentCollection& original);
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    void printRecords();
    studentCollection& operator=(const studentCollection& rhs);
private:
    typedef studentNode* studentList;
    studentList _listHead;
    void deleteList(studentList& listPtr);
    studentList copiedList(const studentList original);
};

studentCollection::studentCollection() 
{
    _listHead = NULL;
}

studentCollection::studentCollection(const studentCollection& original) 
{
    _listHead = copiedList(original._listHead);
}

studentCollection::~studentCollection() 
{
    deleteList(_listHead);
}

void studentCollection::addRecord(studentRecord newStudent) 
{
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) 
{
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum)
        loopPtr = loopPtr->next;

    if (loopPtr == NULL) 
    {
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } 
    else 
    {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum) 
{
    studentNode* loopPtr = _listHead;
    studentNode* trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum) 
    {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL)
        return;
    
    if (trailing == NULL)
        _listHead = _listHead->next;
    else
        trailing->next = loopPtr->next;

    delete loopPtr;
}

void studentCollection::deleteList(studentList& listPtr) 
{
    while (listPtr != NULL) 
    {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

void studentCollection::printRecords() 
{
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL) 
    {
        cout << loopPtr->studentData.studentID() << "\t";
        cout << loopPtr->studentData.name() << "\t";
        cout << loopPtr->studentData.grade() << "\t";
        loopPtr = loopPtr->next;
    }
}

studentCollection::studentList studentCollection::copiedList(const studentList original) 
{
    if (original == NULL)
        return NULL;

    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode* oldLoopPtr = original->next;
    studentNode* newLoopPtr = newList;
    while (oldLoopPtr != NULL) 
    {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

studentCollection& studentCollection::operator=(const studentCollection& rhs) 
{
    if (this != &rhs) 
    {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

int main() 
{
    studentCollection s1, s2;


    studentRecord r1(85, 99837, "John");
    s2.addRecord(r1);
    studentRecord r2(77, 4765, "Elsie");
    s2.addRecord(r2);
    cout << "s2" << endl;
    s2.printRecords();
    s1 = s2;
    cout << "s1" << endl;
    s1.printRecords();
    cout << endl;

    s2.removeRecord(99837);
    cout << "s2" << endl;
    s2.printRecords();
    s1 = s2;
    cout << "s1" << endl;
    s1.printRecords();
    cout << endl;

    return 0;
}
