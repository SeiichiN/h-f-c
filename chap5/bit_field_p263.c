/*
 * bit_field_p263.c
 * p263
 */

#include <stdio.h>

typedef struct {
    unsigned int first_visit:1;
    unsigned int come_again:1;
    unsigned int fingers_lost:4;
    unsigned int shark_attack:1;
    unsigned int days_a week:3;
} survey;
