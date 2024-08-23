/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	sa(const t_pair *pair)
{
	if (pair == NULL || pair->stack_a == NULL || pair->stack_a->list == NULL)
		return (0);
	swap(pair->stack_a->list, pair->stack_a->list + 1);
	ft_printf("sa");
	return (1);
}

int	sb(const t_pair *pair)
{
	if (pair == NULL || pair->stack_b == NULL || pair->stack_b->list == NULL)
		return (0);
	swap(pair->stack_b->list, pair->stack_b->list + 1);
	ft_printf("sb");
	return (1);
}

int	ss(const t_pair *pair)
{
	if (pair == NULL || pair->stack_a == NULL || pair->stack_b == NULL)
		return (0);
	if (pair->stack_a->list == NULL || pair->stack_b->list == NULL)
		return (0);
	swap(pair->stack_a->list, pair->stack_a->list + 1);
	swap(pair->stack_b->list, pair->stack_b->list + 1);
	ft_printf("ss");
	return (1);
}