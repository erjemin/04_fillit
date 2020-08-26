/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_read_check_covert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:03:23 by mretha            #+#    #+#             */
/*   Updated: 2019/06/20 19:42:45 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimo		*ft_tetmake(t_tetcfg *ttr)
{
	t_tetrimo	*tet;

	if ((tet = (t_tetrimo *)malloc(sizeof(t_tetrimo))))
		tet->tetcfg = ttr;
	return (tet);
}

t_tetrimo		*ft_tetget2(char **dtet, t_point first_block)
{
	static t_tetcfg		tet[DIF_TET] = {TTR_I1, TTR_I2, TTR_O, TTR_L1, \
		TTR_L2, TTR_L3, TTR_L4, TTR_J1, TTR_J2, TTR_J3, TTR_J4, TTR_T1, \
		TTR_T2, TTR_T3, TTR_T4, TTR_Z1, TTR_Z2, TTR_S1, TTR_S2};
	int					itet;
	int					iblc;
	int					x;
	int					y;

	itet = -1;
	while (++itet < DIF_TET && (iblc = -1) == -1)
	{
		while (++iblc < LEN_TET)
		{
			y = first_block.y + tet[itet].tetblock[iblc].y + tet[itet].h;
			x = first_block.x + tet[itet].tetblock[iblc].x + tet[itet].offsetx;
			if (x >= LEN_TET || x < 0 || y >= LEN_TET || dtet[y][x] != BLOCK)
				break ;
		}
		if (iblc == LEN_TET)
			return (ft_tetmake(&(tet[itet])));
	}
	return (NULL);
}

t_tetrimo		*ft_tetget1(char **dtet)
{
	int			col;
	int			row;
	int			num_tet_point;
	t_point		first_block;

	row = -1;
	num_tet_point = 0;
	while (++row < LEN_TET && (col = -1) == -1)
		while (++col < LEN_TET)
			if (dtet[row][col] == BLOCK)
				if (num_tet_point++ == 0)
				{
					first_block.x = col;
					first_block.y = row;
				}
				else
					continue;
			else if (dtet[row][col] != SPACE)
				return (NULL);
	if (num_tet_point != LEN_TET)
		return (NULL);
	return (ft_tetget2(dtet, first_block));
}

int				tet_read(int fd)
{
	char		*drow[LEN_TET];
	int			r;
	int			err_code;
	t_tetrimo	*tet;

	g_num_tet = -1;
	err_code = 1;
	while (++g_num_tet < MAXTOTAL_TET && err_code == 1 && (r = -1) == -1)
	{
		while (++r < LEN_TET)
			if (get_next_line(fd, &(drow[r])) <= 0 || ft_strlen(drow[r]) != 4)
				return (0);
		if (!(tet = ft_tetget1(drow)))
			return (0);
		g_dimtet[g_num_tet] = *tet;
		free(tet);
		if ((err_code = get_next_line(fd, &(drow[r]))) != 0 && drow[r][0] != 0)
			return (0);
		r = 0;
		while (r < LEN_TET + 1)
			ft_strdel(&(drow[r++]));
	}
	return (1 + g_num_tet--);
}
