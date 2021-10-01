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
			if (x >= op->start_x && x <= op->start_x + op->width
				&& y >= op->start_y && y <= op->start_y + op->height)
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
			if (x >= op->start_x && x <= op->start_x + op->width
				&& y >= op->start_y && y <= op->start_y + op->height
				&& (x <= op->start_x + 1 || x >= op->start_x + op->width - 1
			   || y <= op->start_y + 1 || y >= op->start_y + op->height - 1))
				matrix[y][x] = op->shape_char;
		}
	}
}
