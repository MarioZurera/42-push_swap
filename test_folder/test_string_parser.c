/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:30:35 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 22:40:28 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testing.h"

void	test_string_parser(void)
{
	ft_printf(B"================ TESTING STRING PARSER ==============\n"NC);
	START_TEST("Empty String:");
	ASSERT(parse_numbers(2, (char *[]){"", ""}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", " "}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "                "}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "\t\n\r\v\f \n\n\n\t\r\v\v\f\n"}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "\r\t\n\r\v\f \n\n\n\t\r\v\v\f\n\n\n\t\r\v\v\f\n\t\n\r\v\r\n\t\n\r\v\f \n\n\n\t\r\v\v\f\n\t\n\r\v\f \n\n\n\t\r\v\v\f\n\r"}) == NULL);
	END_TEST();


	START_TEST("Invalid String:");
	ASSERT(parse_numbers(2, (char *[]){"", "1 two 3 4"}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "\t1\t2\n3\rfour\v5"}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "42b42"}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "42 b42"}) == NULL);
	ASSERT(parse_numbers(2, (char *[]){"", "42b 42"}) == NULL);
	END_TEST();
	
	
	START_TEST("Simple String:");
    {
		t_stack s = {4, (int []){1, 2, 3, 42}};
		t_stack *result = parse_numbers(2, (char *[]){"", "1 2 3 42"});
		assert_stack(result, &s);
    }
    {
		t_stack s = {6, (int []){1, 2, 3, 4, 5, 6}};
		t_stack *result = parse_numbers(2, (char *[]){"", "\t1\t2\n3\r4\v5\f6\t"});
		assert_stack(result, &s);

    }
    {
		t_stack s = {6, (int []){10, -10, 9, -9, 10, -10}};
		t_stack *result = parse_numbers(2, (char *[]){"", "10 -10 9 -9 10 -10"});
		assert_stack(result, &s);
    }
	END_TEST();


	START_TEST("Extreme Values String:");
    {
		t_stack s = {4, (int []){1, 2, 3, 42}};
		t_stack *result = parse_numbers(2, (char *[]){"", "1 2 3 42"});
		assert_stack(result, &s);
    }
    {
		t_stack s = {6, (int []){1, 2, 3, 4, 5, 6}};
		t_stack *result = parse_numbers(2, (char *[]){"", "\t1\t2\n3\r4\v5\f6\t"});
		assert_stack(result, &s);

    }
    {
		t_stack s = {6, (int []){10, -10, 9, -9, 10, -10}};
		t_stack *result = parse_numbers(2, (char *[]){"", "10 -10 9 -9 10 -10"});
		assert_stack(result, &s);
    }
	END_TEST();

	// Extremes Valid
	// Extremes Invalid

	ft_printf(B"================== END STRING PARSER ================\n\n"NC);
}