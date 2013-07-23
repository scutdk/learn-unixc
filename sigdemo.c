#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    void f(int signal);
    int i;

    signal(SIGINT, f);
    for (i = 0; i < 5; i++) {
        printf("i is %d\n", i);
        sleep(2);
    }
}

void f(int signal) {
    printf("you pressed ctrl-c\n");
}
