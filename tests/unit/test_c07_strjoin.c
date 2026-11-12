/* SOURCES: C/C07/ex03/ft_strjoin.c */
#include "check.h"

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*s;
	char	*strs[] = {"a", "bc", "def"};

	s = ft_strjoin(3, strs, ", ");
	CHECK_STR(s, "a, bc, def");
	free(s);
	s = ft_strjoin(1, strs, ", ");
	CHECK_STR(s, "a");
	free(s);
	s = ft_strjoin(0, strs, ", ");
	CHECK_STR(s, "");
	free(s);
	DONE();
}
