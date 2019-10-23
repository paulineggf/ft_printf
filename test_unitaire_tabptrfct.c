/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unitaire_tabptrfct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:23:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 18:48:28 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fct_p(va_list ap, t_opt *opt)
{
	printf("CA MARCHE !!\n");
}

int		main(int argc, char **argv)
{
	t_opt	*opt;
	void	(*f[1])(va_list, t_opt *);

	opt = NULL;
	opt = init_lst("%p");
	while (opt)
	{
		printf("opt->str : %s\n", opt->str);
		printf("opt->type : %c\n", opt->type);
		printf("opt->tiret : %d\n", opt->tiret);
		printf("opt->zero : %d\n", opt->zero);
		printf("opt->point : %d\n",opt->point);
		printf("opt->wildcard : %d\n", opt->wildcard);
		printf("opt->nbr : %d\n", opt->nbr);
		printf("\n");
		opt = opt->next;
	}
	//if (!(f = malloc(sizeof(*f))))
	//	return (0);
	init_ptrf(f);
	f[0]();
	//f[opt->type];
	return (0);
}
