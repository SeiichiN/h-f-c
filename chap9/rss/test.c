/*
 * test.c
 * p417
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    const char *PYTHON = "/usr/bin/python3";
    const char *SCRIPT = "./rssgossip3.py";
    char *feeds[] = {
		"https://news.yahoo.com/rss/entertainment",
		"https://news.yahoo.co.jp/pickup/rss.xml",
		"http://feeds.cnn.co.jp/rss/cnn/cnn.rdf"
	};
    int times = 3;
    char *phrase = argv[1];
    int i = 0;

    printf("phrase: %s\n", phrase);

    printf("i: %i\n", i);
    char var[255];
    sprintf(var, "RSS_FEED=%s", feeds[i]);
    printf("var: %s\n", var);
    char *vars[] = {var, NULL};

    
    if (execle (PYTHON, PYTHON, SCRIPT, phrase, NULL, vars ) == -1) {
        error("Can't run script");
    }
    
    return 0;
}

    
