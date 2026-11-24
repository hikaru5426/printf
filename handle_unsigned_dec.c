/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:54:37 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/24 12:11:09 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digit(long nbr)
{
	size_t	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_uint(unsigned int nb)
{
	char	*str;
	int		idx;
	long	nbr;

	nbr = nb;
	idx = ft_count_digit(nbr);
	str = malloc((idx + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[idx--] = '\0';
	while (idx >= 0)
	{
		str[idx--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

void	handle_unsigned_dec(va_list *args, int *count)
{
	char	*str;
	int		size;

	str = ft_itoa_uint(va_arg(*args, unsigned int));
	if (str)
	{
		size = ft_strlen(str);
		write(1, str, size);
		*count += size;
		free(str);
	}
}
