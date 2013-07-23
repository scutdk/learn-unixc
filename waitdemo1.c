#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

#define DELAY 2

int main(void) {
    int newpid;
    void child_code(), parent_code();

    printf("Before fork(), my pid is %d\n", getpid());

    if ((newpid = fork()) == -1) 
        perror("for error");
    else if (newpid == 0)
        child_code(DELAY);
    else
        parent_code(newpid);
}

void child_code(int delay) {
    printf("this is child, will sleep for %d seconds\n", delay);
    sleep(delay);
    printf("About to exit program\n");
    exit(17);
}

void parent_code(int childpid) {
    int rv;
    rv = wait(NULL);
    printf("Done waiting for %d. Wait returned %d\n", childpid, rv);
}
