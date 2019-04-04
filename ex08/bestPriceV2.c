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

double	recursion(int pizzaSize, double *prices, double *b)
{
	double compare = 0;
	if (b[pizzaSize])
		return (b[pizzaSize]);
	b[pizzaSize] = prices[pizzaSize];
	for (int i = 1; i < pizzaSize; i++)
	{
		compare = recursion(i, prices, b) + recursion(pizzaSize - i, prices, b);
		if (compare > b[pizzaSize])
			b[pizzaSize] = compare;
	}
	return b[pizzaSize];
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *bestPrice = malloc(sizeof(double));
	return recursion(pizzaSize, prices, bestPrice);
}