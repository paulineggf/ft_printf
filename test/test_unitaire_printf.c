/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unitaire_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:43:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 18:06:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		ret;
	char	c;

	c = 'D';
	printf("my ft_printf ret : %d\n", ft_printf("Hello %-10.5dpp%20s  cc%20c\n", 12, "ca va ?", c));
	printf("printf ret : %d\n", printf("Hello %-10.5dpp%20s  cc%20c\n", 12, "ca va ?", c));
	return (0);
}
