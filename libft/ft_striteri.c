/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:28:13 by panderss          #+#    #+#             */
/*   Updated: 2019/11/06 14:40:06 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	if (str != NULL && f != NULL)
	{
		while (str[index] != '\0')
		{
			f(index, &str[index]);
			index++;
		}
	}
}
