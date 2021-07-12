/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:13:13 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/07/11 17:42:10 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void afficherPile(pile *pile_a)
{
    if (pile_a == NULL)
    {
        exit(EXIT_FAILURE);
    }
    element *actuel;  
    actuel = malloc(sizeof(*actuel));
    actuel = pile_a->element;

    while (actuel != NULL)
    {
        printf("%d\n", actuel->number);
        actuel = actuel->next;
    }

    printf("\n");
    free(actuel);
}

int    init_a(int n, pile *pile_a)
{   
    element *element_a;

    element_a = malloc(sizeof(*element_a));
    if (element_a == NULL)
        return (-1);
    element_a->number = n;
    element_a->next = pile_a->element;    
    pile_a->element = element_a;
    pile_a->size++;
    return (0);    
}

int main(int argc, char **argv)
{
    int i;
    int n;
  //  char    **param;
    pile    *pile_a;
    pile    *pile_b;   
    t_arg		arg;
    n = 0;
  //  param = ft_split(argv[1], ' ');
    get_arg(argc, argv, &arg);
  // printf("%s", argv[0]);
   // i = args_number(param) - 1;
 //   if(!check_error(i, param))
   //     return(-1);
    argc = 2;
    i = args_number(argv) - 1;
    pile_a = malloc(sizeof(*pile_a));
    pile_b = malloc(sizeof(*pile_b));
    pile_a->element = NULL;
    pile_b->element = NULL;
    while (i >= 1)
    {   
        n = ft_atoi(argv[i]);
        init_a(n, pile_a);
        pile_a->element->rank = pile_a->size;
        i--;
    }
   // afficherPile(pile_a);
    algo(pile_a, pile_b);
   // afficherPile(pile_b);
   //afficherPile(pile_a);
    free_arg(&arg);
  //  free(param);
    free(pile_a);
    free(pile_b);
    return (0);
}