/* SOURCES: C/C03/ex05/ft_strlcat.c */
#include "check.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	buf[16];

	strcpy(buf, "abc");
	CHECK(ft_strlcat(buf, "defgh", 6) == 8);
	CHECK_STR(buf, "abcde");
	strcpy(buf, "abc");
	CHECK(ft_strlcat(buf, "def", 2) == 5);
	CHECK_STR(buf, "abc");
	strcpy(buf, "abc");
	CHECK(ft_strlcat(buf, "def", 16) == 6);
	CHECK_STR(buf, "abcdef");
	DONE();
}
