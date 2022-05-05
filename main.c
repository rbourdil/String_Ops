#include "strops.h"
#include <stdio.h>

#define BUFSIZE 200

int	main(int argc, char *argv[])
/*{
	size_t	len = 0;
	ssize_t	nread;
	char	res[200], *line = NULL;
	FILE	*fstream;

	if (argc != 2)
		exit(EXIT_FAILURE);
	fstream = fopen(argv[1], "r");
	res[0] = '\0';
	while ((nread = getline(&line, &len, fstream)) != -1)
	{
		line[nread - 1] = '\0';
		add(res, line);
		free(line);
		line = NULL;
		len = 0;
	}
	printf("%s\n", res);
	fclose(fstream);
	return (0);
}*/
{
	char	res[BUFSIZE];

	if (argc != 3)
		return (-1);
	res[0] = '\0';
	add(res, argv[1]);
	diff(res, argv[2]);
	printf("%s\n", res);
	return (0);
}
