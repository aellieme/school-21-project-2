#include "test.h"

#include "../s21_string.h"

int main(void) {
    int number_failed = 0;
    Suite *s[] = {
        suite_memchr(), suite_memcmp(), suite_memcpy(),suite_memset(), suite_strncat(), suite_strcspn(), suite_strchr(),suite_strncmp(),
        suite_strncpy(), suite_strerror(), suite_strlen(),suite_strpbrk(),suite_strrchr(),suite_strstr(), 
        suite_strtok(), suite_to_upper(), suite_to_lower(),
        suite_insert(), suite_trim(),//suite_sprintf(),

        s21_NULL
    };

    for (int i = 0; s[i] != NULL; i++) {
        SRunner *sr = srunner_create(s[i]);
        srunner_run_all(sr, CK_NORMAL);
        number_failed += srunner_ntests_failed(sr);
        srunner_free(sr);
    }
    
    return (number_failed == 0) ? 0 : 1;
}