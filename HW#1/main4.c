/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void filter(char *a){
    int len = 0;
    int n=0;
    while (a[len] != '\0') {len++;}
    for(int i=0; i<len-1; i++){
        if(a[i]<='9'){printf("%c",a[i]);}
    }
}

int main()
{
    char a[]="x-99acbc";
    filter(a);
}
