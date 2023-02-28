/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char a[]="Hello";
    int len=0;
    while(a[len]!='\0'){len++;}
    printf("a = ");
    for(int i=0; i<=len; i++){printf("%c",a[i]);}
    printf("\na = ");
    a[0]=a[0]+' ';
    a[len-1]=a[len-1]-' ';
    for(int i=len; i>=0; i--){printf("%c",a[i]);}
    return 0;
}
