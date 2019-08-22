/*
 * newshound.c
 * p417
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *feeds[] = {"https://news.yahoo.co.jp/pickup/rss.xml",
                    "http://feeds.cnn.co.jp/rss/cnn/cnn.rdf",
                     "http://www.billies-works.com/feed/"};
    int times = 3;
    char *phrase = argv[1];
    int i;
    const char *PYTHON = "/usr/bin/python";
    const char *SCRIPT = "rssgossip.py";

    printf("phrase: %s\n", phrase);

    for (i = 0; i < times; i++) {
        char var[255];
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        printf("%s\n", var);
        char *vars[] = {var, NULL};
        if ( execle (PYTHON, PYTHON, SCRIPT, phrase, NULL, vars ) == -1) {
            fprintf(stderr, "スクリプトを実行できません：%s\n", strerror(errno));
            return 1;
        }
    }
    return 0;
}

    
