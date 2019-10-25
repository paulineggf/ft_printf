/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unitaire_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:43:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/25 17:38:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		ret;
	char	c;

	c = 'D';
	printf("my ft_printf ret : %d\n", ft_printf("Hello %-20.30s  %c\n", "ca va ?", c));
	printf("printf ret : %d\n", printf("Hello %-20.30s  %c\n", "ca va ?", c));
	return (0);
}
