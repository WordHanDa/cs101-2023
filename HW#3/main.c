#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 7
int generateRandomNumber(int previous) {
    int num=rand()%69+1;
    while (num==previous){num=rand()%69+1;}
    return num;
}
void generateRandomArray(int arr[]){
    int previous = 0;
    for(int i=0; i<ARRAY_SIZE-1; i++){arr[i]=generateRandomNumber(previous=arr[i]);}
    arr[ARRAY_SIZE-1]=rand()%10+1;
}
char* date(){
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t current_time=time(NULL);
    return asctime(localtime(&current_time));
}
int file_Count(){
    char str[] = "1";
    char string[100];
    FILE*wfp = fopen("record.bin", "ab+");
    fwrite(str, strlen(str), 1, wfp);
    fclose(wfp);
    FILE*rfp = fopen("record.bin", "r");
    fgets(string, 100, rfp);
    fclose(rfp);
    return strlen(string);
}
int main(){
    char lotto[1000];
    srand(time(NULL));
    int arr[ARRAY_SIZE],x,j,k;
    FILE*fp=fopen("lotto.txt","w");
    scanf("%d",&x);
    printf("已為您購買的%d組樂透組合輸出至lotto.txt\n",x);
    fprintf(fp,"======+ NO.%05d +======\n========lotto649========\n%s",file_Count(),date());
    for(j=0; j<x; j++){
        generateRandomArray(arr);
        fprintf(fp,"[%d]: ", j+1);
        for(int i = 0; i<ARRAY_SIZE; i++) {fprintf(fp,"%02d ", arr[i]);}
        fprintf(fp,"\n");
    }
    for(k=j; k<5;k++){fprintf(fp,"[%d]: -- -- -- -- -- -- --\n", k+1);}
    fprintf(fp,"========csie@cgu========");
    fclose(fp);
}
