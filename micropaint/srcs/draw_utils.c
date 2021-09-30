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
			if (x >= (int)op->start_x + 1
				&& x <= (int)(op->start_x + op->width)
				&& y >= (int)op->start_y + 1
				&& y <= (int)(op->start_y + op->height))
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
			if (((x == (int)op->start_x + 1 || x == (int)op->start_x + op->width) && y >= (int)op->start_y + 1 && y <= (int)op->start_y + op->height)
				|| ((y == (int)op->start_y + 1 || y == (int)op->start_y + op->height) && x >= (int)op->start_x + 1 && x <= (int)op->start_x + op->width))
				matrix[y][x] = op->shape_char;
		}
	}
}
