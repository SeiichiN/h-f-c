/*
 * news_opener.c
 * p447
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void open_url(char *url)
{
    /*
    char launch[255];

    sprintf(launch, "cmd /c start %s", url);
    system(launch);

    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);

    sprintf(launch, "open '%s'", url);
    system(launch);
    */

    const char *READER = "/usr/bin/wget";

	char link[510];
	sprintf(link, "%s", url);
    
    pid_t pid = fork();
    if (pid == -1)
        error("プロセスをフォークできません");
    if (!pid) {
        if (execl(READER, READER,  url, NULL) == -1) {
            fprintf(stderr, "スクリプトを実行できません: %s\n", strerror(errno));
        }
    }
}

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
	/* char *vars[] = {"RSS_FEED=https://rss.msn.com/", NULL}; */
    char *vars[] = {"RSS_FEED=https://news.yahoo.co.jp/pickup/rss.xml", NULL};
    const char *PYTHON = "/usr/bin/python";
    const char *SCRIPT = "./rssgossip.py";
    
    int fd[2];
    if (pipe(fd) == -1) {
        error("パイプを作成できません");
    }

    pid_t pid = fork();
    if (pid == -1) {
        error("プロセスをフォークできません");
    }
    if (!pid) {
        close(fd[0]);  /* fd[0] -- パイプの読み込み側。 */
        dup2(fd[1], 1);  /* パイプの書き込み側を標準出力にコピー。 */
        /* これにより、出力内容がパイプに書き込まれる。 */
        if (execle(PYTHON, PYTHON, SCRIPT, "-u", phrase, NULL, vars) == -1) {
            error("スクリプトを実行できません");
        }
    }
    close(fd[1]);  /* パイプの書き込み側を閉じる。 */
    dup2(fd[0], 0);  /* パイプの読み込み側を標準入力にコピー。 */
    /* これにより、パイプからの内容が標準入力に書き込まれる。 */
    char line[510];
    while (fgets(line, 510, stdin) != NULL) {
        if (line[0] == '\t'){
		  printf("line: %s\n", line + 1);
		  open_url(line + 1);
		}
    }
    return 0;
}
