/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:21:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 14:47:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_op
{
	char		*str;
	char		type;
	int			tiret;
	int			zero;
	int			point;
	int			wildcard;
	int			nbr;
	struct s_op *next;
}				t_opt;

enum
{
	p,
};

int				ft_printf(const char *str, ...);
int				ft_charset(char c, char const *set);
int				ft_strnlen(const char *s, char c);
int				ft_natoi(const char *s, int *i);
int				ft_atoi(const char *s, int *i);
char			*stock_type(char c, char *type);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
void			ft_lstadd_front(t_opt **alst, t_opt *new);
void			ft_lstadd_back(t_opt **alst, t_opt *new);
t_opt			*ft_lstlast(t_opt *lst);
t_opt			*nb_string(const char *str);
t_opt			*init_lst(const char *str);

#endif
