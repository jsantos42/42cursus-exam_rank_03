#include "../headers/utils.h"

int	print_error(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (1);
}


int	is_in_range(float value, float min, float max)
{
	return (value >= min && value <= max);
}

