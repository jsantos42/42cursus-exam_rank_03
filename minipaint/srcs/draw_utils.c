#include "../headers/draw_utils.h"

void	draw_full_shape(t_info *info, t_op *op, char **matrix)
{
	int 	y;
	int		x;

	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			if (sqrtf(powf((int)op->start_x, 2) + powf((int)op->start_x, 2)) <= op->radius)
				matrix[y][x] = op->shape_char;
		}
	}
}

void	draw_contour(t_info *info, t_op *op, char **matrix)
{
	int 	y;
	int		x;

	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			if (sqrtf(powf((int)op->start_x, 2) + powf((int)op->start_x, 2)) <= op->radius)
				matrix[y][x] = op->shape_char;
		}
	}
}
