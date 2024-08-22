/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:00:50 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:00:52 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_convert_digit(long nbr, int base, char *hex)
{
    //?what's the difference between long and int?
    //-long: 8 bytes; larger range:-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807; operates more slowly.
    //-int: 4 bytes; smaller range:-2,147,483,648 to 2,147,483,647; operates more quickly.
    //-2147483648: after we ouput the '-' sign first, the value 2147483648 will be out of the range of an int.
    int len;
    
    len = 0;
    if(nbr >= base)
    {
        len = ft_convert_digit(nbr/base, base, hex);
        //Start to recursive, everytime we call this function, we remove the rightmost digit, 
        //then output the rightmost digit now we have in the following function.
        if(len == -1)
            return (-1);
        //Check if we output the number sucessfully every time.
        if(ft_print_character(hex[nbr % base]) != 1)
        //hex[nbr & base]:Modulo the number by base to find the rightmost digit directly.
            return (-1);
        len++;
        //Each time we output the digit sucessfully, len = len + 1;
        //The statements len++, len += 1, and len = len + 1 are equivalent in functionality. 
        //But the len++ is commonly used in the recursive functions.

    //?Why is the order like that?
    //-The return values and the printing order are reversed compared to the call order in a recursive function like this.
    }
    else
    {
        if(ft_print_character(hex[nbr]) != 1)
            return (-1);
        //hex[nbr]: Find the last digit directly.
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
        //Cause we just output a '-' sign.
    }
    else
    {
        len = ft_convert_digit(nbr, base, hex);
        if(len == -1)
            return (-1);
    }
    
    return (len);
}
