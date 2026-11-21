/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:16:55 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/21 20:26:42 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_detected(char c, va_list *args, int *count)
{
	if (c == 'c')
		handle_char(args, count);
	else if (c == 's')
		handle_string(args, count);
	else if (c == 'p')
		handle_void(args, count);
	else if (c == 'd' || c == 'i')
		handle_int(args, count);
	else if (c == 'u')
		handle_unsigned_dec(args, count);
	else if (c == 'x')
		handle_hexa_lower(args, count);
	else if (c == 'X')
		handle_hexa_upper(args, count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

void	parse(const char *str, va_list *args, int *count)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			arg_detected(str[i + 1], args, count);
			i += 2;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			(*count)++;
			i++;
		}
	}
}
