/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <sjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:51:21 by sjo               #+#    #+#             */
/*   Updated: 2022/01/24 17:20:04 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char_num(const char **str, va_list ap)
{
    int i;
    
    while (*str)
    {
        if ((char)**str == 'c')
        {
            i = va_arg(ap, int);
            write(1, &i, 1);
            return (1);
        }
        else if ((char)**str == 's')
            return (ft_printf_s(str, ap));
        else if ((char)**str == 'x' || (char)**str == 'X' || (char)**str == 'p')
            return (ft_printf_hex(str, ap));
        else if ((char)**str == 'd' || (char)**str == 'i')
            return (ft_printf_diu(str, ap));
        else
            return (ft_printf_percent(str));
    }
    return (0);
}

int ft_printf(const char *str, ...) 
{
    va_list ap;
    int     len;

    va_start(ap, str);
    len = ft_strlen(str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            len += ft_print_char_num(&str, ap) - 2;
        }
        else
        {
            write(1, str, 1);
            str++;
        }
    }
    va_end(ap);
    return (len);
}