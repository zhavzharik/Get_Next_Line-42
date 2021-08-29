/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:25:36 by abridger          #+#    #+#             */
/*   Updated: 2021/06/06 16:29:34 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, char const *src);
char	*check_rest(char *rest, char **line);
int		check_lesen(int lesen, char **buf, char **line);
int		get_rest_and_line(char **n_point, char **buf, char **rest, char **line);
int		get_return(char **buf, int lesen, char **rest, char **line);
int		get_next_line(int fd, char **line);

#endif
