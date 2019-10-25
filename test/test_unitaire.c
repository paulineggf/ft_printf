/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unitaire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:55:12 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/21 21:34:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*type;

	(void)argc;
	(void)argv;

	//TEST NB_STRING && STOCK_TYPE
	if (!(type = ft_strdup("")))
		return (0);
	if (nb_string("Hello", &type) == 1)
	{
		printf("nb_string 1 : OK\n");
		printf("TEST1 ft_strnlen : %s\n", ft_strndup("Hello", ft_strnlen("Hello", '%')));
		printf("type : %s\n", type);
	}
	else
		printf("False return : %d\n", nb_string("Hello", &type));
	free(type);
	if (!(type = ft_strdup("")))
		return (0);
	if (nb_string("Hello %d\n %-0s", &type) == 4)
	{
		printf("nb_string 2 : OK\n");
		printf("ft_strnlen : %d\n", ft_strnlen("Hello %d\n %-0s", '%'));
		printf("TEST2 ft_strnlen : %s\n", ft_strndup("Hello %d\n %-0s", ft_strnlen("Hello %d\n %-0s", '%')));
		printf("type : %s\n", type);
	}
	else
		printf("False return : %d\n", nb_string("Hello %d\n %-0s", &type));
	free(type);
	if (!(type = ft_strdup("")))
		return (0);
	if (nb_string("%0-c Helslo%% %d\n %-0s", &type) == 7)
	{
		printf("nb_string 3 : OK\n");
		printf("type : %s\n", type);
	}
	else
		printf("False return : %d\n", nb_string("%0-c Hello %d\n %-0s", &type));
	return (0);
}
