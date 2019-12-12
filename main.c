/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:45:52 by panderss          #+#    #+#             */
/*   Updated: 2019/12/12 13:06:59 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		ret;
	int		fd;
	char	*line;
	int		file;
	int		l_nbr;

	l_nbr = 0;
	ret = 1;
	if (argc == 1)
	{
		fd = 0; /*read from stdin*/
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			++l_nbr;
			ft_putstr("Line ");
			ft_putnbr(l_nbr);
			ft_putstr(" from stdin: ");
			ft_putstr(line);
			ft_putchar('\n');
			if (line != NULL)
				free(line);
		}
		if (ret < 0)
			ft_putendl("Error! Something went wrong; either the file did not open correctly, or it does not exist, or read failed. Check file name and directory.");
	}
	else if (argc > 1)
	{
		file = 1;
		while (file < argc)
		{
			l_nbr = 0;
			if (!(fd = open(argv[file], O_RDONLY)))
			{
				ft_putendl("An error occurred in the open.");
				return (-1);
			}
			while ((ret = get_next_line(fd, &line)) == 1)
			{
			++l_nbr;
			ft_putstr("Line ");
			ft_putnbr(l_nbr);
			ft_putstr(" from file ");
			ft_putnbr(file);
			ft_putstr(":");
			ft_putstr(line);
			ft_putchar('\n');
			if (line != NULL)
				free(line);
			}
			++file;
		}
		if (ret < 0)
			ft_putendl("Error! Something went wrong; either the file did not open correctly, or it does not exist, or read failed. Check file name and directory.");
	}
//	ft_putstr("END OF THE LINE(s).");
	return (0);
}
