/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:41:06 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/30 18:56:39 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pile    *get_bottom(pile *pile_a)
{
    pile *bottom_a;
    
    bottom_a = malloc(sizeof(*bottom_a));
    bottom_a->element = pile_a->element;

    while (bottom_a->element->next != NULL)
    {
        bottom_a->element = bottom_a->element->next;
    }
    return(bottom_a);
}

int args_number(char **arg)
{
    int i;

    i = 0;
    while(arg[i] != NULL)
    {
        i++;
    }
    return (i);    
}

void	get_arg(int argc, char **argv, t_arg *arg)
{
	int		i;
	int		n;
	char	**tab;

	arg->ac = -1;
	n = -1;
	if (!(arg->av = malloc(sizeof(char *) * 1000)))
		return;
	while (++n < argc)
	{
		i = -1;
		tab = ft_split(argv[n], ' ');
		while (tab[++i])
		{
			arg->av[++arg->ac] = ft_strdup(tab[i]);
			free(tab[i]);
		}
		free(tab);
	}
	arg->av[++arg->ac] = NULL;
}

void	free_arg(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < arg->ac)
	{
		free(arg->av[i]);
	}
	free(arg->av);
}

void	free_pile(pile *pile_a)
{
	pile	*temp;
	temp = malloc(sizeof(*temp));
	temp->element = pile_a->element;
	while(pile_a->element != NULL)
	{		
		pile_a->element = pile_a->element->next;
		free(pile_a->element);
	}
	free(temp->element);
	free(pile_a);
}
