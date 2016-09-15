#include <iostream>
#include <cstdlib>
using namespace std;

int values[] = {40, 10, 100, 90, 20,25};
char char_vals[] = {'c', 'f', 'r', 'h', 'a', 'e'};

int IntCompare(const void* a, const void* b) 
{
	return( *(int*)a - *(int*)b);
}

int CharCompare(const void* a, const void* b) 
{
	return( *(char*)a - *(char*)b);
}

int main(int argc, char **argv) 
{
	qsort(values, 6, sizeof(int), IntCompare);
	qsort(char_vals, 6, sizeof(char), CharCompare);
	
	for (int i = 0; i < 6; i++)
		cout << values[i] << '-';
		
	cout << endl;
	for (int i = 0; i < 6; i++)
		cout << char_vals[i] << '-';
		
	return 0;
}
