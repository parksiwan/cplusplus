#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct student 
{
	int grade;
	int studentID;
	//string name;
	char name[15]; //must be a fixed size
};

const int ARRAY_SIZE = 10;
student studentArray[ARRAY_SIZE] = 
{
	{87, 10001, "Fred"},
	{28, 10002, "Tom"},
	{100, 10003, "Alistair"},
	{78, 10004, "Sasha"},
	{84, 10005, "Erin"},
	{98, 10006, "Belinda"},
	{75, 10011, "Leslie"},
	{70, 10008, "Candy"},
	{81, 10009, "Aretha"},
	{68, 10010, "Veronica"}
};

int GradeCompare(const void* a, const void* b) 
{
    const struct student *st1 = (struct student *)a;
    const struct student *st2 = (struct student *)b;
    
    return( st1->grade - st2->grade );
}

int IdCompare(const void* a, const void* b) 
{
    const struct student *st1 = (struct student *)a;
    const struct student *st2 = (struct student *)b;
	
    return( st1->studentID - st2->studentID );
}

int main(int argc, char **argv) 
{
	size_t structs_len = sizeof(studentArray) / sizeof(struct student);
	
	qsort(studentArray, structs_len, sizeof(struct student), GradeCompare);
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << studentArray[i].grade << '-' << studentArray[i].studentID 
			<< '-' << studentArray[i].name << endl;
		
	qsort(studentArray, structs_len, sizeof(struct student), IdCompare);
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << studentArray[i].grade << '-' << studentArray[i].studentID 
			<< '-' << studentArray[i].name << endl;
	cout << endl;
		
	return 0;
}
