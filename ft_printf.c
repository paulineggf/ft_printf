/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:31:03 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/21 21:49:39 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	char	**ret;
	char	*type;
	int		i;
	int		j;
	va_list	ap;

	i = 0;
	j = 0;
	if (!(type = ft_strdup("")))
		return (0);
	if (!(ret = malloc(sizeof(char*) * (nb_string(str, &type) + 1))))
		return (0);
	va_start(ap, str);
	while (type[j] || *str)
	{
		ret[i] = ft_strndup(str, ft_strnlen(str, '%'));
		str = str + ft_strnlen(str, '%');
		if (type[j] == 'c')
			ret[i] = type_char(ap, str);
		else if (type[j] == 's')
			ret[i] = type_string(ap, str);
		else if (type[j] == 'p')
			ret[i] = type_p(ap, str);
		else if (type[j] == 'd')
			ret[i] = type_decimal(ap, str);
		else if (type[j] == 'i')
			ret[i] = type_int(ap, str);
		else if (type[j] == 'u')
			ret[i] = type_unsignedint(ap, str);
		else if (type[j] == 'x')
			ret[i] = type_hexa(ap, str);
		else if (type[j] == 'X')
			ret[i] = type_HEXA(ap, str);
	}
	ret[i] = ft_strndup(str, ft_strnlen(str, '%'));
}
