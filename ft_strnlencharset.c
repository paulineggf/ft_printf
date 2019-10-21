/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlencharset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:17:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/21 21:20:27 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnlen(const char *s, char const *set)
{
	int		i;

	i = 0;
	while (s[i] && ft_charset(s[i], set) == -1)
		i++;
	return (i);
}
