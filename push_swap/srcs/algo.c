/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/08/06 14:13:37 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_upper(pile *pile_a, pile *pile_b)
{
	int	bottom;

	bottom = pile_b->size - pile_b->rank_f;
	if (pile_b->rank_f <= pile_b->size / 2)
	{
		while (pile_b->rank_f > 1)
		{
			rotate(pile_b, 'b');
			pile_b->rank_f--;
		}
	}
	else if (pile_b->rank_f > pile_b->size / 2)
	{
		while (bottom + 1 > 0)
		{
			reverse_rotate(pile_b, 'b');
			bottom--;
		}
	}
	push_to_a(pile_a, pile_b);
}

int	before_pb(pile *pile_a, pile *pile_b)
{
	int	fb;
	int	sb;
	int	fa;
	int	sa;

	fb = pile_b->element->number;
	sb = pile_b->element->next->number;
	fa = pile_a->element->number;
	sa = pile_a->element->next->number;
	if (pile_b->size < 2 || pile_a->size < 2)
		return (0);
	if (fa < sa && pile_a->size >= 2)
		swap(pile_a, 'a');
	if (fb < sb)
		swap(pile_b, 'b');
	return (0);
}

int	sort_b(pile *pile_a, pile *pile_b, int i)
{
	pile_b->rank_f = 1;
	pile_b->upper = pile_b->element;
	while (pile_b->size > 1)
	{
		if (pile_b->upper->number == pile_a->base[i])
		{
			push_upper(pile_a, pile_b);
			return (0);
		}
		pile_b->upper = pile_b->upper->next;
		pile_b->rank_f++;
	}
	return (0);
}
