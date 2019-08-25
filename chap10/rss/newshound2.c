/*
 * newshound2.c
 * p435
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{

    char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=https://rss.msn.com/", NULL };
    FILE *f = fopen("stories.txt", "w");
    if (!f) {
        error("stories.txtを開けません");
    }

    const char *PYTHON = "/usr/bin/python";
    const char *SCRIPT = "rssgossip.py";

    pid_t pid = fork();
    if (pid == -1) {
        error("プロセスをフォークできません");
    }
    if (!pid) {
        if (dup2(fileno(f), 1) == -1) {
            error("標準出力をリダイレクトできません");
        }
        if (execle(PYTHON, PYTHON, SCRIPT, phrase, NULL, vars) == -1) {
            fprintf(stderr, "スクリプトを実行できません:%s\n", strerror(errno));
            return (1);
        }
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("子プロセスの待機エラー");
    }
    
    return (0);
}
