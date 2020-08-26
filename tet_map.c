/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:06:23 by mretha            #+#    #+#             */
/*   Updated: 2019/06/01 14:06:31 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**   tet_clear_map -- ochishhaet pole, zapolnyaya ego nulyami.
**
**   tet_clear_map -- clears the map, filling it with zeros.
*/

void	tet_clear_map(void)
{
	int		y;
	int		x;

	y = -1;
	while (++y < g_size_max_map)
	{
		x = -1;
		while (++x < g_size_max_map)
			g_map[y][x] = '\0';
	}
}
