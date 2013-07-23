#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[]) {
    int count;
    sscanf(av[1], "-%d", &count);
    printf("count is %d, av[1] is %s\n", count, av[1]);
}
