/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:15:54 by dgonor            #+#    #+#             */
/*   Updated: 2019/04/01 21:15:55 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	sinkIsland(int **map, int row, int col)
{
	if (row < 0 || col < 0 || !map[row] || map[row][col] == -1)
		return ;
	if (map[row][col] == 0)
		return ;
	map[row][col] = 0;	
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
}
