/*
 * openurl.c
 * p446
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

    const char *BROWSER = "/usr/bin/x-www-browser";
    
    pid_t pid = fork();
    if (pid == -1)
        error("プロセスをフォークできません");
    if (!pid) {
        if (execl(BROWSER, BROWSER, url,  NULL) == -1) {
            fprintf(stderr, "スクリプトを実行できません: %s\n", strerror(errno));
        }
    }
}

int main()
{
    char *url = "http://www.billies-works.com/";
    open_url(url);

    return (0);
}
