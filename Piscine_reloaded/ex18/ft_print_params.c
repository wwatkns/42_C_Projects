/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:57:52 by wwatkins          #+#    #+#             */
/*   Updated: 2016/11/29 15:43:41 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int j;
	int index;

	j = 0;
	index = 1;
	while (index < argc)
	{
		while (argv[index][j] != '\0')
		{
			ft_putchar(argv[index][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		index++;
	}
	return (0);
}
