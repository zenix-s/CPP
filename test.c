#include <stdio.h>

int	max(int *tab, signed int len)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	if (len <= 0)
		return (max);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	main(void)
{
	int			tab[] = {2, 4, 98};
	signed int	len;
	int			max_num;

	len = 0;
	max_num = max(tab, len);
	printf("Maximo: %d", max_num);
	return (0);
}
