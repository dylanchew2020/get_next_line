/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:02:15 by lchew             #+#    #+#             */
/*   Updated: 2022/07/05 17:44:07 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
The ft_strlen() function computes the length of the string s.

The ft_strlen() function returns the number of characters that precede the 
terminating NUL character.
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

/*
The ft_strdup() function returns a pointer to a new string a of which is 
a duplicate of the string s.

The ft_strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available
*/
/* char	*ft_strdup(const char *src)
{
	char	*dup;
	char	*d;

	dup = ft_malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	d = dup;
	while (*src != '\0')
		*d++ = *src++;
	*d = '\0';
	return (dup);
} */

/*
**	The ft_strlcpy() copy strings by taking the full size of the destination 
**	buffer and guarantee NUL-termination if there is room.  Note that room for 
**	the NULL should be included in dstsize.
**
**	ft_strlcpy() copies up to dstsize - 1 characters from the string src to dst,
**	NUL-terminating the result if dstsize is not 0. If the src and dst strings
**	overlap, the behavior is undefined.
**
**	Return the total length of the string they tried to create, that means the
**	length of src. If the return value is >= dstsize, the output string has been
**	truncated.
*/

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
		i++;
	return (i);
}

/*
**	The ft_strlcat() appends string src to the end of dst up to 
**	(dstsize - strlen(dst) - 1) characters.It takes the full size 
**	of the buffer, not only the length, and terminates the result 
**	with NUL as long as is greater than 0.
**
**	The ft_strlcat() function returns the total length of the string that 
**	would have been created if there was unlimited space. This might or 
**	might not be equal to the length of the string actually created, 
**	depending on whether there was enough space. This means that you can 
**	call ft_strlcat() once to find out how much space is required, then 
**	allocate it if you do not have enough, and finally call ft_strlcat() 
**	a second time to create the required string.
*/
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
	while (dstsize-- != 0)
		*dst++ = *(unsigned char *)src++;
	dst[dstsize] = '\0';
	return (slen + dlen);
}

/*
Allocates with ft_calloc and returns a substring from the string 's'.
The substring begins at index 'start' and is of maximum size 'len'.

The ft_substr() returns the pointer to the index 'start' of the substring.
Returns NULL if the allocation fails.
*/
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
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}

/*
Allocates with ft_calloc and returns a new string, which is the result
of the concatenation of 's1' and 's2'.

The ft_strjoin() returns the pointer to the new string.
Returns NULL if the allocation fails.
*/
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
	ft_strlcpy(array, s1, len);
	ft_strlcat(array, s2, len);
	return (array);
}
