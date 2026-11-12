/* SOURCES: C/C07/ex05/ft_split.c */
#include "check.h"

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char	**t;
	int		i;

	t = ft_split("  hello,,world 42 ", " ,");
	CHECK(t != NULL);
	CHECK_STR(t[0], "hello");
	CHECK_STR(t[1], "world");
	CHECK_STR(t[2], "42");
	CHECK(t[3] == NULL);
	for (i = 0; t[i]; i++)
		free(t[i]);
	free(t);
	t = ft_split("", " ");
	CHECK(t != NULL && t[0] == NULL);
	free(t);
	DONE();
}
