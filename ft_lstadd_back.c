/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:00 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 12:54:17 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstadd_back(t_opt **alst, t_opt *new)
{
	
	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}
