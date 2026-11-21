/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:02:51 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/21 20:25:52 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hexa_upper(va_list *args, int *count)
{
	char	*str;
	int		size;

	str = ft_convert_tob16(va_arg(*args, unsigned int), 1);
	if (str)
	{
		size = ft_strlen(str);
		write(1, str, size);
		*count += size;
		free(str);
	}
}
