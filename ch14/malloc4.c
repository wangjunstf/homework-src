#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(100 * sizeof(int));
    data[5] = 1024;
    free(data[5]);
    //printf("%d\n", data[5]);
    return 0;
}