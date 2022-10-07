#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void simpleSystem(const char *command) {
  pid_t pid;
  int status;

  pid = fork();

  if (pid < 0) {
    exit(1);
  } else if (pid == 0) {
    execl("/bin/bash", "bash", "-c", command, (char *)NULL);
    exit(0);
  } else {
    waitpid(pid, &status, 0);
  }
}

int main(void) {
  while (1) {
    char command[80];
    printf(">");
    fgets(command, 80, stdin);
    simpleSystem(command);
  }
}
