#include <iostream>

using namespace std;

typedef char * arrayString;


arrayString subString(arrayString s1, int startPoint, int length) {
	arrayString newS = new char[length + 1];

	for (int i = 0; i < length; i++)
		newS[i] = s1[startPoint + i];

	newS[length] = 0;
	return newS;
}


int main() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;

	cout << "Original string of a is " << a << endl;
	cout << subString(a, 1, 2) << " is a Substring of a" << endl;

	system("pause");
	return 0;

}


