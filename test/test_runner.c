#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

int add(int a, int b) { return a + b; }

void test_Addition(void) {
	TEST_ASSERT_EQUAL(30, add(10, 20));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_Addition);
	return UNITY_END();
}
