#include "strops.h"

void	reverse(char *s)
{
	char	*end;
	char	tmp;

	end = s;
	while (*end != '\0')
		end++;
	while (s < end)
	{
		tmp = *s;
		*s++ = *--end;
		*end = tmp;
	}
}
