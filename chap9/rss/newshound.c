/*
 * newshound.c
 * https://www.mkamimura.com/2014/09/c-unistdfork-idpid.html
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{

	char *feeds[] = {
        "https://news.yahoo.co.jp/pickup/rss.xml",
        "https://rss.msn.com/",
        "https://news.google.com/rss?ie=UTF-8&oe=UTF-8&topic=h&hl=en-US&gl=US&ceid=US:en"
    };
                   
    int times = 3;
    char *phrase = argv[1];
    int i;
    const char *PYTHON = "/usr/bin/python";
    const char *SCRIPT = "rssgossip.py";

    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var , "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};
        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "プロセスをフォークできません:%s\n", strerror(errno));
            return (1);
        }
        if (!pid) {
            if (execle(PYTHON, PYTHON, SCRIPT, phrase, NULL, vars) == -1) {
                fprintf(stderr, "スクリプトを実行できません:%s\n", strerror(errno));
                return (1);
            }
        }
    }

    return (0);
}
