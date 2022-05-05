#include "strops.h"

void	mult(char *res, const char *op)
{
	char	*buf, *step;
	int		tmp, carry, i, j, offset, sign;

	sign = 1;
	if (*res == '-' && *op == '-')
	{
		depop(res);
		op++;
	}
	else if (*res == '-')
	{
		sign = -1;
		depop(res);
	}
	else if (*op == '-')
	{
		sign = -1;
		op++;
	}
	buf = (char *)calloc(strlen(res) + strlen(op) + 1, sizeof(char));
	step = (char *)calloc(strlen(res) + strlen(op) + 1, sizeof(char));
	if (buf == NULL || step == NULL)
		return ;
	offset = 0;
	for (i = strlen(op) - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = strlen(res) - 1; j >= 0; j--)
		{
			tmp = (op[i] - '0') * (res[j] - '0') + carry;
			carry = tmp / 10;
			step[j] = tmp % 10 + '0';
		}
		if (carry > 0)
			pop(step, carry + '0');
		append(step, '0', offset);
		plus(buf, step);
		bzero(step, strlen(step));
		offset++;
	}
	strcpy(res, buf);
	if (sign < 0 && *res != '0')
		pop(res, '-');
	if (*res == '0')
		*(res + 1) = '\0';
	free(buf);
	free(step);
}
