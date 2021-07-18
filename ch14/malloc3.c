#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(100 * sizeof(int));
    data[0] = 1024;
    free(data);
    printf("%d\n",data[0]);
    return 0;
}