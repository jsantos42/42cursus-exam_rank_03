#include "../headers/read_utils.h"

static int	get_info(FILE *file, t_info *info);
static int	get_op(FILE *file, t_op *op);

int	read_file_and_print(char *arg)
{
	FILE	*file;
	t_info	info;
	t_op	op;
	char	**matrix;

	file = fopen(arg, "r");
	if (!file
		|| !get_info(file, &info)
		|| !init_matrix(&matrix, info.height, info.width)
		|| !fill_matrix(&matrix, info.height, info.width, info.bg_char))
		return (0);
	while (get_op(file, &op))
	{
		if (op.fill_flag == 'C')
			draw_full_shape(&info, &op, matrix);
		else if (op.fill_flag == 'c')
			draw_contour(&info, &op, matrix);
	}
	if (op.scan_ret == EOF)
	{
		print_matrix(&info, matrix);
		free_matrix(matrix, info.height);
		return (1);
	}
	else
	{
		free_matrix(matrix, info.height);
		return (0);
	}
}

static int	get_info(FILE *file, t_info *info)
{
	if (fscanf(file, "%d %d %c\n", &info->width, &info->height, &info->bg_char) != 3)
		return (0);
	if (info->width == 0 || info->height == 0
		|| !is_in_range(info->width, 0, 300)
		|| !is_in_range(info->height, 0, 300))
		return (0);
	return (1);
}

static int	get_op(FILE *file, t_op *op)
{
	op->scan_ret = fscanf(file, "%c %f %f %f %c\n", &op->fill_flag, &op->start_x,
			   &op->start_y, &op->radius, &op->shape_char);
	if (op->scan_ret != 5
	|| (op->fill_flag != 'c' && op->fill_flag != 'C')
	|| op->radius < 0)
		return (0);
	return (1);
}
