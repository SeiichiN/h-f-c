/*
 * catalog.c
 * p228
 */

#include <stdio.h>

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void label(struct fish a)
{
    printf("名前：%s\n種類：%s\n%i 本の歯、%i 才 \n",
           a.name, a.species, a.teeth, a.age);
    printf("餌は %2.2f キロの %s を与え、%s を %2.2f 時間行わせます \n",
           a.care.food.weight, a.care.food.ingredients,
           a.care.exercise.description, a.care.exercise.duration);
}

int main()
{
    struct fish snappy = {"スナッピー", "ピラニア", 69, 4,
                          {{"肉", 0.10},
                           {"ジャグジーでの泳ぎ", 7.50}}};

    label(snappy);

    return 0;
}
