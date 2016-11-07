#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[30];
};

int main() {
  struct my_msgbuf buf;
  int msqid;
  key_t key;

  if ((key = ftok("./dat/msgq.dat", 'b')) == -1) {
    perror("ftok");
    exit(1);
  }

  if ((msqid = msgget(key, 0644)) == -1) {
    perror("msgget");
    exit(1);
  }

  printf("queue: ready to receive messages.\n");
  for(;;) {
    if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
      perror("msgrcv");
      exit(1);
    }
    printf("queue: \"%s\"\n", buf.mtext);
  }

  return 0;
}

