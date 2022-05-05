#include "strops.h"

void	plus(char *res, const char *op)
{
	int	carry, tmp, i, j;

	carry = 0;
	for (i = strlen(res) - 1, j = strlen(op) - 1; i >= 0 && j >= 0; i--, j--)
	{
		tmp = (res[i] - '0') + (op[j] - '0') + carry;
		carry = tmp / 10;
		res[i] = tmp % 10 + '0';
	}
	for (; i >= 0; i--)
	{
		tmp = res[i] - '0' + carry;
		carry = tmp / 10;
		res[i] = tmp % 10 + '0';
	}
	for (; j >= 0; j--)
	{
		tmp = op[j] - '0' + carry;
		carry = tmp / 10;
		pop(res, tmp % 10 + '0');
	}
	if (carry > 0)
		pop(res, carry + '0');
}

void	minus(char *res, const char *op)
{
	int	carry, tmp, i, j;

	carry = 0;
	for (i = strlen(res) - 1, j = strlen(op) - 1; i >= 0 && j >= 0; i--, j--)
	{
		tmp = (res[i] - '0') - (op[j] - '0') - carry;
		carry = (tmp >= 0) ? 0 : 1;
		res[i] = (tmp >= 0) ? tmp + '0' : tmp + 10 + '0';
	}
	for (; i >= 0; i--)
	{
		tmp = res[i] - '0' - carry;
		carry = (tmp >= 0) ? 0 : 1;
		res[i] = (tmp >= 0) ? tmp + '0' : tmp + 10 + '0';
	}
	while (*res == '0' && *(res + 1) != '\0')
		depop(res);
}

int	comp(const char *op1, const char *op2)
{
	if (*op1 == '-' && *op2 == '-')
	{
		op1++;
		op2++;
		if (strlen(op1) != strlen(op2))
			return ((int)strlen(op2) - (int)strlen(op1));
		return (strcmp(op1, op2) * -1);
	}
	else if (*op1 == '-')
		return (-1);
	else if (*op2 == '-')
		return (1);
	if (strlen(op1) != strlen(op2))
		return ((int)strlen(op1) - (int)strlen(op2));
	return (strcmp(op1, op2));
}
