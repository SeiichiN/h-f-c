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
  printf("\n最終得点：%i\n", SCORE);
  _________________________________;
}

int catch_signail(int sig, void (*handler)(int))
{
  struct sigaction action;
  action.sa_handler = hendler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction (sig, &action, NULL);
}

