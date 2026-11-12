/* SOURCES: C/C04/ex03/ft_atoi.c C/C05/ex00/ft_iterative_factorial.c C/C05/ex01/ft_recursive_factorial.c C/C05/ex02/ft_iterative_power.c C/C05/ex03/ft_recursive_power.c C/C05/ex04/ft_fibonacci.c C/C05/ex05/ft_sqrt.c C/C05/ex06/ft_is_prime.c */
#include "check.h"

int	ft_atoi(char *str);
int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);

int	main(void)
{
	CHECK(ft_atoi(" ---+--+1234ab567") == -1234);
	CHECK(ft_atoi("\t\n 42") == 42);
	CHECK(ft_atoi("abc") == 0);
	CHECK(ft_iterative_factorial(0) == 1);
	CHECK(ft_iterative_factorial(5) == 120);
	CHECK(ft_iterative_factorial(-1) == 0);
	CHECK(ft_recursive_factorial(0) == 1);
	CHECK(ft_recursive_factorial(10) == 3628800);
	CHECK(ft_recursive_factorial(-3) == 0);
	CHECK(ft_iterative_power(2, 10) == 1024);
	CHECK(ft_iterative_power(0, 0) == 1);
	CHECK(ft_iterative_power(3, -1) == 0);
	CHECK(ft_recursive_power(-2, 3) == -8);
	CHECK(ft_recursive_power(0, 0) == 1);
	CHECK(ft_recursive_power(3, -1) == 0);
	CHECK(ft_fibonacci(0) == 0);
	CHECK(ft_fibonacci(1) == 1);
	CHECK(ft_fibonacci(10) == 55);
	CHECK(ft_fibonacci(-1) == -1);
	CHECK(ft_sqrt(16) == 4);
	CHECK(ft_sqrt(15) == 0);
	CHECK(ft_sqrt(1) == 1);
	CHECK(ft_sqrt(2147395600) == 46340);
	CHECK(ft_sqrt(2147483647) == 0);
	CHECK(ft_is_prime(2) == 1);
	CHECK(ft_is_prime(1) == 0);
	CHECK(ft_is_prime(97) == 1);
	CHECK(ft_is_prime(91) == 0);
	CHECK(ft_is_prime(2147483647) == 1);
	DONE();
}
