/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:45:32 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/10 18:45:02 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(va_list *args, int *count)
{
	char			*str;
	unsigned int	i;

	str = va_arg(*args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		(*count)++;
		i++;
	}
}
