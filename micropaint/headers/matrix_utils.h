#ifndef MATRIX_H
#define MATRIX_H

#include "main.h"

int		init_matrix(char ***matrix, int height, int width);
int		fill_matrix(char ***matrix, int height, int width, char bg_char);
void	free_matrix(char **matrix, int nb_rows);
void	print_matrix(t_info *info, char **matrix);

#endif