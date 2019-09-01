/*
 * p515.c
 * p515
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

int beers = 2000000;

void* do_stuff(void* param)
{
    long thread_no = (long)param;
    printf("スレッド番号 %ld\n", thread_no);
    return (void*)(thread_no + 1);
}

int main()
{
    pthread_t threads[20];
    long t;

    for (t = 0; t < 3; t++) {
        if (pthread_create ( &threads[t], NULL, do_stuff, (void*)t ) == -1)
            error("スレッド threads[t] を作成できません");
    }
    void* result;
    for (t = 0; t < 3; t++) {
        if (pthread_join (threads[t], &result) == -1)
            error("スレッド threads[t] をジョインできません");
        printf("スレッド %ld は %ld を返しました\n", t, (long)result);
    }
    return 0;
}
