#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include "my_strncpy.h"

// Test de la fonction my_strncpy
void test_my_strncpy(void) {

    // Test 1 : Copie de 5 caractères
    char *result1 = my_strncpy("Hello, World!", 5);
    CU_ASSERT_STRING_EQUAL(result1, "Hello");
    free(result1);

    // Test 2 : Copie de plus de caractères que la longueur de la chaîne
    char *result2 = my_strncpy("Test", 10);
    CU_ASSERT_STRING_EQUAL(result2, "Test");
    free(result2);

    // Test 3 : Copie de 0 caractère
    char *result3 = my_strncpy("Sample", 0);
    CU_ASSERT_STRING_EQUAL(result3, "");
    free(result3);
}

int main() {
    // Initialisation du registre de tests
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Ajout d'un ensemble de tests
    CU_pSuite pSuite = CU_add_suite("Suite_my_strncpy", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ajout des tests à l'ensemble
    if ((NULL == CU_add_test(pSuite, "test of my_strncpy", test_my_strncpy))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Exécution des tests avec une sortie basique
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}