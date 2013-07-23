#include <stdio.h>

int main(int ac, char *av[]) {
    int arr[] = {1, 2, 5, 0, -1};
    printf("the addr of arr is %d, an the addr of the first element is %d\n", &arr, arr);
    
    return 0;
}
