#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string convert(string toconv, int before, int after);
string intToString(int integer);
bool validation(string forvalid, int system);

int main(int argc, char *argv[]) 
{
	system("@echo off && cls");

	string number;
	int presys, postsys;

	cout << "Number: ";
	cin >> number;
	cout << "Numeral system of number: ";
	cin >> presys;
	if (!validation(number,presys))
	{
		cout<<"Wrong number or numeral system!"<<endl;
		return 0;
	}
	
	cout << "Convert to system: ";
	cin >> postsys;

	cout<<endl<<"Number after conversion: "<<convert(number,presys,postsys)<<endl;

	system("pause");
	return EXIT_SUCCESS;
	
}

string convert(string toconv, int before, int after)
{
	int x = toconv.length(), sum = 0,a;
	string digit;
	for(int i = 0; i < x; i++)
	{
		digit = toconv[x - i - 1];
		istringstream(digit)>>a;
		sum+=a*pow(before,i);
	}

	toconv = "";

	do
	{
		toconv += intToString(sum%after);
		sum = sum/after;
	}
	while(sum>0);

	reverse(toconv.begin(), toconv.end());

	return toconv;

}

string intToString(int integer)
{
	string str;          
	ostringstream temp;  
	temp << integer;
	str = temp.str();
	return str;    
}

bool validation(string forvalid, int system)
{
	for(int j = 0;j<forvalid.length();j++)
	{
		string dig;
		int onedigit;
		dig = forvalid[j];
		istringstream(dig)>>onedigit;
		if(onedigit>=system) return false;
	}

	return true;

}