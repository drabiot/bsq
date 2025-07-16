/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:27:56 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/16 19:02:07 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "color.h"

# include <stdio.h>
# include <stdlib.h>

typedef struct s_bsq
{
    int     line_size;
    int     line_nb;

    char    emp_arg;
    char    obs_arg;
    char    fil_arg;

    int     best_x;
    int     best_y;
    int     best_size;

    char    **display_map;
}			t_bsq;


int     open_map(int argc, char **argv);
int     analyze_map(FILE * map, t_bsq *bsq);
void    init_bsq(t_bsq *bsq);
int     copy_map(FILE * map, t_bsq *bsq);
int     ft_strlen(char *str);
int     check_map(t_bsq *bsq);

#endif //BSQ_H
