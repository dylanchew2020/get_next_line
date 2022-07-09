/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/09 22:09:26 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (str || *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*res;
	int			i;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	*buffer;
	int			find_nl;
	int			count;
	char		*tmp;

	res = NULL;
	find_nl = 0;
	count = 0;
	nbyte = 1;
	if (fd < 3 || fd > 999)
		return (NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	// printf("debug 1: txt = \"%s\", txtp = %p, nbyte = %i\n\n", txtread, txtread, nbyte);
	if (nbyte == -1)
		return (NULL);
	if (nbyte == 0 && buffer == NULL)
		return (NULL);
	while (find_nl != 1 && nbyte != 0)
	{
		txtread[nbyte] = '\0';
		if (buffer == NULL)
			buffer = ft_substr(txtread, 0, BUFFER_SIZE);
		else
		{
			tmp = ft_strjoin(buffer, txtread);
			free(buffer);
			buffer = tmp;
		}
		i = 0;
		while (txtread[i] != '\0' && txtread[i] != '\n' && i < nbyte)
			++i;
		find_nl = (txtread[i] == '\n');
		nbyte = read(fd, txtread, BUFFER_SIZE);
	}
	if (nbyte != 0)
	{
		tmp = ft_strjoin(buffer, txtread);
		free(buffer);
		buffer = tmp;
	}
	if (*buffer == '\0')
		return (res);
	while (buffer[count] != '\n' && buffer[count] != '\0')
		++count;
	// printf("debug 5: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("%i\n\n", count);
	res = ft_substr(buffer, 0, (count));
	tmp = ft_strdup(buffer + count + 1);
	free(buffer);
	buffer = tmp;
	// printf("debug 5: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("debug 6: res = \"%s\", resp = %p\n\n", res, res);
	return (res);
}
// txtread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// printf("debug 1: txt = \"%s\", txtp = %p, nbyte = %i\n\n", txtread, txtread, nbyte);
	// 	printf("debug 2: i = %i, find_nl = %i\n\n", i, find_nl);
	// 	printf("debug 3: txtread = \"%s\"\n\n", txtread);
	// 	printf("debug 4: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("debug 5: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("debug 6: res = \"%s\", resp = %p\n\n", res, res);
