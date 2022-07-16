/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/16 11:18:38 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_find_nl(char *buffer, int nbyte, char *txtread, int fd);
char	*gnl_join(char *buffer, char *txtread);
char	*gnl_write(char *buffer, char **res);

char	*get_next_line(int fd)
{
	char		*res;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	*buffer[1024];

	if (fd < 0 || fd > 1024)
		return (NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	if (nbyte == -1)
		return (NULL);
	if (nbyte == 0 && buffer[fd] == NULL)
		return (NULL);
	buffer[fd] = gnl_find_nl(buffer[fd], nbyte, txtread, fd);
	if (nbyte != 0)
		buffer[fd] = gnl_join(buffer[fd], txtread);
	if (*(buffer[fd]) == '\0' || buffer[fd] == NULL)
	{
		free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = gnl_write(buffer[fd], &res);
	return (res);
}

char	*gnl_find_nl(char *buffer, int nbyte, char *txtread, int fd)
{
	int	find_nl;
	int	i;

	find_nl = 0;
	while (find_nl != 1 && nbyte != 0)
	{
		txtread[nbyte] = '\0';
		if (buffer == NULL)
			buffer = ft_substr(txtread, 0, BUFFER_SIZE);
		else
			buffer = gnl_join(buffer, txtread);
		i = 0;
		while (txtread[i] != '\0' && txtread[i] != '\n' && i < nbyte)
			++i;
		find_nl = (txtread[i] == '\n');
		if (txtread[nbyte - 1] != '\n')
			nbyte = read(fd, txtread, BUFFER_SIZE);
		else
			nbyte = 0;
	}
	txtread[nbyte] = '\0';
	return (buffer);
}

char	*gnl_join(char *buffer, char *txtread)
{
	char		*tmp;

	tmp = ft_strjoin(buffer, txtread);
	free(buffer);
	return (tmp);
}

char	*gnl_write(char *buffer, char **res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		++i;
	if (buffer[i] == '\n')
		++i;
	*res = ft_substr(buffer, 0, i);
	tmp = ft_strdup(buffer + i);
	free(buffer);
	return (tmp);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*d;

	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*src != '\0')
		*d++ = *src++;
	*d = '\0';
	return (dup);
}
