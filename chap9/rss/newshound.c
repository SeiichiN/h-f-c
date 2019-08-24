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
        "http://www.billies-works.com/feed/",
        "http://rss.cnn.com/rss/edition_world.rss",
        "http://rss.cnn.com/rss/edition_americas.rss"
    };

/*
    char *feeds[] = {
        "http://rss.cnn.com/rss/edition.rss",
        "http://rss.cnn.com/rss/edition_world.rss",
        "http://rss.cnn.com/rss/edition_africa.rss",
        "http://rss.cnn.com/rss/edition_americas.rss",
        "http://rss.cnn.com/rss/edition_asia.rss",
        "http://rss.cnn.com/rss/edition_europe.rss",
        "http://rss.cnn.com/rss/edition_meast.rss",
        "http://rss.cnn.com/rss/edition_us.rss"
    };
*/
                   
    int times = 1;
    char *phrase = argv[1];
    int i;
    const char *PYTHON = "/usr/bin/python3";
    const char *SCRIPT = "rssgossip3.py";

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
