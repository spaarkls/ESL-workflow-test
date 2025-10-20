#include <check.h>
#include <math.h>
#include <stdlib.h>
#include "vector/vector3D.h"

#define EPS 1e-9

START_TEST(test_sum)
{
    
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    vector3D_t *b = vector3D_init_with_value(4, 5, 6);
    vector3D_t *res = vector3D_init();

    vector3D_sum(a, b, res);

    ck_assert_double_eq_tol(vector3D_get_x(res), 5.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(res), 7.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(res), 9.0, EPS);
    vector3D_destroy(a);
    vector3D_destroy(b);
    vector3D_destroy(res);

}
END_TEST

START_TEST(test_sub)
{
    vector3D_t *a = vector3D_init_with_value(4, 5, 6);
    vector3D_t *b = vector3D_init_with_value(1, 2, 3);
    vector3D_t *res = vector3D_init();

    vector3D_sub(a, b, res);

    ck_assert_double_eq_tol(vector3D_get_x(res), 3.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(res), 3.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(res), 3.0, EPS);
    vector3D_destroy(a);
    vector3D_destroy(b);
    vector3D_destroy(res);
}
END_TEST

START_TEST(test_dot)
{
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    vector3D_t *b = vector3D_init_with_value(4, 5, 6);

    double res = vector3D_dot(a, b);
    ck_assert_double_eq_tol(res, 32.0, EPS);
    vector3D_destroy(a);
    vector3D_destroy(b);
}
END_TEST

START_TEST(test_cross)
{
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    vector3D_t *b = vector3D_init_with_value(4, 5, 6);
    vector3D_t *res = vector3D_init();

    vector3D_cross(a, b, res);

    ck_assert_double_eq_tol(vector3D_get_x(res), -3.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(res),  6.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(res), -3.0, EPS);
    vector3D_destroy(a);
    vector3D_destroy(b);
    vector3D_destroy(res);
}
END_TEST

START_TEST(test_init_destroy)
{
    vector3D_t *v = vector3D_init();
    ck_assert_ptr_nonnull(v);
    vector3D_destroy(v);
}
END_TEST

START_TEST(test_sum_with_zero)
{
    vector3D_t *a = vector3D_init_with_value(3, -2, 5);
    vector3D_t *zero = vector3D_init_with_value(0, 0, 0);
    vector3D_t *res = vector3D_init();

    vector3D_sum(a, zero, res);
    ck_assert_double_eq_tol(vector3D_get_x(res), 3, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(res), -2, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(res), 5, EPS);
    vector3D_destroy(a);
    vector3D_destroy(zero);
    vector3D_destroy(res);
}
END_TEST

START_TEST(test_dot_2)
{
    vector3D_t *a = vector3D_init_with_value(1, 0, 0);
    vector3D_t *b = vector3D_init_with_value(0, 1, 0);
    
    double res = vector3D_dot(a, b);
    ck_assert_double_eq_tol(res, 0.0, EPS);
}
END_TEST

START_TEST(test_cross_2)
{
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    vector3D_t *b = vector3D_init_with_value(2, 4, 6);
    vector3D_t *res = vector3D_init();

    vector3D_cross(a, b, res);

    ck_assert_double_eq_tol(vector3D_get_x(res), 0.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(res), 0.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(res), 0.0, EPS);
    vector3D_destroy(a);
    vector3D_destroy(b);
    vector3D_destroy(res);
}
END_TEST

START_TEST(test_null_safety)
{
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    vector3D_t *b = vector3D_init_with_value(4, 5, 6);
    vector3D_cross(NULL, b, a);
    vector3D_cross(a, NULL, b);
    vector3D_cross(a, b, NULL);
    
    vector3D_destroy(a);
    vector3D_destroy(b);
}
END_TEST

START_TEST(test_getters) {
    vector3D_t *a = vector3D_init_with_value(1, 2, 3);
    ck_assert_double_eq_tol(vector3D_get_x(a), 1.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(a), 2.0, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(a), 3.0, EPS);
    vector3D_destroy(a);
}
END_TEST

START_TEST(test_setters) {
    vector3D_t *a = vector3D_init();
    vector3D_set_x(a, 12);
    ck_assert_double_eq_tol(vector3D_get_x(a), 12, EPS);
    vector3D_set_y(a, 9321);
    ck_assert_double_eq_tol(vector3D_get_y(a), 9321, EPS);
    vector3D_set_z(a, -156);
    ck_assert_double_eq_tol(vector3D_get_z(a), -156, EPS);
    

    vector3D_set_xyz(a, 12, 14, 15);
    ck_assert_double_eq_tol(vector3D_get_x(a), 12, EPS);
    ck_assert_double_eq_tol(vector3D_get_y(a), 14, EPS);
    ck_assert_double_eq_tol(vector3D_get_z(a), 15, EPS);

    vector3D_destroy(a);
}

Suite *vector3D_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Vector3D");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sum);
    tcase_add_test(tc_core, test_sub);
    tcase_add_test(tc_core, test_dot);
    tcase_add_test(tc_core, test_cross);
    tcase_add_test(tc_core, test_init_destroy);

    tcase_add_test(tc_core, test_sum_with_zero);
    tcase_add_test(tc_core, test_dot_2);
    tcase_add_test(tc_core, test_cross_2);
    tcase_add_test(tc_core, test_null_safety); 
    tcase_add_test(tc_core, test_getters); 
    tcase_add_test(tc_core, test_setters); 
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = vector3D_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
