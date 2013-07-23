#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(void)
{
    int i;
    int pid = getpid();
    for(i=0; i<2; i++){
        fork();
        printf("-");
    }
    sleep(2);
 
    if (getpid() == pid) 
        wait(NULL);

    return 0;
}
