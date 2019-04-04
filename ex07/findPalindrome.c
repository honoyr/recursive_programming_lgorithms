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

char *Palindrome_recur(char *sequence, int nDelete, int pos)
{
	int n = strlen(sequence);
	while (pos < n / 2 + 1 && sequence[pos] == sequence[n - 1 - pos])
		pos++;
	if (pos == n / 2 + 1)
		return sequence;
	if (nDelete == 0)
		return NULL;
	char *res;
	char *tmp = strdup(sequence);
	memmove(&tmp[pos], &tmp[pos + 1], n - pos);
	if ((res = findPalindrome(tmp, nDelete - 1)))
		return (res);
	strcpy(tmp, sequence);
	memmove(&tmp[n - 1 - pos], &tmp[n - pos], pos + 1);
	if ((res = findPalindrome(tmp, nDelete - 1)))
		return (res);
	free(tmp);
	return 0;
}

char *findPalindrome(char *sequence, int nDelete)
{
	return (sequence ? Palindrome_recur(sequence, nDelete, 0) : NULL);
}
