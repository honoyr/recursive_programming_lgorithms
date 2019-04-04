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

void		count(int i)
{
	int j = 1;
	if (!i)
		return ;
	count(i - 1);
	printf(", %i", j);
}

void printPossibleSlices(int pizzaSize)
{
	static int i;
	if (!pizzaSize)
		return ;
	printf("[");
	printf("%i", pizzaSize);
	if (i)
		count(i);
	printf("]\n");
	i++;
	printPossibleSlices(pizzaSize - 1);
}

// typedef struct s_array t_array;

// void getSlices(t_array *arr, int sizeRemain)
// {
// 	if (sizeRemain == 0)
// 		arrayPrint(arr);
// 	else
// 		for (int i = sizeRemain; i >= 1; i--)
// 		{
// 			t_array *tmp = arrayClone(arr);
// 			arrayAppend(tmp, i);
// 			getSlices(tmp, sizeRemain - i);
// 		}
// }

// void printPossibleSlices(int pizzaSize)
// {
// 	t_array *arr = arrayInit();
// 	getSlices(arr, pizzaSize);
// 	free(arr->content);
// 	free(arr);
// }