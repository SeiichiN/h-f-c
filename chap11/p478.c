/*
 * p478.c
 * p478
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}

int listener_d;
void handle_shutdown(int sig)
{
    if (listener_d)
        close(listener_d);

    fprintf(stderr, "\nさようなら！\n");
    exit(0);
}

int read_in(int socket, char *buf, int len)
{
  char *s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);

  while ((c > 0) && (s[c-1] != '\n')) {
	s += c;
	slen -= c;
	c = recv(socket, s, slen, 0);
  }
  if (c < 0)
	return c;
  else if (c == 0)
	buf[0] = '\0';
  else
	s[c-1] = '\0';
  return len - slen;
}

int open_listener_socket()
{
    int s = socket (PF_INET, SOCK_STREAM, 0);
    if (s == -1)
        error("ソケットを開けません");
	return s;
}

void bind_to_port(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("ソケットに再利用オプションを設定できません");
    
    int c = bind (socket, (struct sockaddr *) &name, sizeof(name));
    if (c == -1)
        error("ソケットにバインドできません");
}

int say(int socket, char *s)
{
    int result = send (socket, s, strlen(s), 0);
	if (result == -1)
	  fprintf(stderr, "%s: %s\n", "クライアントとの通信エラー", strerror(errno));
	return result;
}

int main(int argc, char *argv[])
{
    catch_signal(SIGINT, handle_shutdown);

    int PORT = 30000;
    char *res[] = {
        "> コン！コン！\r\n",
        "> オスカー\r\n",
        "> オスカーシリーな（くだらない）質問をすると、くだらない答えが返ってきます\r\n",
        "> 期待したことばと違います\r\n"
    };

	char *cli[] = {
	  "だれですか？\r",
	  "オスカー？\r",
	};

    /*
    char *cli[] = {
        "who's there?\r",
        "oscar who?"
    };
    */

    listener_d = open_listener_socket();

	bind_to_port(listener_d, PORT);

    if (listen (listener_d, 10) == -1)
        error("接続待ちできません");

    puts("ポート30000で 接続を待っています");

    
    while(1) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        int connect_d = accept (listener_d, (struct sockaddr *)&client_addr, &address_size);
        if (connect_d == -1)
            error("第2のソケットを開けません");
    
		char rec_msg[255];
        /*
        char *msg = res[0];
		char *send_msg1 = cli[0];
		char *send_msg2 = cli[1];
        */
        
        say(connect_d, res[0]);

        while(1) {
            read_in(connect_d, rec_msg, sizeof(rec_msg));

            printf("client> %s\n", rec_msg);
            printf("server> %s\n", cli[0]);
            printf("strcmp: %i\n", strcmp(rec_msg, cli[0]));
            
            if (strcmp(rec_msg, cli[0]) == 0) {
                say(connect_d, res[1]);
            } else if (strcmp(rec_msg, cli[1]) == 0) {
                say(connect_d, res[2]);
                break;
            } else {
                say(connect_d, res[3]);
                break;
            }
        }

        close(connect_d);
    }
    
    return 0;
}
