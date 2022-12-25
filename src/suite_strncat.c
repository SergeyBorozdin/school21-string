#include "tests_suitcases.h"

START_TEST(strncat_1) {
    char str_1[100] = "Hello";
    char str_2[100] = " World";
    ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));
} END_TEST

START_TEST(strncat_2) {
    char str_1[100] = "\0";
    char str_2[100] = "i am proger";
    ck_assert_str_eq(strncat(str_1, str_2, 13), s21_strncat(str_1, str_2, 13));
} END_TEST

START_TEST(strncat_3) {
    char str_1[100] = "\n";
    char str_2[100] = "p-\0-roger";
    ck_assert_str_eq(strncat(str_1, str_2, 9), s21_strncat(str_1, str_2, 9));
} END_TEST

START_TEST(strncat_4) {
    char str_1[100] = "-\t-";
    char str_2[100] = "\0";
    ck_assert_str_eq(strncat(str_1, str_2, 2), s21_strncat(str_1, str_2, 2));
} END_TEST

START_TEST(strncat_5) {
    char str_1[100] = " \b";
    char str_2[100] = "  1 \n";
    ck_assert_str_eq(strncat(str_1, str_2, 5), s21_strncat(str_1, str_2, 5));
} END_TEST

START_TEST(strncat_6) {
    char str_1[100] = " 0 ";
    char str_2[100] = "123";
    ck_assert_str_eq(strncat(str_1, str_2, 0), s21_strncat(str_1, str_2, 0));
} END_TEST

START_TEST(strncat_7) {
    char str_1[100] = " 0 ";
    char str_2[100] = "qwer";
    ck_assert_str_eq(strncat(str_1, str_2, 0+2), s21_strncat(str_1, str_2, 0+2));
} END_TEST

START_TEST(strncat_8) {
    char str_1[100] = " 0 ";
    char str_2[100] = "error";
    ck_assert_str_eq(strncat(str_1, str_2, 4-1), s21_strncat(str_1, str_2, 4-1));
} END_TEST

START_TEST(strncat_9) {
    char str_1[100] = "999";
    char str_2[100] = "puckKK";
    ck_assert_str_eq(strncat(str_1, str_2, 2*2), s21_strncat(str_1, str_2, 2*2));
} END_TEST

START_TEST(strncat_10) {
    char s1[255] = "QWERTY";
    char s2[255] = "E";
    ck_assert_pstr_eq(strncat(s1, s2, 6), s21_strncat(s1, s2, 6));
} END_TEST

Suite * suite_strncat(void) {
    Suite *s17;
    TCase *tc17;
    s17 = suite_create("s21_STRNCAT");
    tc17 = tcase_create("case_strncat");
    tcase_add_test(tc17, strncat_1);
    tcase_add_test(tc17, strncat_2);
    tcase_add_test(tc17, strncat_3);
    tcase_add_test(tc17, strncat_4);
    tcase_add_test(tc17, strncat_5);
    tcase_add_test(tc17, strncat_6);
    tcase_add_test(tc17, strncat_7);
    tcase_add_test(tc17, strncat_8);
    tcase_add_test(tc17, strncat_9);
    tcase_add_test(tc17, strncat_10);
    suite_add_tcase(s17, tc17);
    return s17;
}
