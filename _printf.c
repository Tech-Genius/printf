#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_str - custom function to print a string
 * @str: The string to print
 *
 * Return: number of characters printed
 */
int print_str(char *str)
{
    int printed_chars = 0;

    while (*str)
    {
        if (*str < ' ' || *str >= 127)
        {
            printed_chars += _putchar('\\');
            printed_chars += _putchar('x');
            printed_chars += _putchar(*str / 16 + '0');
            printed_chars += _putchar(*str % 16 < 10 ? *str % 16 + '0' : *str % 16 - 10 + 'A');
        }
        else
        {
            printed_chars += _putchar(*str);
        }
        str++;
    }

    return printed_chars;
}

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'S')
            {
                str_arg = va_arg(args, char *);
                if (str_arg == NULL)
                    return -1;

                printed_chars += print_str(str_arg);
            }
            else
            {
                printed_chars += _putchar('%');
                printed_chars += _putchar(*format);
            }
        }
        else
        {
            printed_chars += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}







