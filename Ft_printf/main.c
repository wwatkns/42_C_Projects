#include "libftprintf.h"
#include <locale.h>

// make re && gcc main.c -I./include libftprintf.a && clear && ./a.out

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("\n%d\n", ft_printf("%15.4o", 42));
	printf("\n%d\n", printf("%15.4o", 42));
	return (0);
}
