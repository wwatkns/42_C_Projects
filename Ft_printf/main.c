#include "libftprintf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("\n%d\n", ft_printf("[%+s]", 0));
	printf("\n%d\n", printf("[%+s]", 0));
	return (0);
}
