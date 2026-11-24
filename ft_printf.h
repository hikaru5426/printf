/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:55:48 by hikaru            #+#    #+#             */
/*   Updated: 2026/11/24 12:05:38 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"


int		ft_printf(const char *str, ...);
void	parse(const char *str, va_list *args, int *count);

void	handle_char(va_list *args, int *count);
void	handle_string(va_list *args, int *count);
void	handle_void(va_list *args, int *count);
void	handle_int(va_list *args, int *count);
void	handle_unsigned_dec(va_list *args, int *count);
void	handle_hexa_lower(va_list *args, int *count);
void	handle_hexa_upper(va_list *args, int *count);

char	*ft_convert_tob16(unsigned int nb, int caps);

#endif
