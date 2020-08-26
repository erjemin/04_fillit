/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:37:27 by mretha            #+#    #+#             */
/*   Updated: 2019/06/20 19:51:31 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

# define DIF_TET 19
# define LEN_TET 4
# define MAXTOTAL_TET 26
# define SPACE '.'
# define BLOCK '#'

typedef struct	s_point
{
	int short	x;
	int	short	y;
}				t_point;

typedef struct	s_tetcfg
{
	t_point		tetblock[LEN_TET];
	int			offsetx;
	int			w;
	int			h;
}				t_tetcfg;

typedef struct	s_tetrimo
{
	t_tetcfg	*tetcfg;
}				t_tetrimo;

/*
** .....I1.####.....I2.#...........
** ....................#...........
** ....................#...........
** ....................#...........
*/

# define TTR_I1 {{{-3, 0}, {-2, 0}, {-1, 0}, {0, 0}}, 3, 3, 0}
# define TTR_I2 {{{0, -3}, {0, -2}, {0, -1}, {0, 0}}, 0, 0, 3}

/*
** .....O.##.......................
** .......##.......................
*/

# define TTR_O {{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}, 1, 1, 1}

/*
** .....L1.#........L2.###......L3.##.......L4...#.........
** ........#...........#............#..........###.........
** ........##.......................#......................
*/

# define TTR_L1 {{{-1, -2}, {-1, -1}, {-1, 0}, {0, 0}}, 1, 1, 2}
# define TTR_L2 {{{-2, -1}, {-1, -1}, {0, -1}, {-2, 0}}, 2, 2, 1}
# define TTR_L3 {{{-1, -2}, {0, -2}, {0, -1}, {0, 0}}, 1, 1, 2}
# define TTR_L4 {{{0, -1}, {-2, 0}, {-1, 0}, {0, 0}}, 0, 2, 1}

/*
** .....J1..#.......J2.###......J3.##.......J4.#...........
** .........#............#.........#...........###.........
** ........##......................#.......................
*/

# define TTR_J1 {{{0, -2}, {0, -1}, {-1, 0}, {0, 0}}, 0, 1, 2}
# define TTR_J2 {{{-2, -1}, {-1, -1}, {0, -1}, {0, 0}}, 2, 2, 1}
# define TTR_J3 {{{-1, -2}, {0, -2}, {-1, -1}, {-1, 0}}, 1, 1, 2}
# define TTR_J4 {{{-2, -1}, {-2, 0}, {-1, 0}, {0, 0}}, 2, 2, 1}

/*
** .....T1.###......T2.#........T3..#.......T4..#..........
** .........#..........##. ........###.........##..........
** ....................#........................#..........
*/

# define TTR_T1 {{{-2, -1}, {-1, -1}, {0, -1}, {-1, 0}}, 2, 2, 1}
# define TTR_T2 {{{-1, -2}, {-1, -1}, {0, -1}, {-1, 0}}, 1, 1, 2}
# define TTR_T3 {{{-1, -1}, {-2, 0}, {-1, 0}, {0, 0}}, 1, 2, 1}
# define TTR_T4 {{{0, -2}, {-1, -1}, {0, -1}, {0, 0}}, 0, 1, 2}

/*
** .....Z1..#.......Z2.##..........
** ........##...........##.........
** ........#.......................
*/

# define TTR_Z1 {{{0, -2}, {-1, -1}, {0, -1}, {-1, 0}}, 0, 1, 2}
# define TTR_Z2 {{{-2, -1}, {-1, -1}, {-1, 0}, {0, 0}}, 2, 2, 1}

/*
** .....S1.#........S2..##.........
** ........##..........##..........
** .........#......................
*/

# define TTR_S1 {{{-1, -2}, {-1, -1}, {0, -1}, {0, 0}}, 1, 1, 2}
# define TTR_S2 {{{-1, -1}, {0, -1}, {-2, 0}, {-1, 0}}, 1, 2, 1}

/*
** GLOBAL'NY'E PEREMENNY'E
** g_dimtet       -- massiv dlya xraneniya tetrimo
** g_num_tet      -- chislo polucheny'x tetrimo (-1, ispol'zovat' kak indeks)
** g_size_max_map -- predel'ny'j razmer polya
** g_map          -- massiv strok dlya xraneniya polya
**
** GLOBAL VARIABLES
** g_dimtet       -- tetrimo storage array
** g_num_tet      -- the number of tetrimo obtained (-1 to use as an index)
** g_size_max_map -- map size limit
** g_map          -- an array of strings to store the map
*/

t_tetrimo		g_dimtet[MAXTOTAL_TET];
int				g_num_tet;
int				g_size_max_map;
char			g_map[MAXTOTAL_TET * LEN_TET][MAXTOTAL_TET * LEN_TET];

/*
** PROTOTYPE
*/

int				tet_solve(void);
int				tet_place(int curent_tet, int size);
int				tet_check_place(t_point *tetblock, int y, int x);
void			tet_put_on_map(t_point *tetblock, int y, int x, char c);
void			tet_clear_map(void);
int				tet_read(int fd);
t_tetrimo		*ft_tetget1(char **dtet);
t_tetrimo		*ft_tetget2(char **dtet, t_point first_block);
t_tetrimo		*ft_tetmake(t_tetcfg *ttr);
int				tet_print_error(char *str);
void			tet_print_map(int size);

#endif
