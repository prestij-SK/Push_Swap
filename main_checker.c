#include "checker.h"

int main()
{
	// write(0, "eba\n", 4);
	char *ptr = get_next_line(0);
	write(1, "______\n", 7);
	write(1, ptr, 2);
	ptr = get_next_line(0);
	write(1, ptr, 2);
	write(1, "______\n", 7);
}