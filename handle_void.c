/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:23:23 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/10 20:37:27 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_mem_address(unsigned long nb, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		write_mem_address (nb / 16, count);
	write(1, &base[nb % 16], 1);
	(*count)++;
}

void	handle_void(va_list *args, int *count)
{
	void			*memory_address;
	unsigned long	nb;

	memory_address = va_arg(*args, void *);
	if (!memory_address)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	nb = (unsigned long)memory_address;
	write(1, "0x", 2);
	*count += 2;
	write_mem_address(nb, count);
}
