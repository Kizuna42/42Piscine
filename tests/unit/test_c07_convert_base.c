/* SOURCES: C/C07/ex04/ft_convert_base.c C/C07/ex04/ft_convert_base2.c */
#include "check.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

static void	check_conv(char *nbr, char *from, char *to, char *expected)
{
	char	*s;

	s = ft_convert_base(nbr, from, to);
	CHECK_STR(s, expected);
	free(s);
}

int	main(void)
{
	check_conv("1010", "01", "0123456789", "10");
	check_conv("  --+-ff", "0123456789abcdef", "01", "-11111111");
	check_conv("0", "01", "0123456789", "0");
	CHECK(ft_convert_base("1", "0", "01") == NULL);
	CHECK(ft_convert_base("1", "01", "0+") == NULL);
	DONE();
}
