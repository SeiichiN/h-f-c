/*
 * test3.c
 * p412 の 3つめのリスト
 *
 * 出力 -- ./coffee と ./coffee
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (execl("./coffee", "./coffee", NULL) == -1) {
        fprintf(stderr, "プロセス0 を実行できません：%s\n", strerror(errno));
        return 1;
    }

    fprintf(stderr, "注文を作成できません：%s\n", strerror(errno));

    return 0;
}

