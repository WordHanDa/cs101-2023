/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMystring{
    public:
    void replaceString(string& str){
        ifstream in;
    ofstream out;
    char str;
    in.open("main.cpp");
    out.open("rmain.cpp");
    while(!in.eof()){
        in>>str;
        if(in.fail()){
            
        }
        out << str << endl;
            if(str=='\n'){
                out << endl;
            }
    }
    }
};
int main()
{
    ReplaceMystring my;
    my.replaceString("IU","IU is best");
    return 0;
}