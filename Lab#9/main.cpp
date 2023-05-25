#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMystring{
    public:
    void replaceString(string str,string str2){
        ifstream in("main.cpp");
        ofstream out("rmain.cpp");
        string line;
        while (getline(in, line)){
            out << line << endl;
        }
        in.close();
        out.close();
    }
};

int main()
{
    ReplaceMystring my;
    my.replaceString("IU","IU is best");
    return 0;
}