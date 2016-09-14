#include "Header.h"


//Функція вводу в стек інфо
void push(char*info, Stack *&myStack)
{
	Stack *temp = new Stack;
	temp->data = info;
	temp->next = myStack;
	myStack = temp;
}

//Звільнення стеку
char* pop(Stack *&myStack)
{
	if (myStack == NULL)
	{
		cout << "Stack is already empty" << endl;
		return NULL;
	}
	Stack *temp = myStack;
	myStack = temp->next;
	char *arr = temp->data;
	delete temp;
	return arr;
}

//Вивід стеку
//void printStek(Stack *&myStack)
//{
//	Stack *p = myStack;
//	while (p != NULL)
//	{
//		for (int i = 0; i < strlen(p->data); ++i)
//		{
//			printf("%c", p->data[i]);
//		}
//		p = p->next;	
//	}
//}

//Запис з файлу в стек
void LoadFileToStek(FILE*f, Stack *&myStack)
{
	myStack = NULL;

	fopen_s(&f, "Text.txt", "r");

	if (f == NULL)
	{
		perror("File didn't open");
	}
	else
	{
			while(!feof(f))
			{
				char *arr = new char[N];
				fgets(arr, N, f);
				push(arr, myStack);
			}
	}

	fclose(f);

	char *temp = pop(myStack);//Видаляємо в останній стрічці '\n'

	renumber(myStack);

}

//Функція форматування стрічок в стеку
void renumber(Stack *&myStack)
{
	int i = 1;
	Stack *p = myStack;
	
	while (p != NULL)
	{
		char *a = new char[100];
		
		a = itoa(i, a, 10);
		
		strcat(a, ": ");

		strcat(a, p->data);

		delete[] p->data;

		p->data = new char[strlen(a)];

		strcpy(p->data, a);
		
		p = p->next;

		++i;	
		
	}
}

//Функція звільнення стеку і одару виводу
void purge(Stack *&myStack)
{
	while (myStack != NULL)
	{
		char *c = pop(myStack);
		cout << c;
	}
	delete[]myStack;
}

//Функція заголовку
void header()
{
	cout << "\t  ***Laboratory work #1***" << endl;

	line(50, '-');

	cout << "\t***Done by Datskiv Andrii***" << endl;


}

//Функція лінії
void line(int n, char c)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
}

