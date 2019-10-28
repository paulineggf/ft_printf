/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unitaire_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:43:22 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/28 19:11:59 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	int		ret;
	char	c;
	char 	str[] = "coucou";

	c = 'D';
	printf("my ft_printf ret : %d\n", ft_printf("Hello %20s  a%30.40da cc%c  b%p   p%-30.40u  blabla%-30x\n", "ca va ?", 420, c, str, 31464, -654));
	printf("printf ret : %d\n", printf("Hello %20s  a%30.40da cc%c  b%p   p%-30.40u  blabla%-30x\n", "ca va ?", 420, c, str, 31464, -654));
	return (0);
}

	/*printf("struct->str : %s\n", ((t_opt*)(lst->content))->str);
	printf("struct->type : %d\n", ((t_opt*)(lst->content))->type);
	printf("struct->tiret : %d\n", ((t_opt*)(lst->content))->tiret);
	printf("struct->zero : %d\n", ((t_opt*)(lst->content))->zero);
	printf("struct->point : %d\n", ((t_opt*)(lst->content))->point);
	printf("struct->wildcard_point : %d\n", ((t_opt*)(lst->content))->wildcard_point);
	printf("struct->wildcard_tiret : %d\n", ((t_opt*)(lst->content))->wildcard_tiret);
	printf("struct->wildcard_nbr : %d\n", ((t_opt*)(lst->content))->wildcard_nbr);
	printf("struct->nbr : %d\n\n", ((t_opt*)(lst->content))->nbr);*/

	/*printf("struct->str : %s\n", ((t_opt*)(lst->content))->str);
	printf("struct->type : %d\n", ((t_opt*)(lst->content))->type);
	printf("struct->tiret : %d\n", ((t_opt*)(lst->content))->tiret);
	printf("struct->zero : %d\n", ((t_opt*)(lst->content))->zero);
	printf("struct->point : %d\n", ((t_opt*)(lst->content))->point);
	printf("struct->wildcard_point : %d\n", ((t_opt*)(lst->content))->wildcard_point);
	printf("struct->wildcard_tiret : %d\n", ((t_opt*)(lst->content))->wildcard_tiret);
	printf("struct->wildcard_nbr : %d\n", ((t_opt*)(lst->content))->wildcard_nbr);
	printf("struct->nbr : %d\n\n", ((t_opt*)(lst->content))->nbr);*/