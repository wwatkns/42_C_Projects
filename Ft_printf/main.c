#include "libftprintf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("\n%d\n", ft_printf("%.0p, %.p", 0, 0));
	printf("\n%d\n", printf("%.0p, %.p", 0, 0));
	return (0);
}
