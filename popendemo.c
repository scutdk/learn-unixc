#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0;
    char buf[100];
    
    FILE * fp;
    fp = popen("last | sort", "r");
    while (fgets(buf, 100, fp) != NULL) {
        printf("%3d %s", i++, buf);
    }
    pclose(fp);

    return 0;
}

