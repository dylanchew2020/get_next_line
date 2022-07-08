/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/08 16:12:28 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	int			i;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	buffer[32700];
	int			find_nl;
	int			count;

	res = NULL;
	find_nl = 0;
	count = 0;
	nbyte = 1;
	if (fd < 0)
		return (res = NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	printf("debug 1: txt = \"%s\", txtp = %p, nbyte = %i\n\n", txtread, txtread, nbyte);
	// if (nbyte == 0 && *txtread == '\0')
	// 	return (res);
	if (nbyte == 0 && *buffer == '\0')
		return (res);
	while (find_nl != 1 && nbyte != 0)
	{
		txtread[BUFFER_SIZE] = '\0';
		if (*buffer == '\0')
			ft_strlcpy(buffer, txtread, BUFFER_SIZE + 1);
		else
			ft_strlcat(buffer, txtread, BUFFER_SIZE + 1);
		i = 0;
		while (txtread[i] != '\0' && txtread[i] != '\n' && i < nbyte)
			++i;
		find_nl = (txtread[i] == '\n');
		nbyte = read(fd, txtread, BUFFER_SIZE);
	}
	if (nbyte != 0)
		ft_strlcat(buffer, txtread, BUFFER_SIZE + 1);
	if (*buffer == '\0')
		return (res);
	while (buffer[count] != '\n' && buffer[count] != '\0')
		++count;
	// printf("debug 5: buffer = \"%s\", bufferp = %p\n\n", buffer, buffer);
	// printf("%i\n\n", count);
	res = ft_substr(buffer, 0, (count));
	ft_memmove(buffer, buffer + count + 1, ft_strlen(buffer) - count + 1);
	// buffer += (count + 1);
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
