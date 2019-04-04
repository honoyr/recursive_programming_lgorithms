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

void	recursion(int pizzaSize, double *best, double sum, double *prices)
{
	if (pizzaSize <= 0)
		if (sum > *best)
			*best = sum;
	for (int i = 1; i <= pizzaSize; i++)
		recursion(pizzaSize - i, best, sum + prices[i], prices);
}

double bestPrice(int pizzaSize, double *prices)
{
	double bestPrice = 0;
	recursion(pizzaSize, &bestPrice, 0, prices);
	return (bestPrice);
}
