/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalpha.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 17:35:23 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 17:35:23 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int isalpha;
	int islower;
	int isupper;

	islower = (c >= 'a' && c <= 'z');
	isupper = (c >= 'A' && c <= 'Z');
	isalpha = (isupper || islower);
	return (isalpha);
}
