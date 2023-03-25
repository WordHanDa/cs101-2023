#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 7
typedef struct lottery {
    int receipt_id;
    int receipt_price;
    int lotto_set[5][7];
    char receipt_time[32];
} lotto_record_t;
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
char* date() {
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t current_time = time(NULL);
    return asctime(localtime(&current_time));
}
int file_Count() {
    int count = 1;
    FILE* fp = fopen("record.bin", "rb+");
    if (!fp) {
        fp = fopen("record.bin", "wb+");
        if (!fp) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fwrite(&count, sizeof(count), 1, fp);
    } else {
        fread(&count, sizeof(count), 1, fp);
        ++count;
        fseek(fp, 0, SEEK_SET);
        fwrite(&count, sizeof(count), 1, fp);
    }
    fclose(fp);
    return count;
}
void write_record_to_file(lotto_record_t record) {
    FILE* fp = fopen("record.bin", "ab+");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(&record, sizeof(lotto_record_t), 1, fp);
    fclose(fp);
}
void generate_lotto(int x){
    char lotto[1000];
    int count=file_Count();
    srand(time(NULL));
    int arr[ARRAY_SIZE],j,k;
    lotto_record_t record;
    FILE*fp=fopen("lotto.txt","w");
    strcpy(record.receipt_time, date());
    fprintf(fp,"========lotto649=========\n======+ NO.%05d +=======\n%s",count, record.receipt_time);
    for(j=0; j<x; j++){
        generateRandomArray(arr);
        fprintf(fp,"[%d]: ", j+1);
        for(int i = 0; i<ARRAY_SIZE; i++) {
            fprintf(fp,"%02d ", arr[i]);
            record.lotto_set[j][i] = arr[i];
        }
        fprintf(fp,"\n");
    }
    for(k=j; k<5;k++){
    fprintf(fp,"[%d]: -- -- -- -- -- -- --\n", k+1);
        memset(record.lotto_set[k], 0, sizeof(record.lotto_set[k]));
    }
    fprintf(fp,"========csie@cgu=========");
    record.receipt_price = x*100;
    record.receipt_id = count;
    write_record_to_file(record);
    fclose(fp);
}
void winning_lotto(int winning_number){
    FILE*fp=fopen("record.bin","r");
    
}
int main() {
    int x,winning_numbers[3];
    printf("請問你要買幾組樂透彩：");
    scanf("%d", &x);
    if (!x) {
        printf("請輸入中獎號碼（最多3個）：");
        for (int i = 0; i < 3; i++) scanf(" %d", &winning_numbers[i]);
        printf("輸入中獎號碼為：");
        for (int i = 0; i < 3; i++) printf("%02d ",winning_numbers[i]);
        printf("\n以下為中獎彩卷：\n");
        for (int i = 0; i < 3; i++) winning_lotto(winning_numbers[i]);
        
    }else if(x<6) {
        printf("已為您購買的%d組樂透組合輸出至lotto.txt\n", x);
        generate_lotto(x);
    }else{
        printf("最多只能買5組");
    }
    return 0;
}