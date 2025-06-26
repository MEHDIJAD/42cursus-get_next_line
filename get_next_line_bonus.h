/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:04 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/03 10:19:42 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_read_join(char **str_buff, int fd);
char	*ft_get_line(char **str_buf, int fd);
int		ft_len_to_newline(char *str_buf);
int		ft_found_newline(char *str_buf);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_filljoin(char *tofill, const char *s1, const char *s2);
char	*ft_strjoined(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif
