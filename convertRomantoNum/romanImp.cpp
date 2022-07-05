#include "roman.h"
#include <iostream>

using namespace std;



int romanType::convertRomantoDecimal(string romanvalue) //Make sure class name is same as in header
{
	
	int sum = 0;
	int previous = 1000;         //initialize to prevent run time error
	for (int i = 0;i < romanvalue.size();i++)
	{
		switch (romanvalue[i])
		{
		case 'M':
			sum += 1000;         
			if (previous < 1000)  //if a small number comes first, then subtract
			{
				
				sum = sum - (previous+1);
			}
			previous = 1000;
			break;
		case 'D':
			sum += 500;
			if (previous < 500)
			{
				
				sum = sum - (previous+1);
			}
			previous = 500;
			break;
		case 'C':
			sum += 100;
			if (previous < 100)
			{
				
				sum = sum - (previous+1);
			}
			previous = 100;
			break;
		case 'L':
			sum += 50;
			if (previous < 50)
			{
				sum = sum - (previous+1);
			}
			previous = 50;
			break;
		case 'X':
			sum += 10;
			if (previous < 10)
			{
				sum = sum - (previous+1);
			}
			previous = 10;
			break;
		case 'V':
			sum += 5;
			if (previous < 5)
			{
				
				sum = sum - (previous+1);
			}
			previous = 5;
			break;
		case 'I':
			sum += 1;
			if (previous < 1)
			{
				
				sum = sum - (previous+1);
			}
			previous = 1;
			break;
		}
		
	}
return sum;
}