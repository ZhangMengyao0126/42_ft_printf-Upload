/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:04 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:46:47 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int ft_check_specifier(char spec, va_list ap)
{
    int len;

    len = 0;
    if(spec == 'c')
        len = ft_print_character(va_arg(ap, int));
    else if(spec == 's')
        len = ft_print_string(va_arg(ap, char*));
    else if(spec == 'p')
        len = ft_print_pointer(va_arg(ap,void*));
    else if(spec == 'd' || spec == 'i')
        len = ft_print_digit((long)(va_arg(ap, int)), 10, 1);
    else if(spec == 'u')
        len = ft_print_digit((long)(va_arg(ap, unsigned int)), 10, 1);
    else if(spec == 'x')
        len = ft_print_digit((long)(va_arg(ap, unsigned int)), 16, 1);
    else if(spec == 'X')
        len = ft_print_digit((long)(va_arg(ap, unsigned int)), 16, 2);
    else
        len = write(1, &spec, 1);
    return (len);
}

static int ft_check_format(const char *format, va_list ap, int len)
{
    int i;
    int j;

    i = 0;
    while(format[i] != '\0')
    {
        if(format[i] == '%')
        {
            if(!format[i + 1])
                return (len);
            j = ft_check_specifier(format[++i], ap);
            if(j == -1)
                return (-1);
            len += j;
        }
        else
        {
            if(ft_print_character(format[i]) != 1)
                return (-1);
            len++;
        }
        i++;
    }
    return (len);
}

int ft_printf(const char *format,...)
{
    va_list ap;
    int     len;
    len = 0;
    va_start(ap, format);
    len += ft_check_format(format, ap, len);
    va_end(ap);
    return (len);
}