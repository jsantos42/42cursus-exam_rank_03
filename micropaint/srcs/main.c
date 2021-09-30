#include "../headers/main.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Error: argument\n"));
	if (!read_file_and_print(argv[1]))
		return (print_error("Error: Operation file corrupted\n"));
	return (0);
}
