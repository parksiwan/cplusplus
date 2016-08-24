#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int const ARRAY_SIZE = 10;
int IntArray[ARRAY_SIZE] = {1,22,3,4,5,6,7,8,9,10};

bool CompareElement(const int arr[], const int size) {
	int count = 0;
	
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			count++;
	}
    
	if (count == 0)
		return true;
	else
		return false;
}


int main(int argc, char **argv) {
	if (CompareElement(IntArray, ARRAY_SIZE))
		cout << "This array are sorted" << endl;
	else
		cout << "Thie array are not sorted" << endl;
	
	return 0;
}
