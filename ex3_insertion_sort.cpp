//My insetion sort
#include <iostream>
using namespace std;

int main(int argc, char **argv) 
{
	const int SIZE = 10;
	int arr[SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
	int start = 0, end = SIZE - 1;
	
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << '-';
	cout << endl;
	
	for (int i = start + 1; i <= end; i++) 
	{
		for (int j = i; j > start && arr[j-1] > arr[j]; j--) 
		{
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
		}
	}
	
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << '-';
		
	cout << endl;
	
	return 0;
}
