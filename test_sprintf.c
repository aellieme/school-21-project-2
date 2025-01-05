#include "test.h"

START_TEST(sprintf1) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %f %s %u %%", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %f %s %u %%", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(sprintf2) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %f %s %u %%", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %f %s %u %%", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c % d % f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "% c % d % f % s % u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %+d %+f %s %u", 'b', -123, -123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %+d %+f %s %u", 'b', -123, -123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%1c %1d %1f %1s %1u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%1c %1d %1f %1s %1u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%2c %2d %2f %2s %2u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%2c %2d %2f %2s %2u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%3c %3d %3f %3s %3u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%3c %3d %3f %3s %3u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%4c %4d %4f %4s %4u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%4c %4d %4f %4s %4u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%5c %5d %5f %5s %5u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%5c %5d %5f %5s %5u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf11) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%10c %10d %10f %10s %10u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%10c %10d %10f %10s %10u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf12) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.5d %.5f %.5s %.5u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.5d %.5f %.5s %.5u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf13) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.10d %.10f %.10s %.10u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.10d %.10f %.10s %.10u", 'b', 123, 123.341232,
              "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf14) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.1d %.1f %.1s %.1u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.1d %.1f %.1s %.1u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf15) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.2d %.2f %.2s %.2u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.2d %.2f %.2s %.2u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.3d %.3f %.3s %.3u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.3d %.3f %.3s %.3u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %.4d %.4f %.4s %.4u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%c %.4d %.4f %.4s %.4u", 'b', 123, 123.341232, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf18) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%5c %5.5d %5.5f %5.5s %5.5u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%5c %5.5d %5.5f %5.5s %5.5u", 'b', 123, 123.341232,
              "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf19) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%10c %10.10d %10.10f %10.10s %10.10u", 'b', 123, 123.341232,
          "Stringi", 3242);
  s21_sprintf(str2, "%10c %10.10d %10.10f %10.10s %10.10u", 'b', 123,
              123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf20) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%10c %10.12d %10.12f %10.12s %10.12u", 'b', 123, 123.341232,
          "Stringi", 3242);
  s21_sprintf(str2, "%10c %10.12d %10.12f %10.12s %10.12u", 'b', 123,
              123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf21) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%12c %12.10d %12.10f %12.10s %12.10u", 'b', 123, 123.341232,
          "Stringi", 3242);
  s21_sprintf(str2, "%12c %12.10d %12.10f %12.10s %12.10u", 'b', 123,
              123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf22) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%12c % 12d % 12f %12s %12u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%12c % 12d % 12f %12s %12u", 'b', 123, 123.341232,
              "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf23) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %.7f %s %u", 'b', 123, 123.999999999, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %.7f %s %u", 'b', 123, 123.999999999, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf24) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %.2f %s %u", 'b', 123, 123.999999999, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %.2f %s %u", 'b', 123, 123.999999999, "Stringi",
              3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf25) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%10c % 10d % 10f %10s %10u", 'b', 123, 123.341232, "Stringi",
          3242);
  s21_sprintf(str2, "%10c % 10d % 10f %10s %10u", 'b', 123, 123.341232,
              "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf26) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf27) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%-12c % -12d % -12f %-12s %-12u", 'b', 123, 123.341232,
          "Stringi", 3242);
  s21_sprintf(str2, "%-12c % -12d % -12f %-12s %-12u", 'b', 123, 123.341232,
              "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf28) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%-10c % -10.12d % -10.12f %-10.12s %-10.12u", 'b', 123,
          123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%-10c % -10.12d % -10.12f %-10.12s %-10.12u", 'b', 123,
              123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf29) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%-5c % -5.10d % -5.10f %-5.10s %-5.10u", 'b', 123, 123.341232,
          "Stringi", 3242);
  s21_sprintf(str2, "%-5c % -5.10d % -5.10f %-5.10s %-5.10u", 'b', 123,
              123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf30) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %hd %f %s %hu", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %hd %f %s %hu", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf31) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %ld %f %s %lu", 'b', 123453453343, 123.341232, "Stringi",
          3245234535);
  s21_sprintf(str2, "%c %ld %f %s %lu", 'b', 123453453343, 123.341232,
              "Stringi", 3245234535);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf32) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %hd %f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %hd %f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf33) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %f %s %hu", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %f %s %hu", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf34) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%.5f", 123.3412322432423);
  s21_sprintf(str2, "%.5f", 123.3412322432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf35) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%.10f", 123.3412322432423);
  s21_sprintf(str2, "%.10f", 123.3412322432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf36) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%.15f", 123.3412322432423);
  s21_sprintf(str2, "%.15f", 123.3412322432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf37) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%.f", 123.3412322432423);
  s21_sprintf(str2, "%.f", 123.3412322432423);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf38) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%.f", 123.9999999);
  s21_sprintf(str2, "%.f", 123.9999999);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf39) {
  char str1[100] = "";
  char str2[100] = "";
  sprintf(str1, "%c %d %f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  s21_sprintf(str2, "%c %d %f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf40) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%10c % 10d % 10f %10s %10u", 'b', 123, 123.341232,
                  "Stringi", 3242);
  int b = s21_sprintf(str2, "%10c % 10d % 10f %10s %10u", 'b', 123, 123.341232,
                      "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf41) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%c %.5d %.5f %.5s %.5u", 'b', 123, 123.341232,
                  "Stringi", 3242);
  int b = s21_sprintf(str2, "%c %.5d %.5f %.5s %.5u", 'b', 123, 123.341232,
                      "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf42) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%-10c % -10.12d % -10.12f %-10.12s %-10.12u", 'b', 123,
                  123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%-10c % -10.12d % -10.12f %-10.12s %-10.12u", 'b',
                      123, 123.341232, "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf43) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%10c %10d %10f %10s %10u", 'b', 123, 123.341232,
                  "Stringi", 3242);
  int b = s21_sprintf(str2, "%10c %10d %10f %10s %10u", 'b', 123, 123.341232,
                      "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf44) {
  char str1[100] = "";
  char str2[100] = "";
  int a =
      sprintf(str1, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%c %+d %+f %s %u", 'b', 123, 123.341232, "Stringi",
                      3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf45) {
  char str1[100] = "";
  char str2[100] = "";
  int a =
      sprintf(str1, "%c %d %f %s %u", 'b', 123, 123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%c %d %f %s %u", 'b', 123, 123.341232, "Stringi",
                      3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf46) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%3c %3d %3f %3s %3u", 'b', 123, 123.341232, "Stringi",
                  3242);
  int b = s21_sprintf(str2, "%3c %3d %3f %3s %3u", 'b', 123, 123.341232,
                      "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf47) {
  char str1[100] = "";
  char str2[100] = "";
  int a =
      sprintf(str1, "%c %d %f %s %hu", 'b', 123, 123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%c %d %f %s %hu", 'b', 123, 123.341232, "Stringi",
                      3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf48) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%.10f", 123.3412322432423);
  int b = s21_sprintf(str2, "%.10f", 123.3412322432423);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf49) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%-5c % -5.10d % -5.10f %-5.10s %-5.10u", 'b', 123,
                  123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%-5c % -5.10d % -5.10f %-5.10s % -5.10u", 'b', 123,
                      123.341232, "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf50) {
  char str1[100] = "";
  char str2[100] = "";
  int a = sprintf(str1, "%10c %10.12d %10.12f %10.12s %10.12u", 'b', 123,
                  123.341232, "Stringi", 3242);
  int b = s21_sprintf(str2, "%10c %10.12d %10.12f %10.12s %10.12u", 'b', 123,
                      123.341232, "Stringi", 3242);
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc1_1 = tcase_create("sprintf");
  tcase_add_test(tc1_1, sprintf1);
  tcase_add_test(tc1_1, sprintf2);
  tcase_add_test(tc1_1, sprintf3);
  tcase_add_test(tc1_1, sprintf4);
  tcase_add_test(tc1_1, sprintf5);
  tcase_add_test(tc1_1, sprintf6);
  tcase_add_test(tc1_1, sprintf7);
  tcase_add_test(tc1_1, sprintf8);
  tcase_add_test(tc1_1, sprintf9);
  tcase_add_test(tc1_1, sprintf10);
  tcase_add_test(tc1_1, sprintf11);
  tcase_add_test(tc1_1, sprintf12);
  tcase_add_test(tc1_1, sprintf13);
  tcase_add_test(tc1_1, sprintf14);
  tcase_add_test(tc1_1, sprintf15);
  tcase_add_test(tc1_1, sprintf16);
  tcase_add_test(tc1_1, sprintf17);
  tcase_add_test(tc1_1, sprintf18);
  tcase_add_test(tc1_1, sprintf19);
  tcase_add_test(tc1_1, sprintf20);
  tcase_add_test(tc1_1, sprintf21);
  tcase_add_test(tc1_1, sprintf22);
  tcase_add_test(tc1_1, sprintf23);
  tcase_add_test(tc1_1, sprintf24);
  tcase_add_test(tc1_1, sprintf25);
  tcase_add_test(tc1_1, sprintf26);
  tcase_add_test(tc1_1, sprintf27);
  tcase_add_test(tc1_1, sprintf28);
  tcase_add_test(tc1_1, sprintf29);
  tcase_add_test(tc1_1, sprintf30);
  tcase_add_test(tc1_1, sprintf31);
  tcase_add_test(tc1_1, sprintf32);
  tcase_add_test(tc1_1, sprintf33);
  tcase_add_test(tc1_1, sprintf34);
  tcase_add_test(tc1_1, sprintf35);
  tcase_add_test(tc1_1, sprintf36);
  tcase_add_test(tc1_1, sprintf37);
  tcase_add_test(tc1_1, sprintf38);
  tcase_add_test(tc1_1, sprintf39);
  tcase_add_test(tc1_1, sprintf40);
  tcase_add_test(tc1_1, sprintf41);
  tcase_add_test(tc1_1, sprintf42);
  tcase_add_test(tc1_1, sprintf43);
  tcase_add_test(tc1_1, sprintf44);
  tcase_add_test(tc1_1, sprintf45);
  tcase_add_test(tc1_1, sprintf46);
  tcase_add_test(tc1_1, sprintf47);
  tcase_add_test(tc1_1, sprintf48);
  tcase_add_test(tc1_1, sprintf49);
  tcase_add_test(tc1_1, sprintf50);
  suite_add_tcase(s, tc1_1);
  return s;
}
