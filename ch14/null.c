#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p = malloc(sizeof(int));
    p = NULL;
    free(p);
    return 0;
}