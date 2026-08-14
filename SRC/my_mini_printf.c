/*
** EPITECH PROJECT, 2026
** my_va_args_test.c
** File description:
** test
*/

#include <stdarg.h>
#include <unistd.h>

static int my_putstr(char const *str)
{
    int i = 0;
    int bytes = 0;

    while (str[i] != '\0') {
        bytes += write(1, &str[i], 1);
        i++;
    }
    return bytes;
}

static int my_putchar(char c)
{
    return write(1, &c, 1);
}

static int my_put_nbr(int nb)
{
    int d;
    int bytes = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    d = nb % 10 + '0';
    bytes += my_putchar(d);
    return bytes;
}

static int print_arg(char format, va_list ap)
{
    int bytes = 0;

    if (format == 'c') {
        bytes += my_putchar(va_arg(ap, int));
    }
    if (format == 'd') {
        bytes += my_put_nbr(va_arg(ap, int));
    }
    if (format == 's') {
        bytes += my_putstr(va_arg(ap, char *));
    }
    if (format == '%') {
        bytes += my_putchar('%');
    }
    if (format == 'i') {
        bytes += my_put_nbr(va_arg(ap, int));
    }
    return bytes;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int bytes = 0;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            bytes += print_arg(format[i + 1], ap);
            i++;
        } else {
            bytes += write(1, &format[i], 1);
        }
        i++;
    }
    return bytes;
}
