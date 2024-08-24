/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:59:55 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:55 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TESTING
# define PUSH_SWAP_TESTING

#include "../libft/libft.h"
#include "push_swap.h"
#include <unity.h>

void	stack_invalid_input(void);
void	stack_valid_input(void);
void	stack_with_repetitions(void);
void	stack_without_repetitions(void);

void	stack_swap(void);
void	stack_push(void);
void	stack_rotate(void);

#endif /* PUSH_SWAP_TESTING */
