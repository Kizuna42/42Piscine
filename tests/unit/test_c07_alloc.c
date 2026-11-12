/* SOURCES: C/C07/ex00/ft_strdup.c C/C07/ex01/ft_range.c C/C07/ex02/ft_ultimate_range.c */
#include "check.h"

char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	char	*s;
	int		*r;

	s = ft_strdup("hello");
	CHECK_STR(s, "hello");
	free(s);
	r = ft_range(-2, 3);
	CHECK(r && r[0] == -2 && r[4] == 2);
	free(r);
	CHECK(ft_range(3, 3) == NULL);
	CHECK(ft_ultimate_range(&r, 0, 4) == 4);
	CHECK(r && r[3] == 3);
	free(r);
	CHECK(ft_ultimate_range(&r, 5, 1) == 0 && r == NULL);
	DONE();
}
