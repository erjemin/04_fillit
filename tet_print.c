/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:06:23 by mretha            #+#    #+#             */
/*   Updated: 2019/06/20 19:35:42 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	 tet_print_error -- vy`vodit na e`kran soobshhenie ob oshibke. Argument
**   (*str)  ispol`zuetsya dlya otladki pri diagnostirovanii tipov oshibki.
**
**   tet_print_error -- displays an error message. The argument (* str) is
**   used for debugging when diagnosing error types.
*/

int			tet_print_error(char *str)
{
	ft_putstr("error");
	ft_putstr(str);
	ft_putstr("\n");
	return (0);
}

/*
**	 tet_print_map -- vy`vodit na e`kran pole razmerom size (int size).
**   Ukazatel` na massiv strok (char **), v kotorom xranitsya pole, dolzhen
**   naxoditsya v global`noj peremennoj g_map.
**
**   tet_print_error -- displays a map with size (int size). A pointer to an
**   array of strings (char **) in which the field is stored must be in the
**   global variable g_map.
*/

void		tet_print_map(int size)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			if (g_map[y][x])
				ft_putchar(g_map[y][x]);
			else
				ft_putchar(SPACE);
		ft_putchar('\n');
	}
}
