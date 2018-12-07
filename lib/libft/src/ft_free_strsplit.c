#include "libft.h"

void ft_free_strsplit(char ***split)
{
	char	**tmp;

	tmp = *split;
	if (!split || !tmp)
		return ;
	while(*tmp)
	{
		ft_strdel(tmp);
		tmp++;
	}
	free(*tmp);
	free(*split);
	*split = NULL;
}
