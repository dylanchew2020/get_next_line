/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/08 16:14:03 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	int			i;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	*buffer;
	int			find_nl;
	int			count;

	res = NULL;
	find_nl = 0;
	count = 0;
	nbyte = 1;
	if (fd < 0)
		return (res = NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	// printf("debug 1: txt = \"%s\", txtp = %p, nbyte = %i\n\n", txtread, txtread, nbyte);
	// if (nbyte == 0 && *txtread == '\0')
	// 	return (res);
	if (nbyte == 0 && buffer && *buffer == '\0')
		return (res);
	while (find_nl != 1 && nbyte != 0)
	{
		txtread[BUFFER_SIZE] = '\0';
		if (buffer == NULL)
			buffer = ft_substr(txtread, 0, BUFFER_SIZE);
		else
			buffer = ft_strjoin(buffer, txtread);
		i = 0;
		while (txtread[i] != '\0' && txtread[i] != '\n' && i < nbyte)
			++i;
		find_nl = (txtread[i] == '\n');
		nbyte = read(fd, txtread, BUFFER_SIZE);
	}
	if (nbyte != 0)
		buffer = ft_strjoin(buffer, txtread);
	if (*buffer == '\0')
		return (res);
	while (buffer[count] != '\n' && buffer[count] != '\0')
		++count;
	// printf("debug 5: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("%i\n\n", count);
	res = ft_substr(buffer, 0, (count));
	buffer += (count + 1);
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
