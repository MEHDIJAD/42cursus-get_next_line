/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:21:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/06/27 20:11:00 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_found_newline(char *str_buf)
{
	int	i;

	if (!str_buf)
		return (0);
	i = 0;
	while (str_buf[i])
	{
		if (str_buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_to_newline(char *str_buf)
{
	int	len;

	if (!str_buf)
		return (0);
	len = 0;
	while (str_buf[len] && str_buf[len] != '\n')
		len++;
	if (str_buf[len] == '\n')
		len++;
	return (len);
}

char	*ft_get_line(char **str_buf)
{
	int		len;
	char	*line;

	if (!*str_buf)
		return (NULL);
	len = ft_len_to_newline(*str_buf);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *str_buf, len + 1);
	return (line);
}

char	*read_and_add(char **str_buff, int fd)
{
	int		bytes_read;
	char	*buf;
	char	*temp;

	while (!ft_found_newline (*str_buff))
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (free(*str_buff), *str_buff = NULL, NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(*str_buff), *str_buff = NULL, free(buf), NULL);
		buf[bytes_read] = '\0';
		temp = ft_strjoined(*str_buff, buf);
		if (!temp)
			return (free(*str_buff), *str_buff = NULL, free(buf), NULL);
		free(*str_buff);
		*str_buff = temp;
		free(buf);
		if (bytes_read == 0)
			break ;
	}
	return (*str_buff);
}

char	*get_next_line(int fd)
{
	static char	*str_buf;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_buf = read_and_add(&str_buf, fd);
	if (!str_buf || !*str_buf)
		return (free(str_buf), str_buf = NULL, NULL);
	line = ft_get_line(&str_buf);
	if (!line)
		return (free(str_buf), str_buf = NULL, NULL);
	temp = ft_strdup(str_buf + ft_len_to_newline(str_buf));
	if (!temp)
		return (free(str_buf), free(line), str_buf = NULL, NULL);
	free(str_buf);
	str_buf = temp;
	return (line);
}
