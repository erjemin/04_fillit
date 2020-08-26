/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:06:23 by mretha            #+#    #+#             */
/*   Updated: 2019/06/20 19:34:13 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**   tet_check_place -- proveryaet vozmozhnost' razmeshheniya tetrimo s nomerom
**   current_tet (int current_tet) v koordinate y:x (int y, int x) na pole.
**   Vozvrashhaet 1 -- esli tetrimo mozhno razmetit', i 0 -- esli nel'zya.
**
**   tet_check_place — сhecks whether the tetrimo with the number current_tet
**   (int current_tet) is in the y:x coordinate (int y, int x) on the map.
**   Returns 1 -- if tetrimo can be tagged, and 0 -- if not.
*/

inline int		tet_check_place(t_point *tetblock, int y, int x)
{
	int		i;

	i = -1;
	while (++i < LEN_TET)
		if (g_map[y + tetblock[i].y][x + tetblock[i].x])
			return (0);
	return (1);
}

/*
**   tet_put_on_map -- razmeshhaet na pole tetrimo s nomerom current_tet
**   (int current_tet), nachinaya s koodinaty' y:x (int y, int x).
**
**   tet_put_on_map -- рlaces the tetrimo current_tet (int current_tet) on the
**   map, starting with the coordinate y:x (int y, int x).
*/

inline void		tet_put_on_map(t_point *tetblock, int y, int x, char c)
{
	int	i;

	i = -1;
	while (++i < LEN_TET)
		g_map[y + tetblock[i].y][x + tetblock[i].x] = c;
}

/*
**   tet_place -- "prilazhivanie" (razmeshhaet) tetrimo s nomerom current_tet
**   (int current_tet) na pole s razmernostbyu size (int size). Testiruyutsya
**   vse kletki y:x polya. Esli v kakoj-libo pozicii proverka na vozmozhnost'
**   razmesheniya (tet_check_place) uspeshna, tetrimo razmeshhaetsya
**   (tet_put_on_map) i rekursivno perexodim k razmeshheniyu sleduyushhego
**   tetrimo -- tet_place(curent_tet + 1, size). Vy'xod iz rekursii pri
**   dostizhenii poslednego tetrimo (curent_tet == g_num_tet). Esli vse
**   tetrimo udalos' razmestit' na  pole -- vozvrashhet 1, inache -- 0,
**   pri e'tom vse rekursivno razmeshhenny'e tetrimo budut udaleny' s
**   polya (tet_erase_on_map).
**
**   tet_place -- fitting (places) tetrimo with number current_tet
**   (int current_tet) on the map with dimension size (int size).
**   All cells y:x fields are tested. If the check on the possibility of
**   placing (tet_check_place) is successful in any position, the tetrimo
**   is placed (tet_put_on_map) and recursively proceed to the placement of
**   the next tetrimo -- tet_place (curent_tet + 1, size). Exit recursion
**   when the last tetrimo is reached (curent_tet == g_num_tet). If all the
**   Tetrimo were able to be placed on the field -- returns 1, otherwise -- 0,
**   while all recursively placed Tetrimo will be removed from the
**   map (tet_erase_on_map).
*/

inline int		tet_place(int curent_tet, int size)
{
	int		y;
	int		x;
	int		beginx;
	t_point	*p;
	char 	c;

	y = g_dimtet[curent_tet].tetcfg->h - 1;
	beginx = g_dimtet[curent_tet].tetcfg->w - 1;
	p = g_dimtet[curent_tet].tetcfg->tetblock;
	c = (char)(curent_tet + 'A');
	while (++y < size)
	{
		x = beginx;
		while (++x < size)
			if (tet_check_place(p, y, x))
			{
				tet_put_on_map(p, y, x, c);
				if (curent_tet == g_num_tet || tet_place(curent_tet + 1, size))
					return (1);
				tet_put_on_map(p, y, x, '\0');
			}
	}
	return (0);
}

/*
**   tet_solve -- opredelyaet startovy'j i predel'ny'j razmer polya, i
**   zapuskaet razmeshhenie terimo. Esli razmeshhenie na pole takogo razmera
**   ne udalos' -- ochishhaet pole, uvelichivaet razmer polya i zapuskaet
**   razmeshhenie zanovo. Kogda razmeshhenie udalos' -- vozvrashhaet razmer
**   poluchennogo polya.
**
**   tet_solve -- defines the starting and limit size of the map, and starts
**   the placement of the terimo. If placement on a map of this size fails
**   -- clears the map, increases the size of the map and restarts
**   placement. When placement succeeds, returns the size of the map
**   received.
*/

int				tet_solve(void)
{
	int		size;

	size = ft_sqrt_ge((g_num_tet + 1) * LEN_TET) - 1;
	while (++size <= g_size_max_map)
		if (!(tet_place(0, size)))
			tet_clear_map();
		else
			return (size);
	return (0);
}
