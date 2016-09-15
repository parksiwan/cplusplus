// Using the same rule as the shapes programs from earlier in the chapter (only
// two output statements—one that outputs the hash mark and one that outputs
// an end - of - line and space), write a program that produces the following shape :
//########
// ######
//  ####
//   ##

#include <iostream>
using namespace std;

int main() 
{
	for (int i = 4; i > 0; i--) 
	{
		for (int j = 0; j < (4 - i); j++)
			cout << ' ';
		for (int k = 0; k < (2 * i); k++)
			cout << '#';
		cout << endl;
	}
	return 1;
}
