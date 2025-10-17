#include <check.h>
#include <math.h>
#include <stdlib.h>
#include "vector/vector3D.h"

#define EPS 1e-9

START_TEST(test_sum)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};
    vector3D_t res;

    vector3D_sum(&a, &b, &res);

    ck_assert_double_eq_tol(res.x, 5.0, EPS);
    ck_assert_double_eq_tol(res.y, 7.0, EPS);
    ck_assert_double_eq_tol(res.z, 9.0, EPS);
}
END_TEST

START_TEST(test_sub)
{
    vector3D_t a = {4, 5, 6};
    vector3D_t b = {1, 2, 3};
    vector3D_t res;

    vector3D_sub(&a, &b, &res);

    ck_assert_double_eq_tol(res.x, 3.0, EPS);
    ck_assert_double_eq_tol(res.y, 3.0, EPS);
    ck_assert_double_eq_tol(res.z, 3.0, EPS);
}
END_TEST

START_TEST(test_dot)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};

    double res = vector3D_dot(&a, &b);

    ck_assert_double_eq_tol(res, 32.0, EPS);
}
END_TEST

START_TEST(test_cross)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};
    vector3D_t res;

    vector3D_cross(&a, &b, &res);

    ck_assert_double_eq_tol(res.x, -3.0, EPS);
    ck_assert_double_eq_tol(res.y,  6.0, EPS);
    ck_assert_double_eq_tol(res.z, -3.0, EPS);
}
END_TEST

START_TEST(test_init_destroy)
{
    vector3D_t *v = vector3D_init();
    ck_assert_ptr_nonnull(v);

    v->x = 10;
    v->y = 20;
    v->z = 30;

    ck_assert_double_eq_tol(v->x, 10, EPS);
    ck_assert_double_eq_tol(v->y, 20, EPS);
    ck_assert_double_eq_tol(v->z, 30, EPS);

    vector3D_destroy(v);
}
END_TEST

START_TEST(test_sum_with_zero)
{
    vector3D_t a = {3, -2, 5};
    vector3D_t zero = {0, 0, 0};
    vector3D_t res;

    vector3D_sum(&a, &zero, &res);
    ck_assert_double_eq_tol(res.x, 3, EPS);
    ck_assert_double_eq_tol(res.y, -2, EPS);
    ck_assert_double_eq_tol(res.z, 5, EPS);
}
END_TEST

START_TEST(test_sum_commutative)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};
    vector3D_t res1, res2;

    vector3D_sum(&a, &b, &res1);
    vector3D_sum(&b, &a, &res2);

    ck_assert_double_eq_tol(res1.x, res2.x, EPS);
    ck_assert_double_eq_tol(res1.y, res2.y, EPS);
    ck_assert_double_eq_tol(res1.z, res2.z, EPS);
}
END_TEST

START_TEST(test_cross_anticommutative)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};
    vector3D_t ab, ba;

    vector3D_cross(&a, &b, &ab);
    vector3D_cross(&b, &a, &ba);

    ck_assert_double_eq_tol(ab.x, -ba.x, EPS);
    ck_assert_double_eq_tol(ab.y, -ba.y, EPS);
    ck_assert_double_eq_tol(ab.z, -ba.z, EPS);
}
END_TEST

START_TEST(test_dot_perpendicular)
{
    vector3D_t a = {1, 0, 0};
    vector3D_t b = {0, 1, 0};
    double res = vector3D_dot(&a, &b);
    ck_assert_double_eq_tol(res, 0.0, EPS);
}
END_TEST

START_TEST(test_cross_parallel)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {2, 4, 6};
    vector3D_t res;

    vector3D_cross(&a, &b, &res);

    ck_assert_double_eq_tol(res.x, 0.0, EPS);
    ck_assert_double_eq_tol(res.y, 0.0, EPS);
    ck_assert_double_eq_tol(res.z, 0.0, EPS);
}
END_TEST

START_TEST(test_null_safety)
{
    vector3D_t a = {1, 2, 3};
    vector3D_t b = {4, 5, 6};
    vector3D_cross(NULL, &b, &a);
    vector3D_cross(&a, NULL, &b);
    vector3D_cross(&a, &b, NULL);
}
END_TEST


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
    tcase_add_test(tc_core, test_sum_commutative);
    tcase_add_test(tc_core, test_cross_anticommutative);
    tcase_add_test(tc_core, test_dot_perpendicular);
    tcase_add_test(tc_core, test_cross_parallel);
    tcase_add_test(tc_core, test_null_safety); 
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
