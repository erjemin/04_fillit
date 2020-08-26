/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:03:23 by mretha            #+#    #+#             */
/*   Updated: 2019/06/01 15:03:31 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		file;
	int		size;

	if (argc != 2)
		return (tet_print_error(""));
	if ((file = open(argv[1], O_RDONLY)) == -1)
		return (tet_print_error(""));
	if (!(tet_read(file)))
		return (tet_print_error("10"));
	g_size_max_map = (g_num_tet + 1) * LEN_TET;
	tet_clear_map();
	if ((size = tet_solve()) > 0)
		tet_print_map(size);
	else
		return (tet_print_error(""));
	close(file);
	return (0);
}
