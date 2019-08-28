/*
 * p473.c
 * p473
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[])
{
    char *advice[] = {
        "食べる量を減らしなさい\r\n",
        "タイトなジーンズにしなさい。太って見えることはありません。\r\n",
        "一言：不適切。\r\n",
        "今日だけは正直になりなさい。「本当に」思っていることを上司に言いなさい。\r\n",
        "そのヘアスタイルは考え直した方がいいでしょう。\r\n"
    };

    int listener_d = socket (AF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)
        error("ソケットを開けません");

    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("ソケットに再利用オプションを設定できません");
    
    int c = bind (listener_d, (struct sockaddr *) &name, sizeof(name));
    if (c == -1)
        error("ソケットにバインドできません");

    if (listen (listener_d, 10) == -1)
        error("接続待ちできません");

    puts("ポート30000で 接続を待っています");

    while(1) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept (listener_d, (struct sockaddr *)&client_addr, &address_size);
        if (connect_d == -1)
            error("第2のソケットを開けません");
    
        char *msg = advice[rand() % 5];

        send (connect_d, msg, strlen(msg), 0);
        close(connect_d);
    }
    
    return 0;
}
