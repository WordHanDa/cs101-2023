/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 7
int generateRandomNumber(int previous) {
    int num = rand() % 69 + 1;
    while (num == previous) {num = rand() % 69 + 1;}
    return num;
}
void generateRandomArray(int arr[]) {
    int previous = 0;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        arr[i] = generateRandomNumber(previous);
        previous = arr[i];
    }
    arr[ARRAY_SIZE - 1] = rand() % 10 + 1;
}
char* date(){
    char timezone[] = "TZ=Asia/Taipei";
    putenv(timezone);
    tzset();
    time_t current_time;
    struct tm *local_time;
    current_time = time(NULL);
    local_time = localtime(&current_time);
    return asctime(local_time);
}
int main()
{
    char lotto[1000];
    srand(time(NULL));
    int arr[ARRAY_SIZE],x;
    FILE*fp=fopen("lotto.txt","w");
    printf("歡迎光臨長庚樂透購買機台\n請問您要買幾組樂透彩:");
    scanf("%d",&x);
    printf("已為您購買的 %d 組樂透組合輸出至lotto.txt\n",x);
    fprintf(fp,"========lotto649========\n");
    fprintf(fp,"%s",date());
    for(int i = 0; i < x; i++) {
        generateRandomArray(arr);
        for(int i = 0; i < ARRAY_SIZE; i++) {printf("%d ", arr[i]);}
        printf("\n");
    }
    fclose(fp);
    return 0;
}
