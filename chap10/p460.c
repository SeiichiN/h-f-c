/*
 * p460.c
 * p460
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig)
{
  printf("\n最終得点：%i\n", score);
  exit(0);   /* 終了状態 0 に設定 */
}

int catch_signal(int sig, void (*handler)(int))
{
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction (sig, &action, NULL);
}

void times_up(int sig)
{
  puts("\n時間切れ！");
  raise(SIGINT);  /* そのプロセス自体にシグナルを送る */
}

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main()
{
  catch_signal(SIGALRM, times_up );
  catch_signal(SIGINT,  end_game );
  srandom (time (0));   /* 毎回異なる乱数が得られるようにする */
  while(1) {
	int a = random() % 11;
	int b = random() % 11;
	char txt[4];
	alarm(5);
	printf("\n%i かける %i は いくつですか？", a, b);
	fgets(txt, 4, stdin);
	int answer = atoi(txt);
	if (answer == a * b)
	  score++;
	else
	  printf("\n間違いです！得点：%i\n", score);
  }
  return 0;
}

