/* SOURCES: C/C05/ex07/ft_find_next_prime.c */
#include "check.h"

int	ft_find_next_prime(int nb);

int	main(void)
{
	CHECK(ft_find_next_prime(-5) == 2);
	CHECK(ft_find_next_prime(2) == 2);
	CHECK(ft_find_next_prime(14) == 17);
	CHECK(ft_find_next_prime(2147483646) == 2147483647);
	DONE();
}
