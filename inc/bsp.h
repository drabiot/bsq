/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:27:56 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/10 18:52:53 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H
# define BSP_H

# include "color.h"

# include <stdio.h>

typedef struct s_bsp
{
    int     line_size;
    int     line_nb;

    char    emp_arg;
    char    obs_arg;
    char    fil_arg;

    int     best_x;
    int     best_y;
    int     best_size;
}			t_bsp;


int     open_map(int argc, char **argv);
int     analyze_map(FILE * map);
void    init_bsp(t_bsp *bsp);

#endif //BSP_H
