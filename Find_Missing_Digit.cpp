#include "pch.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "math.h"

void split_expression(char user_expression[], char *operator_operand[20]);
void find_missing_digit(char *operator_operands[20]);
void buildDigits(char *operator_operands[20], int arr_operands[3], int digit);

int main()
{
	char user_expression[100]="";
	char *operator_operands[20];
	int len_expression, i;

	//Accept input from user
	printf("Enter the expression :");
	scanf("%[^\n]s", user_expression);

	//Test to check if no input from user.
	if (strlen(user_expression) == 0)
	{
		printf("No input from user");
		return 0;
	}

	//Initialize array to store two operands, answer and operator.
	for (i = 0; i < 4; i++)
	{
		*(operator_operands + i) = (char *)calloc(sizeof(char), 20);
	}

	//Call split_expression function to fetch  operands,operator and result in a array.
	split_expression(user_expression, operator_operands);
	
	//Call find_missing_digit to find the missing digit in the expression.
	find_missing_digit(operator_operands);

}

void split_expression(char user_expression[], char *str_value[20])
{

	char *index_eq, *index_op, *temp_str;
	int i, j, int_ans_len, int_op_len, int_exp_len;

	//Check which operator used in expression and store the address of the same in a pointer.
	if (strstr(user_expression, "*"))
	{
		str_value[3][0] = '*';
		index_op = strstr(user_expression, "*");
	}
	else if (strstr(user_expression, "/"))
	{	
		str_value[3][0] = '/';
		index_op = strstr(user_expression, "/");
	}
	else if (strstr(user_expression, "+"))
	{
		str_value[3][0] = '+';
		index_op = strstr(user_expression, "+");
	}
	else if (strstr(user_expression, "-"))
	{
		str_value[3][0] = '-';
		index_op = strstr(user_expression, "-");
	}

	//Fetch and store the address of the equakto sign in a pointer.
	index_eq = strstr(user_expression, "=");
	int_ans_len = strlen(index_eq);

	//Store the result value in array.
	for (i = 1, j=0; i < int_ans_len; i++)
	{
		str_value[2][i - 1] = *(index_eq + i);

	}


	int_op_len = strlen(index_op);

	//Store the second operand value in array.
	for (i = 1; i < (int_op_len - int_ans_len); i++)
	{
		str_value[1][i-1] = *(index_op + i);
	}


	int_exp_len = strlen(user_expression);
	
	//Store the first operand value in array.
	for (i = 0; i < (int_exp_len - int_op_len); i++)
	{
		str_value[0][i] = *(user_expression + i);
	}
	
	
}

void find_missing_digit(char *operator_operands[20])
{
	char operator_sign, digit1[20], digit2[20],  answer[20];
	int arr_operands[3];
	int  actual_answer, found_value, i;

	operator_sign = operator_operands[3][0];
	found_value = 0;

	for (i = 0; i < 10; i++)
	{
		//Convert the operators in string type to integer type.
		buildDigits(operator_operands, arr_operands, i);
		
		//Perform arithmetic operation according to the operator.
		if (operator_sign == '*')
		{
			actual_answer = arr_operands[0] * arr_operands[1];
		}
		else if (operator_sign == '/')
		{
			actual_answer = arr_operands[0] / arr_operands[1];
		}
		else if (operator_sign == '+')
		{
			actual_answer = arr_operands[0] + arr_operands[1];
		}
		else if (operator_sign == '-')
		{
			actual_answer = arr_operands[0] - arr_operands[1];
		}

		if (actual_answer == arr_operands[2])
		{
			printf("The missing digit is %d\n", i);
			printf("The expression is %d %c %d = %d", arr_operands[0], operator_sign, arr_operands[1], actual_answer);
			found_value = 1;
			break;
		}
	}

	if (found_value == 0)
		printf("Incorrect Expression\n");
}

void buildDigits(char * operator_operands[20], int arr_operands[3], int digit)
{
	int i, j, decimal_multi, number, int_value, negative_sign ;
	char * int_digits[20];
	
	//Convert each digit in char type to int type.
	for (i = 0; i < 3; i++)
	{
		*(int_digits + i) = (char *)calloc(sizeof(char), 20);
		for (j = 0; j < strlen(*(operator_operands + i)); j++)
		{

			if (operator_operands[i][j] == '?')
				int_digits[i][j] = digit + '0';
			else
				int_digits[i][j] = operator_operands[i][j];
		}
	}

	
	//For each row in array int_digits, build a single integer joining each element in the given row.
	for (i = 0; i < 3; i++)
	{
		decimal_multi = 0;
		arr_operands[i] = 0;
		negative_sign = 0;
		for (j = (strlen(operator_operands[i]) - 1); j >= 0; j--)
		{
			if (int_digits[i][j] == '-')
			{
				negative_sign = 1;
				break;
			}

			int_value= int_digits[i][j] - '0';
			number = pow(10, decimal_multi) * int_value;

			arr_operands[i] = arr_operands[i] +number ;
			decimal_multi++;

		}
		//Add negative sign to the integer if any exists.
		if (negative_sign == 1)
		{
			arr_operands[i] = arr_operands[i] * (-1);
		}
	}

	return;
}