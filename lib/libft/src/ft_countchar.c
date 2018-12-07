#include "libft.h"

int		ft_countchar(char *str, char c)
{
	int i;
	int compt;

	i = 0;
	compt = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			compt++;
		i++;
	}
	return (compt);
}
