#pragma once
#include <cstdio>
#include <iostream>
#include <cstring>


#pragma warning(disable: 4996)

using namespace std;

const int N = 100;

struct Stack
{
	char *data = new char[N];

	Stack *next;
};


void push(char * info, Stack *& myStack);

char *pop(Stack *& myStack);

void printStek(Stack *& myStack);

void LoadFileToStek(FILE * f, Stack *& myStack);

void renumber(Stack *& myStack);

void purge(Stack *& myStack);

void header();

void line(int n, char c);

void menu();
