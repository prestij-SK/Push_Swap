/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skedikia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:41:37 by skedikia          #+#    #+#             */
/*   Updated: 2024/02/02 09:42:42 by skedikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*get_next_line(int fd);
char	*strjoin_to_left(char *s1, const char *s2);
size_t	strlen_alt(const char *str, const char alt);
int		str_has_character(const char *str, const char c);
void	strcpy_alt(char *dest, const char *src, size_t *i);

#endif
