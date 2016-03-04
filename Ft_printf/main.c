#include "libftprintf.h"
#include <locale.h>

// make re && gcc main.c -I./include libftprintf.a && clear && ./a.out

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("\n%d\n", ft_printf("{%05.S}", L"42 c est cool"));
	printf("\n%d\n", printf("{%05.S}", L"42 c est cool"));
	return (0);
}
