/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:00:50 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:46:47 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_convert_digit(long nbr, int base, char *hex)
{
    int len;
    
    len = 0;
    if(nbr >= base)
    {
        len = ft_convert_digit(nbr/base, base, hex);
        if(len == -1)
            return (-1);
        if(ft_print_character(hex[nbr % base]) != 1)
            return (-1);
        len++;
    }
    else
    {
        if(ft_print_character(hex[nbr]) != 1)
            return (-1);
        len++;
    }
    return (len);
}

int ft_print_digit(long nbr, int base, int uplow)
{
    int len;
    char *hex;
    
    if(uplow == 1)
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if(nbr < 0)
    {
        if(write(1,"-",1) != 1)
            return (-1);
        len = ft_convert_digit(-nbr, base, hex);
        if(len == -1)
            return (-1);
        len += 1;
    }
    else
    {
        len = ft_convert_digit(nbr, base, hex);
        if(len == -1)
            return (-1);
    }
    
    return (len);
}
