/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:30:35 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/22 12:31:38 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstadd_front(t_opt **alst, t_opt *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
}
