#include "test.h"


void *s21_to_lower(const char *str); 


START_TEST(to_lower1) {
    const char *input1 = "HELLO, WORLD!";
    const char *output = "hello, world!";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower2) {
    const char *input1 = "HELLO, \0WORLD!";
    const char *output = "hello, \0world!";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    size_t len = 13; 
    ck_assert_int_eq(memcmp(result, output, len), 0);  
    free(result);
}
END_TEST

START_TEST(to_lower3) {
    const char *input1 = "HELLO, WORLD123456789!";
    const char *output = "hello, world123456789!";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower4) {
    const char *input1 = "ASDFG\0HJKL";
    const char *output = "asdfg\0hjkl";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    size_t len = 10; 
    ck_assert_int_eq(memcmp(result, output, len), 0);  
    free(result);
}
END_TEST

START_TEST(to_lower5) {
    const char *input1 = "!@#$%^&*()_+HELLO, WORLD!";
    const char *output = "!@#$%^&*()_+hello, world!";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower6) {
    const char *input1 = "";
    const char *output = "";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower7) {
    const char *input1 = "HE\tLLO, WORLD!";
    const char *output = "he\tllo, world!";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower8) {
    const char *input1 = "QWERTYUIOPASDFGHJKL\012345678910";
    const char *output = "qwertyuiopasdfghjkl\012345678910";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower9) {
    const char *input1 = "ONE OF THE MOST \tFAMOUS STATUES IN THE WORLD STANDS ON 121212121AN";
    const char *output = "one of the most \tfamous statues in the world stands on 121212121an";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL); 
    ck_assert_str_eq(result, output);  
    free(result);
}
END_TEST

START_TEST(to_lower10) {
    const char *input1 = "1234567890!@#$%^&*()_+-=";
    const char *output = "1234567890!@#$%^&*()_+-=";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, output);
    free(result);
}
END_TEST

START_TEST(to_lower11) {
    const char *input1 = "abcdefghijklmnopqrstuvwxyz";
    const char *output = "abcdefghijklmnopqrstuvwxyz";
    char *result = s21_to_lower(input1);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, output);
    free(result);
}
END_TEST

Suite *suite_to_lower(void) {
    Suite *s = suite_create("to_lower");
    TCase *tc = tcase_create("to_lower_tc");

    tcase_add_test(tc, to_lower1);
    tcase_add_test(tc, to_lower2);
    tcase_add_test(tc, to_lower3);
    tcase_add_test(tc, to_lower4);
    tcase_add_test(tc, to_lower5);
    tcase_add_test(tc, to_lower6);
    tcase_add_test(tc, to_lower7);
    tcase_add_test(tc, to_lower8);
    tcase_add_test(tc, to_lower9);
    tcase_add_test(tc, to_lower10);
    tcase_add_test(tc, to_lower11);

    suite_add_tcase(s, tc);
    return s;
}