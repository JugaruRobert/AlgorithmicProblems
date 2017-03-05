
// Prb1.cpp : Defines the entry point for the console application.
//1. a. Generate all the prime numbers smaller than a given natural number n.
//b.Given a vector of numbers, find the longest increasing contiguous subsequence.

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int prim(int x)
{
	/*
	Function used for testing if an integer is prime.
	input: x - an integer number
	output: 0 if the number is not prime, 1 if the number is prime.
	*/
	if (x < 2 || (x % 2 == 0 && x != 2))
		return 0;
	else
	{
		for (int d = 3; d*d <= x; d += 2)
			if (x%d == 0)
				return 0;
	}
	return 1;
}

void first(int x)
{
	/*
	Function used for printing in the console all the prime numbers smaller than a specific integer given as a parameter.
	Variables used : p - an integer that has initially the value 2, and then all the odd numbers starting from 3 to n;
	input: x - an integer number
	output: all the prime numbers smaller than x.
	*/
	int p = 2;
	if (x <= 2)
		printf("There are no prime numbers smaller than %d.", x);
	else
	{
		if (x != 3)
			printf("Prime numbers : %d ", p);
		else
			printf("The only prime number is %d" , p);

		p = p + 1;

		while (p < x)
		{
			
			if (prim(p) == 1)
			{
				printf(" , ");
				printf("%d", p);
			}
			p = p + 2;
		}
		printf(".");
	}
	

}

int *readVector(int *n)
{
	/*
	Function used for reading from the keyboard the lenght of an array and its elements.
	input: a - an array , n - an integer, the lenght of the array
	output: the lenght of the vector and the array with all the elements.
	*/
	printf("\nPlease enter the lenght of the vector: ");
	scanf_s("%d", &*n);
	int *a = (int*)malloc(*n * sizeof(int));
	for (int i = 0; i < *n; i++)
	{
		printf("a[%d]= ", i);
		scanf_s("%d", &a[i]);
	}
	return a;

}

void second(int a[100], int &n)
{
	/*
	Function used for printing in the console the longest increasing contiguous subsequence of elements from the vector.
	If there are two subsequences of same size, the first one is printed.
	Variables used : lc - integer representing the current lenght of the current subsequence of elements,lt - integer representing the lenght of the current longest subsequence,pozf - integer
	representing the index of the final element in the longest subsequence of elements.
	input: a -an array, n -an integer representing the lenght of the vector.
	output: The elements of the vector forming the longest increasing contiguous subsequence.
	*/
	int lc = 1, lt = 0,pozf = 0;
	for(int i=0;i<n-1;i++)
	{
		if (a[i] < a[i + 1])
			lc = lc + 1;
		else
		{
			if (lc > lt)
			{
				lt = lc;
				pozf = i;
			}
			lc = 1;
		}
	}
	if (lc > lt)
	{
		lt = lc;
		pozf = n - 1;
	}
	printf("The longest increasing contiguous subsequence is: ");
	for(int i=lt-pozf-1;i<pozf;i++)
		printf("%d , ", a[i]);
	printf("%d.", a[pozf]);
}

int main()
{
	/*	
	Main function used for reading the user's command from the keyboard and callinf the corresponding functions for each command.
	The command is represented by an integer read from the keyboard.It can be 0 - exit, 1 - first problem, 2 - second problem.A message is printed if the command is invalid.
	A menu is printed on the screen with all the available commands.
	input: - 
	output: - 
	*/
	char command[100];
	while(true)
	{	

		printf("Menu:\n   1. Generate all the prime numbers smaller than a given natural number n.\n   2. Given a vector of numbers, find the longest increasing contiguous subsequence.\n   0. Exit.\nPlease enter your command:");
		scanf("%99s", command);
		if (strlen(command) != 1)
			printf("\nINVALID COMMAND! Please enter 1,2,3 or 0!");
		else
		{
			if (command[0] == '0')
			{
				printf("\nGoodbye! :D");
				break;
			}
			else if (command[0] == '1')
			{
				int n;
				printf("\nPlease enter the number: ");
				scanf("%d", &n);
				first(n);
			}
			else if (command[0] == '2')
			{
				int n, *a;
				a=readVector(&n);
				second(a, n);
				free(a);
			}
			else
				printf("\nINVALID COMMAND! Please enter 1,2,3 or 0!");
			
		}
		printf("\n\n");
	}
	printf("\n\n");
	system("pause");
    return 0;
}


