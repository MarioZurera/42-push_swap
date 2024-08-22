/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:43:05 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "push_swap_testing.h"

void setUp(void) {}

void tearDown(void) {}

static void run_stack_tests(void) {
	TEST_MESSAGE("Test Stack");
	RUN_TEST(stack_valid_input_list);
	RUN_TEST(stack_invalid_input_list);
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	UNITY_BEGIN();
	run_stack_tests();
	return (UNITY_END());
}
