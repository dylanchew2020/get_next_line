/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:42 by lchew             #+#    #+#             */
/*   Updated: 2022/07/05 21:43:06 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	write_a_file()
{
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0755);
	printf("file descriptor 1 %i\n", fd);
	write(fd, "This is a test file\n", 20);
	write(fd, "I am the second line\n", 21);
	write(fd, "Short\n", 6);
	write(fd, "LONGGGG1234567890!@#$^&*()<>?:\"{}|[]\\;\',./\n", 43);
	write(fd, "abcdefghijklmnopqrstuvwxyz", 26);
	close(fd);
}

int	main(void)
{
	char		*buf = malloc(21);
	int	fd = 0;

	if (open("test.txt", O_RDONLY) < 0)
	{
		write_a_file();
	}
	fd = open("test.txt", O_RDONLY);
	printf("file descriptor %i\n", fd);
	printf("%zi\n", read(fd, buf, 200));
	buf[201] = '\0';
	printf("%s\n", buf);
	close(fd);
	return (0);
}
