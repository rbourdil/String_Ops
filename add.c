#include "strops.h"

void	add(char *res, const char *op)
{
	char	*tmp;

	if (*res == '-' && *op == '-')
	{
		depop(res);
		plus(res, (op + 1));
		pop(res, '-');
	}
	else if (*res == '-')
	{
		depop(res);
		if (comp(res, op) <= 0)
		{
			tmp = strdup(res);
			strcpy(res, op);
			minus(res, tmp);
			free(tmp);
		}
		else
		{
			minus(res, op);
			pop(res, '-');
		}
	}
	else if (*op == '-')
	{
		if (comp(res, (op + 1)) < 0)
		{
			tmp = strdup(res);
			strcpy(res, (op + 1));
			minus(res, tmp);
			free(tmp);
			pop(res, '-');
		}
		else
			minus(res, (op + 1));
	}
	else
		plus(res, op);
}
