/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:13:53 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/21 20:25:32 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(unsigned int nbr)
{
	size_t		size;
	long long	nb;

	size = 1;
	nb = nbr;
	while (nb > 15)
	{
		size++;
		nb = nb / 16;
	}
	return (size);
}

char	*ft_convert_tob16(unsigned int nb, int caps)
{
	char	*base;
	char	*str;
	int		len;

	base = "0123456789abcdef";
	if (caps)
		base = "0123456789ABCDEF";
	len = count_digits(nb);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = base[nb % 16];
		nb /= 16;
	}
	return (str);
}

void	handle_hexa_lower(va_list *args, int *count)
{
	char	*str;
	int		size;

	str = ft_convert_tob16(va_arg(*args, unsigned int), 0);
	if (str)
	{
		size = ft_strlen(str);
		write(1, str, size);
		*count += size;
		free(str);
	}
}
