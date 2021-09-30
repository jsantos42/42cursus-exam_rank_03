#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info {
	int		width;
	int		height;
	char	bg_char;
}	t_info;

typedef struct s_op {
	char	fill_flag;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	shape_char;
}	t_op;

# include "read_utils.h"
# include "matrix_utils.h"
# include "draw_utils.h"
# include "utils.h"

#endif