#include "strops.h"

void	diff(char *res, const char *op)
{
	char	*tmp;

	if (*res == '-' && *op == '-')
	{
		depop(res);
		if (comp(res, (op + 1)) <= 0)
		{
			tmp = strdup(res);
			strcpy(res, (op + 1));
			minus(res, tmp);
			free(tmp);
		}
		else
		{
			minus(res, (op + 1));
			pop(res, '-');
		}
	}
	else if (*res == '-')
	{
		depop(res);
		plus(res, op);
		pop(res, '-');
	}
	else if (*op == '-')
		add(res, (op + 1));
	else
	{
		if (comp(res, op) < 0)
		{
			tmp = strdup(res);
			strcpy(res, op);
			minus(res, tmp);
			free(tmp);
			pop(res, '-');
		}
		else
			minus(res, op);
	}
}

