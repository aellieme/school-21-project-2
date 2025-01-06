#include "test.h"



//void *s21_to_upper(const char *str);

START_TEST(to_upper1)
{
#line 7
const char *input1 = "hello, world!";
const char *output = "HELLO, WORLD!";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, output);
free(result);

}
END_TEST

START_TEST(to_upper2)
{
#line 15
const char *input1 = "\0hello, world!";
const char *output = "\0HELLO, WORLD!";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL);  
ck_assert_str_eq(result, output);  
free(result);  

}
END_TEST

START_TEST(to_upper3)
{
#line 23
const char *input1 = "";
const char *output = "";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL);  
ck_assert_str_eq(result, output);  
free(result);  

}
END_TEST

START_TEST(to_upper4)
{
#line 31
const char *input1 = "hello, wor\0ld!";
const char *output = "HELLO, WOR\0LD!";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL);  
ck_assert_str_eq(result, output);  
free(result); 

}
END_TEST

START_TEST(to_upper5)
{
#line 39
const char *input1 = "asdfghjkl";
const char *output = "ASDFGHJKL";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL); 
ck_assert_str_eq(result, output); 
free(result);  

}
END_TEST

START_TEST(to_upper6)
{
#line 47
const char *input1 = "123456789";
const char *output = "123456789";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL); 
ck_assert_str_eq(result, output); 
free(result); 

}
END_TEST

START_TEST(to_upper7)
{
#line 55
const char *input1 = "123456{78}&90-";
const char *output = "123456{78}&90-";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL); 
ck_assert_str_eq(result, output);  
free(result); 

}
END_TEST

START_TEST(to_upper8)
{
#line 63
const char *input1 = "hello, world!";
const char *output = "HELLO, WORLD!";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL); 
ck_assert_str_eq(result, output);  
free(result); 

}
END_TEST

START_TEST(to_upper9)
{
#line 71
const char *input1 = "hello, world!";
const char *output = "HELLO, WORLD!";
char *result = s21_to_upper(input1);
ck_assert_ptr_ne(result, s21_NULL); 
ck_assert_str_eq(result, output);  
free(result); 
}
END_TEST

Suite *suite_to_upper(void)

{
    Suite *s = suite_create("to_upper");
    TCase *tc = tcase_create("to_upper_tc");
    
    tcase_add_test(tc, to_upper1);
    tcase_add_test(tc, to_upper2);
    tcase_add_test(tc, to_upper3);
    tcase_add_test(tc, to_upper4);
    tcase_add_test(tc, to_upper5);
    tcase_add_test(tc, to_upper6);
    tcase_add_test(tc, to_upper7);
    tcase_add_test(tc, to_upper8);
    tcase_add_test(tc, to_upper9);

     suite_add_tcase(s, tc);
    return s;
}