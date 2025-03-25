#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include "my_strncpy.h"

// Test of the my_strncpy function
void test_my_strncpy(void) {

    // Test 1: Copy 5 characters
    char *result1 = my_strncpy("Hello, World!", 5);
    CU_ASSERT_STRING_EQUAL(result1, "Hello");
    free(result1);

    // Test 2: Copy more characters than the length of the string
    char *result2 = my_strncpy("Test", 10);
    CU_ASSERT_STRING_EQUAL(result2, "Test");
    free(result2);

    // Test 3: Copy 0 characters
    char *result3 = my_strncpy("Sample", 0);
    CU_ASSERT_STRING_EQUAL(result3, "");
    free(result3);
}

int main() {
    // Initialization of the test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Adding a test suite
    CU_pSuite pSuite = CU_add_suite("Suite_my_strncpy", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Adding tests to the suite
    if ((NULL == CU_add_test(pSuite, "test of my_strncpy", test_my_strncpy))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Running tests with basic output
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}