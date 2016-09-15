//Want an extra challenge? Generalize the code for the previous exercise to
//make a program that converts from any number base-16 or less to any other
//number base. So, for example, the program could convert from base-9 to
//base-4.

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>  
using namespace std;
 
int StringToTenBaseInteger(string, int);
string  ConvertOtherBaseString(int, int);

int main() 
{
	string str_number, converted_number;
	int src_base, dest_base, int_number;

	cout << "Base of source :";
	cin >> src_base;
	cout << endl;
	cout << "Number of source :";
	cin >> str_number;
	cout << endl;

	cout << "Base of destination :";
	cin >> dest_base;
	cout << endl;
	
	int_number = StringToTenBaseInteger(str_number, src_base);
	converted_number = ConvertOtherBaseString(int_number, dest_base);

	cout << "Number of destination :" << converted_number << endl;
	return 0;
}


int StringToTenBaseInteger(string n, int bs) 
{
	int i = 0, j;
	int dig;

	j = n.length() - 1;
	int total = 0;
	while (i < n.length()) 
	{
		switch (n[i]) 
		{
			case 'A':
				dig = 10;
				break;
			case 'B':
				dig = 11;
				break;
			case 'C':
				dig = 12;
				break;
			case 'D':
				dig = 13;
				break;
			case 'E':
				dig = 14;
				break;
			case 'F':
				dig = 15;
				break;
			default:
				dig = n[i] - '0';
		}
		for (int k = 0; k < j; k++)
			dig = dig * bs;

		total = total + dig;
		i++;
		j--;
	}
	return total;
}

string  ConvertOtherBaseString(int number, int base) 
{
	stringstream ss;
	string str;
	int dividend = number, remainder = 0;

	while (dividend != 0) 
	{
		remainder = dividend % base;
		switch (remainder) 
		{
			case 10 :
				ss << 'A';
				break;
			case 11 :
				ss << 'B';
				break;
			case 12 :
				ss << 'C';
				break;
			case 13 :
				ss << 'D';
				break;
			case 14 :
				ss << 'E';
				break;
			case 15 :
				ss << 'F';
				break;
			default :
				ss << remainder;
		}
		dividend = dividend / base;
	}
	str = ss.str();
	reverse(str.begin(), str.end());
	return str;
}
