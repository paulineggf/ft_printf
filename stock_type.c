/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:36:37 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/22 11:48:12 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	*stock_opt(char c, char *type)
{
	char	*new;
	int		len;

	len = ft_strlen(type);
	if (!(new = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	ft_strcpy(new, type);
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}
