#include <iostream>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string konwertuj(string konwertowana, int przed, int po);
string intToString(int integer);

int main(int argc, char *argv[]) 
{
	system("@echo off && cls");

	string liczba;
	int presys, postsys;

	cout << "Podaj liczbe: ";
	cin >> liczba;
	cout << "W ktorym systemie jest liczba?: ";
	cin >> presys;
	cout << "Na jaki system ja przekonwertowac?: ";
	cin >> postsys;
	
	cout<<endl<<"Liczba po konwersji: "<<konwertuj(liczba,presys,postsys)<<endl;

	return 0;
}

string konwertuj(string konwertowana, int przed, int po)
{
	int x = konwertowana.length(), suma = 0,a;
	string cyfra;
	for(int i = 0; i < x; i++)
	{
		cyfra = konwertowana[x - i - 1];
		istringstream(cyfra)>>a;
		suma+=a*pow(przed,i);
	}

	konwertowana = "";

	do
	{
		konwertowana += intToString(suma%po);
		suma = suma/po;
	}
	while(suma>0);

	reverse(konwertowana.begin(), konwertowana.end());

	return konwertowana;

}

string intToString(int integer)
{
	string str;          
	ostringstream temp;  
	temp << integer;
	str = temp.str();
	return str;    
}