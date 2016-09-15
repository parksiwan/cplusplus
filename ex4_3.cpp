//function replaceString (source, target, replaceText)
//The function replaces every occurrence of target in source with replaceText

#include <iostream>

using namespace std;

typedef char * arrayString;

int length(arrayString);
arrayString subString(arrayString, int, int);
arrayString replaceString(arrayString&, arrayString, arrayString);
void concatenate(arrayString&, arrayString);

int length(arrayString s) 
{
	int count = 0;

	while (s[count] != 0)
		count++;

	return count;
}


arrayString subString(arrayString s1, int startPoint, int length) 
{
	arrayString newS = new char[length + 1];

	for (int i = 0; i < length; i++)
		newS[i] = s1[startPoint + i];

	newS[length] = 0;
	return newS;
}


arrayString replaceString(arrayString& source, arrayString target, arrayString replaceText) 
{
	int sourceLength = length(source);
	int targetLength = length(target);
	int count = 0, sp = 0;
	arrayString tempS = new char[1];

	tempS[0] = NULL;
	int i = 0;
	while (source[i] != NULL) 
	{
		for (int j = 0; j < targetLength; j++) 
		{
			if (target[j] == source[j + i]) 
				count++;
			else {
				count = 0;
				break;
			}
		}
		if (count == targetLength) 
		{
			concatenate(tempS, subString(source, sp, i - sp));	
			concatenate(tempS, replaceText);
			sp = i + targetLength;
			count = 0;
		}	
		i++;
	}

	if (tempS[0] == NULL) 
		concatenate(tempS, source);
	else
		concatenate(tempS, subString(source, sp, sourceLength - sp));

	return tempS;
}


void concatenate(arrayString& s1, arrayString s2) 
{
	int s1_OldLength = length(s1);
	int s2_Length = length(s2);
	int s1_NewLength = s1_OldLength + s2_Length;
	arrayString newS = new char[s1_NewLength + 1];

	for (int i = 0; i < s1_OldLength; i++)
		newS[i] = s1[i];

	for (int i = 0; i < s2_Length; i++)
		newS[s1_OldLength + i] = s2[i];

	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;

}


int main() 
{
	arrayString a = new char[10];
	a = "absdkrabm\0";

	cout << "Original string of a is " << a << endl;
	cout << replaceString(a, "m", "xy") << endl;

	system("pause");

	return 0;
}
