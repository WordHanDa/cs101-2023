#include <iostream>

using namespace std;
class input{
    private:
        bool player=true;
    public:
        int x,y;
        char matrix[3][3];
        void playerInput(){
            cin>>x>>y;
            if(x>3||y>3){
                cout<<"Warning Wrong Number"<<endl;
                playerInput();
            }else if(matrix[y-1][x-1]){
                cout<<"you can't overwrite"<<endl;
                playerInput();
            }else{
                matrix[y-1][x-1]=(player)?'X':'O';
                player=(player)?false:true;
            }
        }
        void checkerboard_builder(){
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char str=(matrix[i][j])?matrix[i][j]:' ';
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
    private:
        int n=0;
    public:
        bool checkWin(){
            for (int i = 0; i < 3; i++) {
                if (matrix[i][0] == 'X' && matrix[i][1] == 'X' && matrix[i][2] == 'X') {
                cout << "Player 2 wins" << endl;
                return true;
            } else if (matrix[i][0] == 'O' && matrix[i][1] == 'O' && matrix[i][2] == 'O') {
                cout << "Player 1 wins" << endl;
                return true;
            }
            }
            for (int j = 0; j < 3; j++) {
                if (matrix[0][j] == 'X' && matrix[1][j] == 'X' && matrix[2][j] == 'X') {
                cout << "Player 2 wins" << endl;
                return true;
            } else if (matrix[0][j] == 'O' && matrix[1][j] == 'O' && matrix[2][j] == 'O') {
                cout << "Player 1 wins" << endl;
                return true;
                }
            }
            if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') {
                cout << "Player 2 wins" << endl;
                return true;
            } else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') {
                cout << "Player 1 wins" << endl;
                return true;
            } else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') {
                cout << "Player 2 wins" << endl;
                return true;
            } else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') {
                cout << "Player 1 wins" << endl;
                return true;
            }
        return false;
        }
        void run(){
            while(n<9){
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