/*
 * turtle.c
 * p236
 */

#include <stdio.h>

typedef struct {
    const char *name;
    const char *spesies;
    int age;
} turtle;

void happy_birthday(turtle *t)
{
    t->age = t->age + 1;
    printf("誕生日おめでとう、%s！ これで %i 才ですね！\n",
           t->name, t->age);
}

int main()
{
    turtle myrtle = {"マートル", "オサガメ", 99};
    happy_birthday(&myrtle);
    printf("%s の年齢は %i 才です\n", myrtle.name, myrtle.age);

    return 0;
}
