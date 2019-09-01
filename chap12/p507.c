/*
 * p507.c
 * p507
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void* does_not(void *a)
{
    int i = 0;
    for (i = 0; i < 5; i++) {
        sleep(1);
        puts("Does not!");
    }
    return NULL;
}

void* does_too(void *a)
{
    int i = 0;
    for (i = 0; i < 5; i++) {
        sleep(1);
        puts("Does too!");
    }
    return NULL;
}

int main()
{
    pthread_t t0;
    pthread_t t1;

    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("スレッド t0 を作成できません");
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("スレッド t1 を作成できません");

    void* result;
    if (pthread_join(t0, &result) == -1)
        error("スレッド t0 をジョインできません");
    if (pthread_join(t1, &result) == -1)
        error("スレッド t1 をジョインできません");

    return 0;
}
