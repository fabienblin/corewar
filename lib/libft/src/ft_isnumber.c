#include "libft.h"

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] != '+' && str[i] != '-')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
