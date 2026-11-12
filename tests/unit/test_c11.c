/* SOURCES: C/C11/ex02/ft_any.c C/C11/ex03/ft_count_if.c */
#include "check.h"

int	ft_any(char **tab, int (*f)(char *));
int	ft_count_if(char **tab, int (*f)(char *));

static int	starts_with_a(char *s)
{
	return (s[0] == 'a');
}

int	main(void)
{
	char	*tab[] = {"xyz", "abc", "aaa", "b", NULL};
	char	*none[] = {"x", NULL};

	CHECK(ft_any(tab, starts_with_a) == 1);
	CHECK(ft_any(none, starts_with_a) == 0);
	CHECK(ft_count_if(tab, starts_with_a) == 2);
	CHECK(ft_count_if(none, starts_with_a) == 0);
	DONE();
}
