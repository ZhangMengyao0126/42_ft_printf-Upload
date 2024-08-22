/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:52 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:01:57 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_convert_pointer(uintptr_t nbr, int len)
//uintptr_t: unsigned integer pointer_type, a specific type to store the address of a pointer.
{
    char *hex;
    
    hex = "0123456789abcdef";
//Memory addresses in a computer are stored in binary form.
//"0x + Hexadecimal" form is simply a convenient way for humans to read and represent these binary addresses.
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
        //Cause we just output "0x"
}
