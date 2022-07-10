/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:02:15 by lchew             #+#    #+#             */
/*   Updated: 2022/07/10 20:09:19 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s != '\0' && *s != c)
		++s;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*d;

	// printf("src: [%s]\n", src);
	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*src != '\0')
		*d++ = *src++;
	*d = '\0';
	// printf("d: [%s]\n", d);
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		++i;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize < (dlen + 1))
		return (slen + dstsize);
	dstsize -= dlen + 1;
	dst += dlen;
	if (dstsize >= slen)
		dstsize = slen;
	while (dstsize != 0)
	{
		*dst++ = *(unsigned char *)src++;
		--dstsize;
	}
	dst[dstsize] = '\0';
	return (slen + dlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = malloc(1);
		*sub = '\0';
		return (sub);
	}
	s += start;
	i = ft_strlen(s);
	if (i < len)
		len = i;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	*sub = '\0';
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*array;
	size_t			len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	array = malloc(len * sizeof(char));
	if (!array)
		return (NULL);
	*array = '\0';
	ft_strlcpy(array, s1, len);
	ft_strlcat(array, s2, len);
	return (array);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	d = dst;
	if (d > (unsigned char *)src)
	{
		d += len - 1;
		src += len - 1;
		while (len-- != 0)
			*(unsigned char *)d-- = *(unsigned char *)src--;
	}
	else
	{
		while (len-- != 0)
			*(unsigned char *)d++ = *(unsigned char *)src++;
	}
	return (dst);
}
