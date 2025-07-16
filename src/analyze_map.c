/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:29:10 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/16 19:01:32 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int open_map(int argc, char **argv)
{
    t_bsq   bsq;
    FILE * map;

    init_bsq(&bsq);
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
            if (!analyze_map(map, &bsq))
                return (0);
        }
        fclose(map);
        //free(bsq.display_map);
    }
    return (1);
}
int analyze_map(FILE * map, t_bsq *bsq)
{
    char    *line;
    size_t  size;

    line = NULL;
    size = 0;
    if (getline(&line, &size, map) == -1)
    {
        fprintf(stderr, RED"Error: Miss Header\n"BASE_COLOR);
        return (0);
    }
    bsq->line_nb = line[0] - 48;
    bsq->display_map = malloc(bsq->line_nb * sizeof(char *) + 1);
    bsq->emp_arg = line[2];
    bsq->obs_arg = line[4];
    bsq->fil_arg = line[6];
    if (bsq->emp_arg == bsq->obs_arg || bsq->emp_arg == bsq->fil_arg || bsq->obs_arg == bsq->fil_arg)
    {
        fprintf(stderr, RED"Error: Same char in the Header\n"BASE_COLOR);
        return (0);
    }
    if (!copy_map(map, bsq))
        return (0);
    if (!check_map(bsq))
        return (0);
    return (1);
}

void init_bsq(t_bsq *bsq)
{
    bsq->line_size = -1;
    bsq->line_nb = -1;
    bsq->emp_arg = -1;
    bsq->obs_arg = -1;
    bsq->fil_arg = -1;
    bsq->best_x = -1;
    bsq->best_y = -1;
    bsq->best_size = -1;
}

int copy_map(FILE * map, t_bsq *bsq)
{
    char    *line;
    size_t  size;
    int     i;

    line = NULL;
    size = 0;
    i = 0;
    while (getline(&line, &size, map) != -1)
    {
        if (i == 0)
            bsq->line_size = ft_strlen(line);
        else if (ft_strlen(line) != bsq->line_size)
        {
            fprintf(stderr, RED"Error: Your map isn't a rectangle\n"BASE_COLOR);
            return (0);
        }
        bsq->display_map[i] = line;
        i++;
    }
    if (i != bsq->line_nb)
    {
        fprintf(stderr, RED"Error: Not the right amount of line\n"BASE_COLOR);
        return (0);
    }
    return (1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
int check_map(t_bsq *bsq)
{
    int i;
    int y;

    i = 0;
    while (bsq->display_map[i])
    {
        y = 0;
        while (bsq->display_map[i][y])
        {
            if (bsq->display_map[i][y] != bsq->emp_arg && bsq->display_map[i][y] != bsq->obs_arg && bsq->display_map[i][y] != '\n')
            {
                fprintf(stderr, RED"Error: Map char undefinded\n"BASE_COLOR);
                return (0);
            }
            y++;
        }
        i++;
    }
    return (1);
}
