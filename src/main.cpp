#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string convert(string toconv, int before, int after);
string intToString(int integer);
bool validation(string forvalid, int system);

int main(int argc, char *argv[]) 
{

	string number;
	int presys, postsys;
	char again;
	bool exit=false;
	cout<<endl<<"Welcome in numeral systems converter!"<<endl<<endl;
	while(true)
	{
		while(true)
		{
			cout << "Number: ";
			cin >> number;
			cout << "Numeral system of number: ";
			cin >> presys;
			if (validation(number,presys))
			{
				break;
			}
			cout<<"Wrong number or numeral system!"<<endl;
		}

		cout << "Convert to system: ";
		cin >> postsys;

		cout<<endl<<"Number after conversion: "<<convert(number,presys,postsys)<<endl;
		while(true)
		{
			cout<<"Do You want to convert another number? (y/n): ";
			cin>>again;
			cout<<endl;
			if(again=='y')
			{
				break;
				exit=false;
				
			}
			else if(again=='n')
			{
				break;
				exit=true;
			}
			else
			{
				cout<<"Wrong letter!"<<endl;
			}
			


		}
		
	}
	
	cout<<"Bye :D"<<endl;
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