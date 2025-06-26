/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:17 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/05 11:48:21 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *buf)
{
	size_t	len;

	len = 0;
	while (buf[len])
	{
		len++;
	}
	return (len);
}

char	*ft_filljoin(char *tofill, const char *str_buf, const char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_buf[i])
	{
		tofill[i] = str_buf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		tofill[i] = buf[j];
		i++;
		j++;
	}
	tofill[i] = '\0';
	return (tofill);
}

char	*ft_strjoined(char const *str_buff, char const *buf)
{
	char	*strjn;
	size_t	len;

	if (!str_buff && !buf)
		return (NULL);
	if (!str_buff)
		return (ft_strdup(buf));
	if (!buf)
		return (ft_strdup(str_buff));
	len = ft_strlen(str_buff) + ft_strlen(buf);
	strjn = malloc((len + 1) * sizeof(char));
	if (!strjn)
		return (NULL);
	strjn = ft_filljoin(strjn, str_buff, buf);
	if (!strjn)
		return (NULL);
	return (strjn);
}

char	*ft_strdup(const char *buff)
{
	size_t	size;
	char	*cpy;
	int		i;

	size = ft_strlen(buff);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		cpy[i] = buff[i];
		i++;
	}
	cpy[size] = '\0';
	return (cpy);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t			len;
	size_t			i;

	len = ft_strlen(src);
	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
