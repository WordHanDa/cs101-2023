/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef int (*calc_func)(int,int);
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int div(int a,int b){
    return a/b;
}
int calc(calc_func func_ptr,int a,int b){
    return func_ptr(a, b);
}
int main(){
    printf("sum = %d\n",calc(add,4,2));
    printf("dif = %d\n",calc(sub,4,2));
    printf("product = %d\n",calc(mul,4,2));
    printf("quotient = %d\n",calc(div,4,2));
    return 0;
}
