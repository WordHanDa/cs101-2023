/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int multi(int i,int j){
        if(j==1){
            printf("%d*%d=%d ",i,j,i*j);
            return 0;
        }else{
            multi(i,j-1);
            printf("%d*%d=%d ",i,j,i*j);
        }
        if()
        //multi(i-1,j);
}
int main(){
    multi(9,9);
    return 0;
}
