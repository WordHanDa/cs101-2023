#include <iostream>
#include <limits>
using namespace std;
class input{
    private:
        int x,y;
        bool player=true;
    public:
        char matrix[3][3];
        void playerInput(){
            while(true){
                cin>>x>>y;
                if(cin.fail()){
                    cout<<"Please enter integers only."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    continue;
                }
                if(x<1||x>3||y<1||y>3){
                    cout<<"Please enter valid coordinates (1-3)."<<endl;
                    continue;
                }
                if(matrix[y-1][x-1]){
                    cout << "This spot is already taken. Please choose another spot." << endl;
                    continue;
                }
                matrix[y-1][x-1]=(player)?'X':'O';
                player=!player;
                break;
            }
        }
        void checkerboard_builder(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    char str=(matrix[i][j]=='X'||matrix[i][j]=='O')?matrix[i][j]:' ';
                    cout << str << "|";
                }
                cout <<endl;
            }
        }
};

class TicTacToe:input{
    private:
        int n=0;
        bool win=false;
    public:
        void checkWin(){
            char symbols[2]={'X','O'};
                for(char sym:symbols){
                    for(int i=0;i<3;i++){
                        if((matrix[i][0]==sym&&matrix[i][1]==sym&&matrix[i][2]==sym)||  // 水平檢查
                           (matrix[0][i]==sym&&matrix[1][i]==sym&&matrix[2][i]==sym)) {   // 垂直檢查
                            win=true;
                            break;
                        }
                    }
                    if((matrix[0][0]==sym&&matrix[1][1]==sym&&matrix[2][2]==sym)||      // 對角線檢查
                       (matrix[0][2]==sym&&matrix[1][1]==sym&&matrix[2][0]==sym)){
                        win=true;
                    }
                if(win){
                    cout<<"Player "<<(sym=='X'?"1":"2")<<" wins"<< endl;
                    return;
                }
            }
        }
        void run(){
            while(n<9&&!win){
                playerInput();
                checkerboard_builder();
                checkWin();
                n++;
            }
        }
};

int main()
{
    TicTacToe game;
    game.run();
    return 0;
}