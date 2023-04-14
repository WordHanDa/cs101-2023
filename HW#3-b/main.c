#include <stdio.h>

typedef struct my_mm {
    int size;
    char* start;
} my_mm_t;

int g_mem[10];
my_mm_t mms[10] = {{0}};

char* my_calloc(int n, int size) {
    for (int i = 0; i < 10; i++) {
        if (mms[i].start) {
            int mem_size = n * size;
            if (mem_size > (10 - i) * sizeof(int)) {
                printf("Insufficient memory\n");
                return NULL;
            }
            char* ptr = (char*)&g_mem[i];
            mms[i].size = mem_size;
            mms[i].start = ptr;
            for (int j = 0; j < mem_size; j++) {
                *(ptr + j) = 0;
            }
            printf("1100000000\n");
            return ptr;
        }
    }
    printf("Insufficient memory\n");
    return NULL;
}

void my_free(char* p) {
    for (int i = 0; i < 10; i++) {
        if (p == mms[i].start) {
            mms[i].start = NULL;
            printf("1100000000\n");
            return;
        }
    }
    printf("Invalid pointer\n");
}

int main() {
    int* np1 = (int*)my_calloc(1, sizeof(int));
    int* np2 = (int*)my_calloc(1, sizeof(int)*2);
    int* np3 = (int*)my_calloc(1, sizeof(int)*3);
    int* np4 = (int*)my_calloc(1, sizeof(int)*4);
    my_free((char*)np1);
    my_free((char*)np4);
    int* np5 = (int*)my_calloc(1, sizeof(int)*3);
    return 0;
}