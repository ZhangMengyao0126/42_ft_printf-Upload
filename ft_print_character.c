/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:57:55 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 11:05:12 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_character(int c)
{
	if ((write(1, &c, 1) != 1))
		return (-1);
	return (1);
}

int	ft_print_string(char *s)
{
	int	i;

	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_print_character(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
