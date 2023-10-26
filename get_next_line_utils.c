/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:31:20 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/26 19:00:59 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	memsize;
	char	*alloc;
	size_t	i;
	size_t	n;

	if ((nmemb * size != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	memsize = nmemb * size;
	alloc = (void *)malloc(memsize);
	if (!alloc)
		return (NULL);
	n = nmemb;
	i = 0;
	while (n-- > 0)
		alloc[i++] = '\0';
	return (alloc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	if (!s1 && !s2)
		return (NULL);
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != '\0')
		s3[l++] = s1[i++];
	while (s2 && s2[j] != '\0')
		s3[l++] = s2[j++];
	free((char *)s1);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pi;

	i = 0;
	if (c > 127)
		c = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			pi = (char *)&s[i];
			return (pi);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	*return_null(void	*del)
{
	if (del)
		free (del);
	del = NULL;
	return (NULL);
}
