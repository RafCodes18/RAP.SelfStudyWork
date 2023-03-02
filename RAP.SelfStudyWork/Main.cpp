#include <iostream>;
#include <conio.h>;
#include <string>;
using namespace std;


struct Person {
	string name;
	int age;
};



void PrintPerson(Person *p) //accept the address of Person struct passed in
{
		//because p is a pointer, we use the arrow to dereference and access its memebers	
	cout << p->name << " is " << p->age << " years old.";
}



int main()
{
	//p NOT A POINTER
	Person p;  //on the stack 
	p.age = 12;
	p.name = "Jerry";

	PrintPerson(&p); //pass in the address of p
					cout << "\n";



	//p2 POINTER		   	//pointer named p2 that points to a Person struct on the heap
	Person *p2 = new Person; //on the heap
	p2->name = "Carl";
	p2->age = 29;

	//since it is already an adress, do not need &
	PrintPerson(p2);
	

	_getch();
	return 0;
}