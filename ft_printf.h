/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:40 by mzhang            #+#    #+#             */
/*   Updated: 2024/08/22 10:01:42 by mzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int ft_print_character(int c);
int ft_print_string(char *s);
int ft_print_pointer(void *ptr);
int ft_print_digit(long nbr, int base, int uplow);
int ft_printf(const char *format, ...);

# endif
