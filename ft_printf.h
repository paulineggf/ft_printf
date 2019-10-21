/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:21:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/21 21:29:02 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_charset(char c, char const *set);
int		nb_string(const char *str, char **type);
int		ft_strnlen(const char *s, char c);
char	*stock_type(char c, char *type);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif
