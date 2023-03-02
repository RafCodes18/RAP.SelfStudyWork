#include <conio.h>;
#include<iostream>;
#include<string>;
using namespace std;

void LearnArrays()
{

	int ages[5];   //array of integers named ages, that can hold up to 5 elements 

	ages[0] = 22;
	ages[1] = 29;
	ages[2] = 45;  //set the Y in ages[n, n, Y, n, n] =  to 45

	//  ages[5] = 12;  while in C++ we can get away with this without an error, 
	//				   avoid assigning values to indices beyond the bounds of the array,
	//				   such as ages[5], as it can cause unexpected behavior and errors 



	//array that holds 23 elements
	string names[10];		//in C++, the name of an array is a pointer to its first element!! 
	names[0] = "Mathew";
	names[1] = "Mark";
	names[2] = "Luke";
	names[3] = "John";

	cout << names;       //this prints the address of the first element of the array 

/*linebreak*/cout << "\n";

	cout << *ages; // this dereferences the address of the first element, printing the values

}


//first code to run, the entry point of the program
int main()
{
	LearnArrays();

	_getch();
	return 0;
}