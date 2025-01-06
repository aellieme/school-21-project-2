#include "test.h"


START_TEST(insert1)
{
#line 7
const char *src = "Hello,  sun, sea!";
const char *str = "peace,";
s21_size_t start_index = 7;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, peace, sun, sea!"); 
free(result);

}
END_TEST

START_TEST(insert2)
{
#line 16
const char *src = "Hello, world!";
const char *str = "";
s21_size_t start_index = 7;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, world!");
free(result);

}
END_TEST

START_TEST(insert3)
{
#line 25
const char *src = "";
const char *str = "Hello";
s21_size_t start_index = 0;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello");
free(result);

}
END_TEST

START_TEST(insert4)
{
#line 34
const char *src = "Hello, world!";
const char *str = "!!!";
s21_size_t start_index = 0;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "!!!Hello, world!");
free(result);

}
END_TEST

START_TEST(insert5)
{
#line 43
const char *src = "Hello, world!";
const char *str = "!!!";
s21_size_t start_index = 100; 
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_eq(result, s21_NULL); 
free(result);


}
END_TEST

START_TEST(insert6)
{
#line 52
const char *src = "12345";
const char *str = "678";
s21_size_t start_index = 3;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "12367845");
free(result);

}
END_TEST

START_TEST(insert7)
{
#line 61
const char *src = "Hello\0world!";
const char *str = " peace";
s21_size_t start_index = 5;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello peace\0world!");
free(result);

}
END_TEST

START_TEST(insert8)
{
#line 70
const char *src = "123\0456";
const char *str = "789";
s21_size_t start_index = 7;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_eq(result, s21_NULL); 
free(result);


}
END_TEST

START_TEST(insert9)
{
#line 79
const char *src = "";
const char *str = "";
s21_size_t start_index = 0;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "");
free(result);

}
END_TEST

START_TEST(insert10)
{
#line 88
const char *src = "123\0456";
const char *str = "789";
s21_size_t start_index = 0;
char *result = s21_insert(src, str, start_index);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "789123\0456");
free(result);

}
END_TEST

Suite *suite_insert(void)
{
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

     
    suite_add_tcase(s, tc);
    return s;
}

