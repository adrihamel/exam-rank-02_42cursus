#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
int ft_numlen(long int n, int lenbase)
{
	int i;
	i = 1;
	while (n >= lenbase)
	{
		 n = n/lenbase;
		 i++;
	}
	return (i);
}

void ft_putnum(long int n, int lenbase, char *base)
{
	if (n>= lenbase)
		ft_putnum(n/lenbase, lenbase, base);
	write(1, &base[n % lenbase], 1);
}

int ft_printf(char *format, ...)
{
	int writed;
	int zero;
	int pad;
	char *base;
	int lenbase;
	va_list args;
	int prec;
	int width;
	int neg;
	int digits;
	int dot;
	char *s;
	long int num;
	va_start(args, format);
	writed = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			writed++;
		}
		else
		{
			format++;
			width = 0;
			prec = 0;
			dot = 0;
			neg = 0;
			pad = 0;
			zero = 0;
			digits = 0;
			while (*format >= '0' && *format <= '9')
				width = width * 10 + (*format++ - '0');
			if (*format == '.')
			{
				dot = 1;
				format++;
				while (*format >= '0' && *format <= '9')
					prec = prec *10 + (*format++ - '0');
			}
			if (*format == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				digits = ft_strlen(s);
			}
			if (*format == 'd')
			{
				num = va_arg(args, int);
				if (num < 0)
				{
					num = -num;
					neg = 1;
				}
				base= "0123456789";
				lenbase = 10;
				digits = ft_numlen(num, lenbase) + neg;
			}
			if (*format == 'x')
			{
				num = va_arg(args, unsigned);
				base = "0123456789abcdef";
				lenbase = 16;
				digits = ft_numlen(num, lenbase);
			}
			if (*format == 's' && dot == 1 && prec < digits)
				digits = prec;
			else if (*format != 's' && dot == 1 && prec > digits)
				zero = prec + neg -digits;
			else if (dot == 1 && prec == 0 && num == 0)
				digits = 0;
			pad = width - digits -zero;
			while (pad > 0)
			{
				write(1, " ", 1);
				writed++;
				pad--;
			}
			if (neg == 1)
				write(1, "-", 1);
			while (zero > 0)
			{
				write(1, "0", 1);
				writed++;
				zero--;
			}
			if (*format == 's')
				write(1, s, digits);
			else if (digits > 0)
				ft_putnum(num, lenbase, base);
			writed += digits;
			format++;
		}
	}
	return (writed);
}
/*
int main()
{
	char a[] = "hola";
	char *b;
	int i = 0;
	int j = -234423;
	printf("%i\n", ft_printf("hello |%3.s| %1.0d %d \n", a, i, j));
	printf("%i\n", printf("hello |%3.s| %1.0d %d \n", a, i, j));
	printf("%i\n", ft_printf("hello |%3.s| %1.0d %30.10d \n", b, i, j));
	printf("%i\n", printf("hello |%3.s| %1.0d %30.10d \n", b, i, j));
	return (0);
}
*/
