/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:52 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:46:47 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_convert_pointer(uintptr_t nbr, int len)
{
    char *hex;
    
    hex = "0123456789abcdef";
    if(nbr >= 16)
    {
        len = ft_convert_pointer(nbr / 16, len);
        if(len == -1)
            return (-1);
        if(ft_print_character(hex[nbr % 16]) != 1)
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

int ft_print_pointer(void *ptr)
{
    int len;
    if(write(1,"0x",2) != 2)
        return (-1);
    len = 0;
    len += ft_convert_pointer((uintptr_t)ptr, len);
    if(len == -1)
        return (-1);
    else
        return (len + 2);
}
