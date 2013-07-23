#include <stdio.h>

int main(int ac, char *av[]) {
    char ch = 'c';
    char c = 'a';

    char *const ptr = &ch;
    //ptr = &c;

    return 0;
}
