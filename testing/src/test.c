/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:54 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 16:47:34 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_testing.h"

static t_test	test;

void	START_TEST(const char *test_name)
{
    test.name = test_name;
	test.error = false;
	test.count = 0;
}

void	ASSERT(bool test_result)
{
	if (test.error)
		return ;
	test.count++;
	if (test_result == false)
	{
		dprintf(STDERR_FILENO, B"%-21s "R"Error in test %d\n"NC, test.name, test.count);
		test.error = true;
	}
}

void	END_TEST()
{
	if (test.error == true || test.name == NULL)
		return ;
	printf(B"%-21s "G"All %d test passed!\n"NC, test.name, test.count);
	test.name = NULL;
}