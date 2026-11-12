#ifndef CHECK_H
# define CHECK_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

static int	g_fail = 0;

# define CHECK(cond) do { if (!(cond)) { \
	fprintf(stderr, "%s:%d: CHECK failed: %s\n", __FILE__, __LINE__, #cond); \
	g_fail = 1; } } while (0)
# define CHECK_STR(a, b) do { const char *a_ = (a); const char *b_ = (b); \
	if (a_ == NULL || strcmp(a_, b_) != 0) { \
	fprintf(stderr, "%s:%d: \"%s\" != \"%s\"\n", __FILE__, __LINE__, \
	a_ ? a_ : "(null)", b_); g_fail = 1; } } while (0)
# define SIGN(x) (((x) > 0) - ((x) < 0))
# define DONE() return (g_fail)

#endif
