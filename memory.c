#include <stdio.h>
#include <stdlib.h>

int gv1 = 1;
int gv2 = 2;
int gv3 = 3;
int gv4 = 4;

void memory(int count,char overflow) {
    int stackV = count;
    printf("Stack variable address (level %d): %p\n", count, &stackV);

    int* heapV = (int*)malloc(sizeof(int));
    *heapV = count;
    printf("Heap variable address (level %d): %p\n", count, heapV);

    if (overflow == 'y') {
        //overflow
        memory(count + 1, overflow);
    }
    else {
        if (count < 3) {
        memory(count + 1, overflow);
        }
    }

    free(heapV);
}

int main() {
    printf("Global variable 1 address: %p\n", &gv1);
    printf("Global variable 2 address: %p\n", &gv2);
    printf("Global variable 3 address: %p\n", &gv3);
    printf("Global variable 4 address: %p\n", &gv4);

    char overflow;
    printf("Show overflow? (y/n): ");
    scanf("%c", &overflow);
    memory(1, overflow);
    return 0;
}
