/*
Program to reverse a string entered by user.
The program prints the reversed string.
The program tests if user provided string and reversed string are same and prints if it is a Palindrome.
*/


#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>


int main()
{
	char user_string[100] = "";
	char * rev_string;
	int len_string, palindrome, i, j;

	

	printf("%s", "Enter the String : ");
	scanf("%[^\n]s", user_string);

	
	//Check if user has entered any input
	if (strlen(user_string)==0)
	{
		printf("%s\n", "No input from user");
		return 0;
	}

	len_string = strlen(user_string);
	

	//Allocating memomry to string pointer and initializing.
	rev_string = (char *) calloc(sizeof(char),(len_string+1));



	for (i = len_string - 1, j=0; i >=0 ; i--, j++)
	{
		
		*(rev_string + j) = *(user_string + i);
	
	}

	printf("\n\n%s\n", "Reversed String");
	printf("%s\n",rev_string);


	//Checks if strings are Palindrome. (case is ignored for comparison
	for (i = 0; i < len_string; i++)
	{
		palindrome = 1;
		if (strcmpi((user_string + i),(rev_string + i)))
			palindrome = 0;

	}

	if (palindrome == 1)
		printf("\n\n%s\n", "It's a PALINDROME");

	else
		printf("\n\n%s\n", "Not a PALINDROME");

}