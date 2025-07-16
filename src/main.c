/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:13:20 by tchartie          #+#    #+#             */
/*   Updated: 2025/07/16 19:01:39 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        fprintf(stderr, RED"Error: Too many input\n"BASE_COLOR);
        return (1);
    }
    if (!open_map(argc, argv))
        return (1);

    return (0);
}