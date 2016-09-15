//
//  main.cpp
//  SiwanProject02
//
//  Created by SiWan Park on 26/08/2016.
//  Copyright © 2016 SiWan Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int acceptInput();
void pushDigitIntoVector(vector<int>&, int);
void computeFactorial(vector<int>&, vector<int>&, vector<int>&, int);
void multiFactorial(vector<int>&, vector<int>&, int);
void addVector(vector<int>&, vector<int>&, int);
void displayOutput(vector<int>&);
void display(vector<int>&, string);
void initializeVector(vector<int>&);


int main(int argc, const char * argv[]) 
{
    vector<int> factorialTarget;
    vector<int> factorialMinusOne;
    vector<int> tempAddedNumbers;
    int factorial;
    
    factorial = acceptInput();
    
    pushDigitIntoVector(factorialTarget,factorial);
    computeFactorial(factorialTarget, factorialMinusOne, tempAddedNumbers, factorial - 1);
    displayOutput(factorialTarget);
    
    return 0;
}


void multiFactorial(vector<int>& p_factorialTarget, vector<int>& p_tempAddedNumbers, int number) 
{
    int i = 0, carry = 0, product = 0, remainder = 0;
    
    while (i < p_factorialTarget.size()) 
    {
        product = carry + (p_factorialTarget[i] * number);
        carry = product / 10;
        remainder = product % 10;
        p_tempAddedNumbers.push_back(remainder);
        i++;
        
    }
    if (carry > 0)
        p_tempAddedNumbers.push_back(carry);
}


void computeFactorial(vector<int>& p_factorialTarget, vector<int>& p_factorialMinusOne, vector<int>& p_tempAddedNumbers, int number) 
{
    int dividend = 0, remainder = 0;
    
    for (int i = number; i > 0; i--) 
    {
        dividend = i;
        int pos = 0;
        while (dividend != 0) 
        {
            remainder = dividend % 10;
            dividend = dividend / 10;
            multiFactorial(p_factorialTarget, p_tempAddedNumbers, remainder);
            addVector(p_factorialMinusOne, p_tempAddedNumbers, pos);
            pos++;
            p_tempAddedNumbers.erase(p_tempAddedNumbers.begin(), p_tempAddedNumbers.end());
        }
        cout << "number : " << i << endl;
        display(p_factorialTarget, "fatorrialTarget");
        display(p_factorialMinusOne, "fatorialMinusOne");
        display(p_tempAddedNumbers, "tempAddedNumbers");
        p_factorialTarget = p_factorialMinusOne;
        p_factorialMinusOne.erase(p_factorialMinusOne.begin(), p_factorialMinusOne.end());
    }
}


void addVector(vector<int>& p_factorialMinusOne, vector<int>& p_tempAddedNumbers, int position) 
{
    int carry = 0, product = 0, remainder = 0;
    
    if (p_factorialMinusOne.size() == 0) 
    {
        p_factorialMinusOne = p_tempAddedNumbers;
        initializeVector(p_factorialMinusOne);
    }
    int diff = p_tempAddedNumbers.size() - p_factorialMinusOne.size() + position;
    int j = diff;
    while (j > 0) 
    {
        p_factorialMinusOne.push_back(0);
        j--;
    }
    
    for (int i = 0; i < p_tempAddedNumbers.size(); i++) 
    {
        product = carry + p_tempAddedNumbers[i] + p_factorialMinusOne[i + position];
        carry = product / 10;
        remainder = product % 10;
        p_factorialMinusOne[i + position] = remainder;
        if ((i >= p_factorialMinusOne.size()) && ((carry != 0) || (remainder != 0)))
            p_factorialMinusOne.push_back(remainder);
    }
    
    if (carry > 0)
        p_factorialMinusOne.push_back(carry);
    
}


int acceptInput() 
{
    int factorialNumber;
    
    cout << "Enter a factorial number :";
    cin >> factorialNumber;
    cout << endl;
    
    return factorialNumber;
}


void pushDigitIntoVector(vector<int>& p_vectorNumber, int number) 
{
    int dividend = number, remainder = 0;
    
    while (dividend != 0) 
    {
        remainder = dividend % 10;
        dividend = dividend / 10;
        p_vectorNumber.push_back(remainder);
    }
}


void displayOutput(vector<int>& p_arr) 
{
    cout << "### display of vector ###" << endl;
    reverse(p_arr.begin(), p_arr.end());
    for (int i = 0; i < p_arr.size(); i++)
        cout << p_arr[i];
    
    cout << endl;
}

void display(vector<int>& p_arr, const string label) 
{
    cout << "### display of vector reverse ###" << label << endl;
    //reverse(p_arr.begin(), p_arr.end());
    for (int i = 0; i < p_arr.size(); i++)
        cout << p_arr[i];
    
    cout << endl;
}

void initializeVector(vector<int>& p_arr) 
{
    for (int i = 0; i < p_arr.size(); i++)
        p_arr[i] = 0;
}
