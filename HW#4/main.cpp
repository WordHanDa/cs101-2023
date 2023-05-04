#include <iostream>

using namespace std;
class input{
    private:
        bool player=true;
    public:
        int x,y;
        char numArray[3][3];
        void playerInput(){
            cin>>x>>y;
            if(x>3||y>3){
                cout<<"Warning Wrong Number"<<endl;
                playerInput();
            }else if(numArray[y-1][x-1]){
                cout<<"you can't overwrite"<<endl;
                playerInput();
            }else{
                numArray[y-1][x-1]=(player)?'X':'O';
                player=(player)?false:true;
            }
        }
        void checkerboard_builder(){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char str=(numArray[i][j])?numArray[i][j]:' ';
                    cout << str << "|";
                }
                cout <<endl;
            }
        }
        bool getPlayerStatus(){
            return player;
        }
};
class TicTacToe:input{
    public:
        string win(){
            string winner=(!player)?"player1":"player2";
            return winner;
        }
        bool checkWin(){
            
        }
        void run(){
            playerInput();
            checkerboard_builder();
            playerInput();
            checkerboard_builder();
            ()
        }
};

int main()
{
    TicTacToe game;
    game.run();
    return 0;
}