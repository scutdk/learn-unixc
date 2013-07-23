#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


void usage(const char *str);
int main(int ac, char *av[]) {
    int fd;
    int nlines;
    int cnt = 0;
    char buf[BUFSIZ];
    int offset = -BUFSIZ;
    int rlen;
    int total = 0;
    int curp = 0;
    /*
    while (ac-- > 0) {
        printf("%s\n", *av++);
    }
    */
    if (*++av && av[0][0] == '-') {
        if (!sscanf(*av, "-%d\0", &nlines)) 
            usage("invalid args");
    } else {
        nlines = 10;
    }

    printf("file name is %s\n", *++av);
    fd = open(*av, O_RDONLY);
    if (fd == -1) {
        perror(*av);
        exit(2);
    }

    lseek(fd, offset, SEEK_END);
    /*
    while (read(fd, buf, BUFSIZ)) {
        printf("%s", buf);
    }
    */
    rlen = read(fd, buf, BUFSIZ);
    printf("%d %c %cheh\n", rlen, buf[BUFSIZ-2], buf[BUFSIZ-1]);
    while (rlen-- > 0) {
        if (buf[curp++] == '\n') {
            total++;
        }
    }
    printf("%s", buf);


    printf("%d %d\n", total, nlines);

    return 0;

}

void usage(const char *str) {
    printf("%s\n", str);
    exit(1);
}
