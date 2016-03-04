#include "libftprintf.h"
#include <locale.h>

// make re && gcc main.c -I./include libftprintf.a && clear && ./a.out

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("\n%d\n", ft_printf("%9.2p", 1234));
	printf("\n%d\n", printf("%9.2p", 1234));
	return (0);
}
