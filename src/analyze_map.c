/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:29:10 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/10 19:09:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.h"

int open_map(int argc, char **argv)
{
    FILE * map;
    if (argc == 1)
    {
        return (0);
    }
    else {
        map = fopen(argv[1], "r");
        if (!map)
        {
            fprintf(stderr, RED"Error: Can't open"MAGENTA" %s\n"BASE_COLOR, argv[1]);
            return (0);
        }
        else {
            if (!analyze_map(map))
                return (0);
        }
        fclose(map);
    }
    return (1);
}
int analyze_map(FILE * map)
{
    t_bsp   bsp;
    char    *line;
    size_t  size;

    init_bsp(&bsp);
    line = NULL;
    size = 0;
    if (getline(&line, &size, map) == -1)
    {
        fprintf(stderr, RED"Error: Miss Header\n"BASE_COLOR);
        return (0);
    }
    bsp.line_nb = line[0];
    bsp.emp_arg = line[2];
    bsp.obs_arg = line[4];
    bsp.fil_arg = line[6];
    if (bsp.emp_arg == bsp.obs_arg || bsp.emp_arg == bsp.fil_arg || bsp.obs_arg == bsp.fil_arg)
    {
        fprintf(stderr, RED"Error: Same char in the Header\n"BASE_COLOR);
        return (0);
    }
    return (1);
}

void init_bsp(t_bsp *bsp)
{
    bsp->line_size = 0;
    bsp->line_nb = 0;
    bsp->emp_arg = 0;
    bsp->obs_arg = 0;
    bsp->fil_arg = 0;
    bsp->best_x = 0;
    bsp->best_y = 0;
    bsp->best_size = 0;
}