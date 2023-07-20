#include "variadic_functions.h"

/**
* print_all - prints numbers and strings everythings
* @format: typr of arguments arrays
*/
void print_all(const char * const format, ...)
{
int k = 0;
char *s, *separ = "";
va_list ptr;
va_start(ptr, format);
if (format)
{
while (format[k])
{
switch (format[k])
{
case 'c':
printf("%s%c", separ, va_arg(ptr, int));
break;
case 'i':
printf("%s%d", separ, va_arg(ptr, int));
break;
case 'f':
printf("%s%f", separ, va_arg(ptr, double));
break;
case 's':
s = va_arg(ptr, char *);
if (!s)
{
s = "(nil)";
}
printf("%s%s", separ, s);
break;
default:
k++;
continue;

}
separ = ", ";
k++;
}
}
printf("\n");
va_end(ptr);
}
