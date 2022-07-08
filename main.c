/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:42 by lchew             #+#    #+#             */
/*   Updated: 2022/07/08 15:33:45 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	write_a_file()
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0755);
	write(fd, "1234567890\n", 11);
	write(fd, "This is a test file\n", 20);
	write(fd, "I am the second line\n", 21);
	write(fd, "Short\n", 6);
	write(fd, "LONGGGG1234567890!@#$^&*()<>?:\"{}|[]\\;\',./\n", 43);
	write(fd, "abcdefghijklmnopqrstuvwxyz\n", 27);
	write(fd, "Do not speedrun!!!!", 20);
	close(fd);
}

int	main(void)
{
	char	*buf;
	int		fd;
	
	fd = 0;
	if (open("test.txt", O_RDONLY) < 0)
	{
		write_a_file();
	}
	fd = open("test.txt", O_RDONLY);
	printf("file descriptor %i\n", fd);
	buf = get_next_line(fd);
	while (buf)
	{
		printf("Result : %s\n=====================\n", buf);
		free(buf);
		buf = get_next_line(fd);
	}	
	close(fd);
	return (0);
}
