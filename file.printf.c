#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                // Print a character
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            } else if (*format == 's') {
                // Print a string
                char *str = va_arg(args, char *);
                while (*str) {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                // Print '%'
                write(1, "%", 1);
                count++;
            }
        } else {
            // Print normal characters
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

