#include "../headers/matrix_utils.h"

int	init_matrix(char ***matrix, int height, int width)
{
	int iter;

	*matrix = NULL;
	*matrix = malloc(height * sizeof(char *));
	if (!*matrix)
		return (0);
	iter = -1;
	while (++iter < height)
	{
		(*matrix)[iter] = NULL;
		(*matrix)[iter] = malloc((width + 1) * sizeof(char));
		if (!(*matrix)[iter])
		{
			free_matrix(*matrix, iter);
			return (0);
		}
	}
	return (1);
}

int	fill_matrix(char ***matrix, int height, int width, char bg_char)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			(*matrix)[y][x] = bg_char;
		(*matrix)[y][x] = '\0';
	}
	return (1);
}

void	free_matrix(char **matrix, int nb_rows)
{
	int	iter;

	if (matrix)
	{
		iter = -1;
		while (++iter < nb_rows && matrix[iter])
			free(matrix[iter]);
		free(matrix);
	}
}

void	print_matrix(t_info *info, char **matrix)
{
	int	iter;

	iter = -1;
	while (++iter < info->height)
		printf("%s\n", matrix[iter]);
}
