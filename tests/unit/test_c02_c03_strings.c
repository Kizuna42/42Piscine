/* SOURCES: C/C02/ex00/ft_strcpy.c C/C02/ex01/ft_strncpy.c C/C02/ex09/ft_strcapitalize.c C/C03/ex00/ft_strcmp.c C/C03/ex01/ft_strncmp.c C/C03/ex02/ft_strcat.c C/C03/ex03/ft_strncat.c C/C03/ex04/ft_strstr.c */
#include "check.h"

char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strcapitalize(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	buf[32];
	char	*pairs[][2] = {{"abc", "abc"}, {"abc", "abd"}, {"abd", "abc"},
		{"", "a"}, {"a", ""}, {"ab", "abc"}};
	size_t	i;
	char	cap[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	CHECK(ft_strcpy(buf, "hello") == buf);
	CHECK_STR(buf, "hello");
	memset(buf, 'x', sizeof(buf));
	ft_strncpy(buf, "hi", 5);
	CHECK(memcmp(buf, "hi\0\0\0x", 6) == 0);
	for (i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++)
	{
		CHECK(SIGN(ft_strcmp(pairs[i][0], pairs[i][1]))
			== SIGN(strcmp(pairs[i][0], pairs[i][1])));
		CHECK(SIGN(ft_strncmp(pairs[i][0], pairs[i][1], 2))
			== SIGN(strncmp(pairs[i][0], pairs[i][1], 2)));
	}
	CHECK(ft_strncmp("abc", "abd", 0) == 0);
	strcpy(buf, "foo");
	CHECK(ft_strcat(buf, "bar") == buf);
	CHECK_STR(buf, "foobar");
	ft_strncat(buf, "bazqux", 3);
	CHECK_STR(buf, "foobarbaz");
	CHECK(ft_strstr("hello world", "o w") == strstr("hello world", "o w"));
	CHECK(ft_strstr("hello", "") != NULL);
	CHECK(ft_strstr("aaab", "aab") != NULL);
	CHECK(ft_strstr("hello", "xyz") == NULL);
	CHECK_STR(ft_strcapitalize(cap),
		"Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un");
	DONE();
}
