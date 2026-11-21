/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:38:57 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/21 20:24:12 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(va_list *args, int *count)
{
	char	*str;
	int		size;

	str = ft_itoa(va_arg(*args, int));
	if (str)
	{
		size = ft_strlen(str);
		write(1, str, size);
		*count += size;
		free(str);
	}
}
