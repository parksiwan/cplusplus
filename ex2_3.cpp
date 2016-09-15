// Using the same rule as the shapes programs from earlier in the chapter (only
// two output statements—one that outputs the hash mark and one that outputs
// an end - of - line and space), write a program that produces the following shape :
// #            #
//  ##        ##
//   ###    ###
//    ########
//    ########
//   ###    ###
//  ##        ##
// #            #

#include <iostream>
using namespace std;

int main() 
{
	for (int i = 4; i > 0; i--) 
	{
		for (int j = 0; j < abs(4 - i); j++)
			cout << ' ';
		for (int k = 0; k < (5 - i); k++)
			cout << '#';
		for (int l = 0; l < (i - 1) * 4; l++)
			cout << ' ';
		for (int k = 0; k < (5 - i); k++)
			cout << '#';
		cout << endl;
	}
	for (int i = 1; i < 5; i++) 
	{
		for (int j = 0; j < abs(4 - i); j++)
			cout << ' ';
		for (int k = 0; k < (5 - i); k++)
			cout << '#';
		for (int l = 0; l < (i-1) * 4; l++)
			cout << ' ';
		for (int k = 0; k < (5 - i); k++)
			cout << '#';
		cout << endl;
	}
	return 1;
}
