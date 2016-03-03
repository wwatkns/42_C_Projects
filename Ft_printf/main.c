#include "libftprintf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	//printf("\n%d\n", ft_printf("{%30S}", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	//printf("\n%d\n", printf("{%30S}", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	printf("\n%d\n", ft_printf("%ld", LONG_MIN));
	printf("\n%d\n", printf("%ld", LONG_MIN));
	return (0);
}
