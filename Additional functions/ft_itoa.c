static int	ft_sign(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int sign = ft_sign(nbr);
	int len = ft_len(nbr);
	char *dest;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);

	dest[len] = '\0';

	if (nbr == 0)
	{
		dest[0] = '0';
		return (dest);
	}

	if (nbr < 0)
	{
		dest[0] = '-';
	}

	while (nbr)
	{
		len--;
		dest[len] = '0' + (sign * (nbr % 10));
		nbr /= 10;
	}

	return (dest);
}