#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int result;

    if (format == NULL)
        return (-1);
    va_start(ap, format);
    result = ft_parse_format(ap, format);
    return (result);
}