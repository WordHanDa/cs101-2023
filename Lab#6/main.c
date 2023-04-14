#include <stdio.h>
#include <time.h>
#include <stdlib.h>
FILE *fp;
char* date() {
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t current_time = time(NULL);
    return asctime(localtime(&current_time));
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int* i) {
    if (n == 1) {
        (*i)++;
        fprintf(fp, "\n %d 1P from %c to %c %s", *i, from_rod, to_rod, date());
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod, i);
    (*i)++;
    fprintf(fp, "\n %d %dP from %c to %c %s", *i, n, from_rod, to_rod, date());
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod, i);
}

int main() {
    fp = fopen("hanoi.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    int n = 7;
    int i = 0;
    towerOfHanoi(n, 'A', 'C', 'B', &i);
    printf("\nTotal moves: %d", i);
    fclose(fp);
    return 0;
}
