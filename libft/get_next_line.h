/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:20:07 by ameta             #+#    #+#             */
/*   Updated: 2021/01/21 00:17:05 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
int		ft_strchrn(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_retline(char **line, char **remaining, int npos);
char	*ft_substr(char *s, unsigned int start, int len);
int		ft_strlen(const char *s);
int		ft_fillrem(char **remaining, int ret, char **buf);

#endif
