#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main()
{
	int i = 1;

	while (i <= 1500)
	{
		rand();
		i++;
	}
	i = 1;
	while (i <= 500)
	{
		printf("%d ", rand() % 999999999);
		i++;
	}
	return (0);
}
