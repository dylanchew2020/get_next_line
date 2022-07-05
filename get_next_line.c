/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/05 22:20:24 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	int			i;
	static char	*buffer;
	char		*tmp;
	int			find_nl;
	int			count;

	find_nl = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE));
	while (find_nl == 0)
	{
		i = 0;
		read(fd, tmp, BUFFER_SIZE);
		while (tmp[i] != '\n' && i < BUFFER_SIZE)
		{
			++i;
			++count;
		}
		find_nl = (*buffer == '\n');
		
	}
	return (res);
}
