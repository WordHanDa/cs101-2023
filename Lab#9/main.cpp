#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMystring {
public:
    void replaceString(const string& str, const string& str2) {
        ifstream in("main.cpp");
        ofstream out("rmain.cpp");
        if (!in.is_open()) {
            cout << "Failed to open input file." << endl;
            return;
        }

        string line;
        while (getline(in, line)) {
            size_t pos = line.find(str);
            while (pos != string::npos) {
                line.replace(pos, str.length(), str2);
                pos = line.find(str, pos + str2.length());
            }
            out << line << endl;
        }

        in.close();
        out.close();
    }
};

int main() {
    ReplaceMystring my;
    my.replaceString("IU", "IU is the best");
    return 0;
}
