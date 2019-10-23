/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:29:01 by pganglof          #+#    #+#             */
/*   Updated: 2019/10/23 20:38:34 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	printargs(char *argv, ...)
{
	va_list		ap;
	va_list		aq;
	char		*str;
	char		*buf;
	int			len;

	if (!argv)
		return ;
	va_start(ap, argv);
	str = va_arg(ap, char *);
	printf("ap : %s\n", str);
	va_copy(aq, ap);
	len = 0;
	while ((str = va_arg(ap, char *)) != NULL)
	{
		printf("str : %s\n", str);
		//va_copy(aq, ap);
		len += strlen(str);
	}
	va_end(ap);
	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return ;
	va_start(ap, argv);
	while ((str = va_arg(ap, char *)) != NULL)
		strcat(buf, str);
	va_end(ap);
	printf("%s\n", buf);
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printargs(argv[0], argv[1], argv[2], argv[3], (char*)NULL);
	return (0);
}
