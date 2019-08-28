/*
 * p454.c
 * p454
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig)
{
    puts("残酷な世界よさようなら・・・\n");
    exit(1);
}

/*
 * @params: int sig -- シグナル番号,
 *             SIGINT  割り込みシグナル
 *             SIGQUIT
 *          (*handler)(int) -- 割り込み時に処理させたい関数
 *             handler -- 関数のアドレス
 *             int -- その関数の引数。シグナル番号を指定。
 *
 *       man より
 *       sigaction 構造体は以下のような感じに定義される。
 *
 *           struct sigaction {
 *               void     (*sa_handler)(int);
 *               void     (*sa_sigaction)(int, siginfo_t *, void *);
 *               sigset_t   sa_mask;
 *               int        sa_flags;
 *               void     (*sa_restorer)(void);
 *           };
 *
 *      sigaction() 関数は成功すると 0 を返す。 エラーの場合、-1 を返し、 errno にエラーを示す値をセットする。
 *
 */
int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}

int main()
{
  if (catch_signal(SIGINT, diediedie) == -1) {
	fprintf(stderr, "ハンドラを設定できません");
	exit(2);
  }
  char name[30];
  printf("名前を入力してください：");
  fgets(name, 30, stdin);
  printf("こんにちは、%s さん\n", name);
  return 0;
}

