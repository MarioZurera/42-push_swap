/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 18:26:35 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/colors.h"
# include <limits.h>

typedef struct  stack
{
    int             *list;
    unsigned int    size;
}   t_stack;

t_stack	*init_stack(int amount_of_nums);

void	free_stack(t_stack *stack);

void	check_stack(t_stack *stack);

t_stack	*parse_numbers(int argc, char **argv);

int		main(int argc, char **argv);

#endif /* PIPEX_H */