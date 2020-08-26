/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:37:27 by mretha            #+#    #+#             */
/*   Updated: 2019/05/15 22:37:24 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 26

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_buff
{
	int			ndx_fd;
	size_t		cursor;
	char		*buf;
	size_t		len;
}				t_buff;

int				get_next_line(int fd, char **line);
t_buff			*ft_buff_get(const int fd);
t_buff			*ft_buff_expand(t_buff **address_buffs, int fd);
t_buff			*ft_buff_find(t_buff *tb, int fd);
t_buff			ft_buff_new(int fd);

#endif
