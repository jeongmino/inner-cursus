/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:25:50 by junoh             #+#    #+#             */
/*   Updated: 2022/08/31 01:40:16 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);    
}

int     isspace(char c)
{
    if ((c >= '\t' && c <= '\r') || c == ' ')
        return (1);
    return (0);
}

int     check_base(char *base)
{
    char    *buf;
    char    *ptr;
    
    buf = base;
    while (*buf != '\0')
    {
        if (*buf == '-' || *buf == '+' || isspace(*buf))
            return (1);
        buf++;
    }
    ptr = base;
    while (*ptr != '\0')
    {
        buf = ptr;
        buf++;
        while (*buf != '\0')
        {
            if (*buf == *ptr)
                return (1);
            buf++;
        }
        ptr++;
    }
    return (0);   
}

int     squre(int a, int b)
{
    while (b > 1)
        a *= a;
    return (a);   
}

char    *ft_alloc(int num, char *base_to, int sign, int radix)
{
    int expo;
    int cnt;
    char    *ptr;
    
    cnt = 1;
    expo = 1;
    while (num > expo)
    {
        if (((num / expo) >= 1) || ((num / (expo * radix) == 0)))                
            break;
        expo * radix;
        cnt++;
    }
    if (sign == -1)
        cnt++;
    ptr = malloc(cnt * sizeof(char));
    if (ptr == NULL)
        return (NULL);
}

char    *ft_change_base(int num, int sign, char *base_to, char *result_str)
{
    int expo;   
    int radix;
    int index;
    int i;
    
    radix = ft_strlen(base_to);
    i = 0;
    if (sign == -1)
        result_str[i++] = '-';
    while (num > 0)
    {
        expo = 1;
        while (num > expo)
        {
            if (((num / expo) >= 1) || ((num / (expo * radix) == 0)))
                break;
            expo * radix;
        }
        index = num / expo;
        result_str[i++] = base_to[index];
        num = num - (index * expo);                      
    }
    return (result_str);    
}

char    *ft_int_to_base(int num, char *base_to, int sign)
{
    int radix;
    int expo;
    int index;
    char    *result_str;
    
    radix = ft_strlen(base_to);
    expo = 1;
    result_str = ft_alloc(num, base_to, sign, radix);
    if (result_str == NULL)
        return (NULL);
    result_str = ft_change_base(num, sign, base_to, result_str);
    return (result_str);
}

char    *ft_base_to_int(char *nbr, char *base_from, char *base_to, int sign)
{
    long    num;
    int     radix;
    int     i;
    int     nbr_len;
    char    *result_str;

    nbr_len = ft_strlen(nbr) - 1;
    radix = ft_strlen(base_from);
    num = 0;
    i = -1;
    while (nbr[++i] != '\0')
        num = squre(radix, nbr_len--) * (nbr[i] - '0');
    if ((sign == 1 && num > 2147483647) || (sign == -1 && num < 2147483648))
        return (NULL);
    result_str = ft_int_to_base(num, base_to, sign);   
    if (result_str == NULL)
        return (NULL);
    return (result_str);     
}

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int     sign;
    
    if (check_base(base_from) || check_base(base_to) || \
    ft_strlen(base_from == 1) || ft_strlen(base_to) == 1)
        return (NULL);
    sign = 1;
    while (*nbr == '-' || *nbr == '+')
        if (*nbr++ == '-')
            sign *= -1;
    return (ft_base_to_int(nbr, base_from, base_to, sign));
}