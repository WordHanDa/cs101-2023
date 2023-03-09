/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[]={1,2,3};
    char b[]="ABC";
    float c[] = {1.1, 1.2, 1.3 };
    FILE*fp;
    if((fp=fopen("a.bin","wb+"))==NULL){
        printf("Cannot open the file...");
        exit(1);
    }
    if(fwrite(a,sizeof(a),1,fp)!=1){
        printf("File write erro...\n");
    }
    fseek(fp,0,SEEK_SET);
    
    if(fread(a,sizeof(a),1,fp)!=1){
        printf("File read erro...\n");
    }
    //-----------------------------------
    if((fp=fopen("a.bin","wb+"))==NULL){
        printf("Cannot open the file...");
        exit(1);
    }
    if(fwrite(b,sizeof(b),1,fp)!=1){
        printf("File write erro...\n");
    }
    fseek(fp,0,SEEK_SET);
    
    if(fread(b,sizeof(b),1,fp)!=1){
        printf("File read erro...\n");
    }
    //-----------------------------------
    if((fp=fopen("a.bin","wb+"))==NULL){
        printf("Cannot open the file...");
        exit(1);
    }
    if(fwrite(c,sizeof(c),1,fp)!=1){
        printf("File write erro...\n");
    }
    fseek(fp,0,SEEK_SET);
    
    if(fread(c,sizeof(c),1,fp)!=1){
        printf("File read erro...\n");
    }

    return 0;
}
