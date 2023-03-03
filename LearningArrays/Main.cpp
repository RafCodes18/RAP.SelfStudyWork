#include <conio.h>;
#include<iostream>;
#include<string>;
#include<vector>;					//vectors are in the header files so we need include statement
using namespace std;



//struct for vectors func below
struct Person {

	string name;
	int age;
};

//vectors
void Vectors()
{
	char input = 'y';
	Person person;

	//like lists in C#, vectors need to know the data type they hold, so we use <>. In this case, a vector of People structs.		
	vector<Person> people;       //vectors are like arrays but we can dynamically increase the size of the array

	
	//while user requests to create another person
	while (input == 'y')
	{
		cout << "Name: ";
		cin >> person.name;  //let user store their name

		cout << "Age: ";
		cin >> person.age;	//let user store their age
		
		
		//push_back is a native C++ library method to add an element to the end of a vector
		people.push_back(person);  //add the user created Person struct to the people vector, as many times as the user wants. 
								   //This would not be possible with array, because compiler needs to know array size at runtime.
		
		
		
		cout << "Would you like to add another person? (y/n): ";
	}



//ITERATE THROUGH THE VECTOR!!!

	//slow/bad but Easier WAY		     //.size() is native method that returns number of elements
	for (int i = 0; i < people.size(); i++) {  
		
		cout << people[i].name << " is " << people[i].age << " years old! \n "; //using people[i] is SLOW, because math needs to be done to find each value
	}


	//better/more difficult way!
	vector<Person>::iterator it;  // 'it' is the name of the iterator variable
	
	for (it = people.begin(); it != people.end(); it++) {
		
		cout << it->name << "\n";
	}

}


//multi-dimensional arrays
void ArrayOfArrays()
{                  
	char checkers[8][8] = {

		{ ' ', 'W', ' ', 'W', ' ', 'W', ' ', 'W' },   //checkers holds 8 arrays, which each hold 8 elements
		{ 'W', ' ', 'W', ' ', 'W', ' ', 'W', ' ' },
		{ ' ', 'W', ' ', 'W', ' ', 'W', ' ', 'x' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ' },
		{ ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B' },
		{ 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ' }
	};

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			cout << checkers[y][x] << " ";
		}
		cout << "\n";
	}

}


//character arrays
void charArray()
{
	//this would error if there was no space in the array for the compiler to add a '\0' escape character, 
	//but since the array holds 5 elements and only sets 4, the compiler is able to add the escape character to the last unfilled spot
	char name[5] = { 'E', 'K', 'C', 'A' };

	cout << name; cout << "\n";
}


//arrays and dynamic memory storage of values
void ArrayOnHeap()
{

	//USING CONST
		//if array is on the stack, we need to know before hand what the size will be, so NUM_PEOPLE has to be const
	const int NUM_PEOPLE = 4;
	int ages1[NUM_PEOPLE] = { 12, 55, 32, 31 };  //if no const above, this would error, must know size when on stack, or use pointer

	//USING POINTER
	int num_people = 0;					//ALLOWS DYNAMIC ARRAY CREATION
	cout << "How many ages would you like to track?: "; cin >> num_people; //ask user for size of array

			//new indicates we are now on the heap, pointer named ages. Anytime we use 'new', we are returned a pointer(address not value) to the first element
	int *ages = new int[num_people];

	for (int i = 0; i < num_people; i++)
	{
		std::cout << "Age of person " << (i + 1) << ": ";
		std::cin >> ages[i];
	}

	for (int i = 0; i < num_people; i++)
	{
		std::cout << ages[i] << "\n";
	}
}


struct Person {
	string name; 
	int age;
};

//structuring data with arrays
void MoreArrays()
{
	const int NUM_PEOPLE = 5;


	//array of integers named ages that holds 5 elements, then sets the values of each 
	int ages[NUM_PEOPLE] = { 12, 22, 56, 33, 15 };

	//array of strings called 'names' that holds 5 elements, then sets the values of each 
	string names[NUM_PEOPLE] = { "Harry", "Suzzy", "Shelly", "Sandy", "Carly" };



	//an array Named 'people', that holds 5 Person structs
	Person people[5];

	for (int i = 0; i < NUM_PEOPLE; i++)  //loop through the array of people objects, and change their .age to ages[i]
	{
		people[i].age = ages[i];
		people[i].name = names[i];
		cout << people[i].name << " is " << people[i].age << " years old! \n";
	}
	
}

//should print an address then a value. names of arrays are pointers to the first element of that array
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

	cout << *ages<<"\n"; // this dereferences the address of the first element, printing the values

}


//first code to run, the entry point of the program
int main()
{
	//fundamentals
	LearnArrays();
	MoreArrays();

	//arrays and memory
	ArrayOnHeap();

	//character arrays and null chars
	charArray(); 

	//multi-dimensional arrays
	ArrayOfArrays();

	//vectors
	Vectors();

	_getch();
	return 0;
}