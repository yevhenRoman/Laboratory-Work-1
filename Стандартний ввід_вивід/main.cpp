#include "Header.h"

void main()
{

	Stack *myStack = NULL;

	FILE *f = NULL;

	header();

	LoadFileToStek(f, myStack);

	cout << "PrintStek: " << endl;

	printStek(myStack);

	renumber(myStack);

	line(50, '-');

	
	
	cout << "Purge: " << endl;

	purge(myStack);

	system("pause>>void");

}