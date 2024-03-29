/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:14:14 by lchew             #+#    #+#             */
/*   Updated: 2022/07/11 22:34:26 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_find_nl(char *buffer, int nbyte, char *txtread, int fd);
static char	*gnl_join(char *buffer, char *txtread);
static char	*gnl_write(char *buffer, char **res);

char	*get_next_line(int fd)
{
	char		*res;
	char		txtread[BUFFER_SIZE + 1];
	int			nbyte;
	static char	*buffer;

	if (fd < 0 || fd > 1024)
		return (NULL);
	nbyte = read(fd, txtread, BUFFER_SIZE);
	if (nbyte == -1)
		return (NULL);
	if (nbyte == 0 && buffer == NULL)
		return (NULL);
	buffer = gnl_find_nl(buffer, nbyte, txtread, fd);
	if (nbyte != 0)
		buffer = gnl_join(buffer, txtread);
	if (*buffer == '\0' || buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	buffer = gnl_write(buffer, &res);
	return (res);
}

static char	*gnl_find_nl(char *buffer, int nbyte, char *txtread, int fd)
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

static char	*gnl_join(char *buffer, char *txtread)
{
	char		*tmp;

	tmp = ft_strjoin(buffer, txtread);
	free(buffer);
	return (tmp);
}

static char	*gnl_write(char *buffer, char **res)
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
