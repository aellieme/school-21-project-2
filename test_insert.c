#include "../test.h"

START_TEST(insert1) {
    const char *src = "Hello,  sun, sea!";
    const char *str = "peace,";
    s21_size_t start_index = 7;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Hello, peace, sun, sea!"); 
    free(result);
}
END_TEST

START_TEST(insert2) {
    const char *src = "Hello, world!";
    const char *str = "";
    s21_size_t start_index = 7;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
}
END_TEST

START_TEST(insert3) {
    const char *src = "";
    const char *str = "Hello";
    s21_size_t start_index = 0;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Hello");
    free(result);
}
END_TEST

START_TEST(insert4) {
    const char *src = "Hello, world!";
    const char *str = "!!!";
    s21_size_t start_index = 0;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "!!!Hello, world!");
    free(result);
}
END_TEST

START_TEST(insert5) {
    const char *src = "Hello, world!";
    const char *str = "!!!";
    s21_size_t start_index = 100; 
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert6) {
    const char *src = "12345";
    const char *str = "678";
    s21_size_t start_index = 3;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "12367845");
    free(result);
}
END_TEST

START_TEST(insert7) {
    const char *src = "Hello";
    const char *str = " peace";
    s21_size_t start_index = 5;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Hello peace");
    free(result);
}
END_TEST

START_TEST(insert8) {
    const char *src = "123";
    const char *str = "789";
    s21_size_t start_index = 7;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert9) {
    const char *src = "";
    const char *str = "";
    s21_size_t start_index = 0;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "");
    free(result);
}
END_TEST

START_TEST(insert10) {
    const char *src = "123";
    const char *str = "789";
    s21_size_t start_index = 0;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "789123");
    free(result);
}
END_TEST

// New test cases for better coverage
START_TEST(insert11) {
    char *result = s21_insert(s21_NULL, "test", 0);
    ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert12) {
    char *result = s21_insert("test", s21_NULL, 0);
    ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert13) {
    const char *src = "Hello, world!";
    const char *str = "beautiful ";
    s21_size_t start_index = 7;
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Hello, beautiful world!");
    free(result);
}
END_TEST

START_TEST(insert14) {
    const char *src = "Test";
    const char *str = "123";
    s21_size_t start_index = 4;  // Insert at the end
    char *result = s21_insert(src, str, start_index);
    ck_assert_ptr_ne(result, s21_NULL);
    ck_assert_str_eq(result, "Test123");
    free(result);
}
END_TEST

Suite *suite_insert(void) {
    Suite *s = suite_create("insert");
    TCase *tc = tcase_create("insert_tc");

    tcase_add_test(tc, insert1);
    tcase_add_test(tc, insert2);
    tcase_add_test(tc, insert3);
    tcase_add_test(tc, insert4);
    tcase_add_test(tc, insert5);
    tcase_add_test(tc, insert6);
    tcase_add_test(tc, insert7);
    tcase_add_test(tc, insert8);
    tcase_add_test(tc, insert9);
    tcase_add_test(tc, insert10);
    tcase_add_test(tc, insert11);
    tcase_add_test(tc, insert12);
    tcase_add_test(tc, insert13);
    tcase_add_test(tc, insert14);

    suite_add_tcase(s, tc);
    return s;
    
}