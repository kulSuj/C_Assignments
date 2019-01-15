//Program to convert a Roman Number to decimal number
// Roman Numbers are represented by seven different letters : I, V, X, L, C, D, M, which represents 1, 5, 10, 50, 100, 500 and 1000 respectively.
#include <pch.h>
#include <stdio.h>
#include <string.h>

int validRomanLetters(char roman_number[]);
int countSequence(char roman_number[]);
int testForPrecedence(char roman_number[]);
int checkForInvalidSequence(char roman_number[]);
void convertToDecimal(char roman_number[]);
int toDigit(char ch);

int main()
{

	char roman_number[20] = "";


	printf("%s", "Enter the Roman Number : ");
	scanf("%[^\n]s", roman_number);

	//Check if user has input any string.
	if (strlen(roman_number) == 0)
	{
		printf("%s\n", "No input from user");
		return 0;
	}

	//Check if user has entered valid roman letters ie. roman_number string contains only following characters. I, V, X, L, C, D, M.
	if (validRomanLetters(roman_number) == 0)
		return 0;

	//Check if any roman digit is not repeated more than 3 times.
	if (countSequence(roman_number) == 0)
		return 0;

	/*Check the precedence of roman letters.
	  Precedence rule :
	  "I" can precede "V" and "X"
	  "X" can precede "L" and "C"
	  "C" can precede "D" and "M"*/
	if (testForPrecedence(roman_number) == 0)
		return 0;

	//Test for some invalid sequence in roman numbers.
	if (checkForInvalidSequence(roman_number) == 0)
		return 0;

	//Convert the roman number to decimal number.
	convertToDecimal(roman_number);

	return 0;

}

int validRomanLetters(char roman_number[])
{

	//Check if roman number is formed from letters I, V, X, L, C, D, M only.
	int len_roman, i;

	len_roman = strlen(roman_number);

	for (i = 0; i < len_roman; i++)
	{
		switch (roman_number[i])
		{
			case 'I':
				break;

			case 'V':
				break;

			case 'X':
				break;

			case 'L':
				break;

			case 'C':
				break;

			case 'D':
				break;

			case 'M':
				break;

			default :
				printf("Inavlid Character \'%c\' in roman number: %s",roman_number[i], roman_number);
				return 0;
		}

	}

	return 1;
}

int countSequence(char roman_number[])
{

	//Check if roman digit in roman number is repeated more than 3 times.
	int i, j, len_roman, counter;

	len_roman = strlen(roman_number);


	if (len_roman == 1) //Single char in roman number
		return 1;


	for (i = 0; i < len_roman; i++)
	{
		if (roman_number[i] == roman_number[i + 1])
		{
			//Roman literals "V", "L", "D" are not allowed to repeat more than once.
			if ((roman_number[i] == 'V') || (roman_number[i] == 'L') || (roman_number[i] == 'D'))
			{
				printf("\nRoman Literal %c cannot be present more than once.\n", roman_number[i]);
				return 0;
			}

			//Loop to check if any roman literal is repeated more than 3 times, the roman number cannot have a literal more than three times.
			counter = 2;

			for (j = i + 2; j < len_roman; j++)
				if (roman_number[i] == roman_number[j])
				{
					counter++;
				}
				else
					break;

			//If counter value is more than 3 error message will be printed.
			if (counter > 3)
			{
				printf("Roman literal %c cannot be repeated more than 3 times in a sequence.", roman_number[i]);
				return 0;

			}


		}



	}

	return 1;
}



int testForPrecedence(char roman_number[])
{

	//Precedence rule :
	//"I" can precede "V" and "X"
	//"X" can precede "L" and "C"
	//"C" can precede "D" and "M"

	int i, j, len_roman, illegal_precedence;


	len_roman = strlen(roman_number);

	for (i = 0; i < (len_roman-1); i++)
	{
		illegal_precedence = 0;
		for (j = (i+1); j < len_roman; j++)
		{
			if (roman_number[i] == 'I')
			{
				if ((roman_number[j] == 'L') || (roman_number[j] == 'C') || (roman_number[j] == 'D') || (roman_number[j] == 'M'))
				{
					illegal_precedence = 1;
					break;
				}
			}
			
			if ((roman_number[i] == 'V') && (roman_number[j] != 'I'))
			{
				illegal_precedence = 1;
				break;
			}

			if ((roman_number[i] == 'X') && ((roman_number[j] == 'D') || (roman_number[j] == 'M')))
			{
				illegal_precedence = 1;
				break;
			}
			
			if ((roman_number[i] == 'L') && ((roman_number[j] == 'C') || (roman_number[j] == 'D') || (roman_number[j] == 'M')))
			{
				illegal_precedence = 1;
				break;
			}

			if ((roman_number[i] == 'D') && (roman_number[j] == 'M'))
			{
				illegal_precedence = 1;
				break;
			}
		}

		if (illegal_precedence)
		{
			printf("%c cannot preceed %c", roman_number[i], roman_number[j]);
			return 0;
		}

				
	}



	return 1;
}

int checkForInvalidSequence(char roman_number[])
{
	int  invalidSequence = 0;
	
	if (strstr(roman_number, "IVI") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "IXI") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "IXV") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "IXX") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "XLX") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "XCX") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "XCL") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "CDC") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "CMC") != NULL)
		invalidSequence = 1;

	else if (strstr(roman_number, "CMD") != NULL)
		invalidSequence = 1;


	if (invalidSequence)
	{
		printf("\nInvalid Roman Number.\n");
		return 0;
	}
	else
		return 1;

}


void convertToDecimal(char roman_number[])
{
	int len_roman, i, decimalValue,digit1, digit2;

	len_roman = strlen(roman_number);


	for (i = (len_roman - 1); i >= 0; i--)
	{
		if (i == (len_roman - 1))
			decimalValue = toDigit(roman_number[i]);

		else
		{

			digit1 = toDigit(roman_number[i]);
			digit2 = toDigit(roman_number[i + 1]);

			if (digit1 < digit2)
				decimalValue = decimalValue - digit1;

			else
				decimalValue = decimalValue + digit1;
		}

	}

	printf ("The decimal form of roman number \'%s\' is: %d", roman_number, decimalValue);
}

int toDigit(char ch)
{

	switch (ch)
	{
		case 'I' :
			return 1;

		case 'V' :
			return 5;

		case 'X' :
			return 10;

		case 'L' :
			return 50;

		case 'C' :
			return 100;

		case 'D' :
			return 500;

		case 'M' :
			return 1000;
	}

}