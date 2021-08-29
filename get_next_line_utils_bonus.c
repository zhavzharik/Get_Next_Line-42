/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:23:02 by abridger          #+#    #+#             */
/*   Updated: 2021/06/06 16:15:19 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (str)
	{
		while (i < len)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
	if (!str)
		return (NULL);
}

char	*ft_strcpy(char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	size_t			len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len_s1 + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (str)
	{
		str = ft_strcpy(str, s1);
		while (i < ft_strlen(s2))
		{
			str[len_s1] = s2[i];
			i++;
			len_s1++;
		}
		str[len_s1] = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}
