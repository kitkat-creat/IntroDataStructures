// roman.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* Overview: Converting Roman numerals to whole numbers*/

#include <iostream>
#include "roman.h"
using namespace std;
int main()
{
    while (true) {
        romanType r;   //class name, building object
        string romannum;
        char response;
        cout << "Enter a roman number: " << endl;
        cin >> romannum;

        cout << r.convertRomantoDecimal(romannum) << endl; //sending user's input into class(header)
        cout << "Do you want to try another? (Y/N): ";
        cin >> response;
        if (response == 'N')
        {
            cout << "Thank you!" << endl;
            return false;
        }


    }
    return 0;
}

