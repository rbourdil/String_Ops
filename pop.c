void	pop(char *s, char c)
{
	char	tmp;

	while (c != '\0')
	{
		tmp = *s;
		*s++ = c;
		c = tmp;
	}
	*s = '\0';
}

void	depop(char *s)
{
	while (*s != '\0')
	{
		*s = *(s + 1);
		s++;
	}
}

void	append(char *s, char c, int n)
{
	while (*s != '\0')
		s++;
	while (n-- > 0)
		*s++ = c;
	*s = '\0';
}
