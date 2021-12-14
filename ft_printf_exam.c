#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_pow(int nb, int pow) //maybe unsigned ?
{
	int	res;
	
	res = nb;
	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (nb);
	else
	{
		while (pow > 1)
		{
			res *= nb;
			pow--;
		}
	}
	return (res);
}

int	print_x(int nb)
{
	long int	tmp;
	long int	nbr;
	int	len;
	int	ret;
	int	i;

	tmp = nb;
	nbr = 0;
	len = 0;
	i = 1;
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	ret = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	while (i <= len)
	{
		nbr = tmp / ft_pow(16, len - i) % 16;
		if (nbr <= 9)
		{
			nbr += 48;
			write (1, &nbr, 1);
		}
		else if (nbr == 10)
			write (1, "a", 1);
		else if (nbr == 11)
			write (1, "b", 1);
		else if (nbr == 12)
			write (1, "c", 1);
		else if (nbr == 13)
			write (1, "d", 1);
		else if (nbr == 14)
			write (1, "e", 1);
		else if (nbr == 15)
			write (1, "f", 1);
		ret++;
		i++;
	}
	return (ret);
}

int	print_d(int nb)
{
	long int	tmp;
	long int	nbr;
	int	len;
	int	ret;
	int	i;

	tmp = nb;
	nbr = 0;
	len = 0;
	i = 1;
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else if (tmp < 0)
	{
		write (1, "-", 1);
		tmp *= -1;
		ret = 1;
	}
	else
		ret = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	while (i <= len)
	{
		nbr = tmp / ft_pow(10, len - i) % 10 + 48;
		write (1, &nbr, 1);
		ret++;
		i++;
	}
	return (ret);
}

int	print_s(char *txt)
{
	int	i;

	i = 0;
	if (txt == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (txt[i])
	{
		write(1, &txt[i], 1);
		i++;	
	}
	printf("%d\n", i);
	return (i);
}

int	ft_printf(const char *txt, ...)
{
	va_list	ap;
	int	i;
	int	ret;

	va_start(ap,txt);
	i = 0;
	ret = 0;
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			i++;
			if (txt[i] == 'd')
				ret += print_d(va_arg(ap, int));
			else if (txt[i] == 's')
				ret += print_s(va_arg(ap, char *));
			else if (txt[i] == 'x')
				ret += print_x(va_arg(ap, int)); // maybe unsigned ?
		}
		else
		{
			write (1, &txt[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}

int	main()
{
	int	d;
	d = ft_printf("test 42 = %d, %s, %x\n", 42, "bla", 42);// bug quand %s\n ?
	printf("\n%d\n", d);
	d = printf("test 42 = %d, %s, %x\n", 42, "bla", 42);
	printf("\n%d\n", d);
}
