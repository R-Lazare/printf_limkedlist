#include "ft_printf.h"
#include <stdio.h>

#include "ft_printf.h"

int main(void)
{
    int a = -42;
    unsigned int b = 42;
    char *str = "Hello, world!";
    char c = 'c';
    void *p = &a;
    ft_printf("Printing an integer (%d), an unsigned integer (%u), a string (%s), a char (%c), a pointer (%p), a lowercase hexadecimal (%x), an uppercase hexadecimal (%X), and a percentage symbol (%%) all in one go!", a, b, str, c, p, b, b);
    return 0;
}
