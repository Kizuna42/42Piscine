/* SOURCES: C/C02/ex10/ft_strlcpy.c */
#include "check.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	buf[16];

	CHECK(ft_strlcpy(buf, "hello world", 6) == 11);
	CHECK_STR(buf, "hello");
	buf[0] = 'z';
	CHECK(ft_strlcpy(buf, "abc", 0) == 3);
	CHECK(buf[0] == 'z');
	DONE();
}
