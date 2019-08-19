/*
 * test4.c
 * p412 の 4つめのリスト
 *
 * 出力 -- ./coffee と donuts
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *my_env[] = {"FOOD=donuts", NULL};
    if (execle("./coffee", "./coffee", NULL, my_env) == -1) {
        fprintf(stderr, "プロセス0 を実行できません：%s\n", strerror(errno));
        return 1;
    }

    fprintf(stderr, "注文を作成できません：%s\n", strerror(errno));

    return 0;
}

