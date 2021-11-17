#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int cpid1, cpid2;
    srand(time(NULL));

    printf("Parent pid: %d\n", getpid());

    cpid1 = fork();
    if(cpid1) {
        cpid2 = fork();
        rand();
    }
    if(cpid1 && cpid2) {
        int status;
        int c = wait(&status);
        printf("Child %d was asleep for %d seconds\n", c, WEXITSTATUS(status));
        printf("Parent done\n");

        return 0;
    } else {
        printf("Child pid: %d\n", getpid());
        int time = 2 + rand() % 3;
        sleep(time);
        printf("Child %d awake\n", getpid());

        return time;
    }

    return 0;
}