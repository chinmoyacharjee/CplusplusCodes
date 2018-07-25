#include<bits/stdc++.h>
using namespace std;

#define rc 5

int find_max(char board[3][3], bool isMax);
int find_min(char board[3][3]);


int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int win_value = 3;

struct Move{
    int row, col;
};

bool determine(int tx, int ty, char palyer_sign, char board[rc][cc]){

    if(tx >= r || tx < 0) return false;
    if(ty >= c || ty < 0) return false;
    if()
    return true;
}

int evaluate(char board[rc][rc]){
    char player = 'X';
    char opponent = 'O';

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int count = 1;
            int tempX = i;
            int tempY = j;
            if(board[i][j] == 'O' || board[i][j] == 'X'){
                char palyer_sign = board[i][j];

                for(int k = 0; k<8; k++){
                    int tx
                }
            }
        }
    }


    
    return 0;
}

void print_board(char board[rc][rc]){
    
    for(int i=0;i<rc;i++) cout<<"|-----";
    cout<<"|"<<endl;
    // cout<<"|-----|-----|-----|"<<endl;
    for (int i = 0; i<rc; i++){
        cout<< "|  " ;
        for (int j = 0; j<rc; j++){
            cout<<board[i][j];
            if(j!=4) cout<<"  |  ";
         
        }
        cout<<"  |  "<<endl;
        for(int i=0;i<rc;i++) cout<<"|-----";
        cout<<"|"<<endl;
    }cout<<endl<<endl;
}



int main(){
    char board[rc][rc];

    memset(board, '-', sizeof(board));

    print_board(board);
    
    int winner = play(board);
    // if(winner == 10) cout<<"Cpu Won"<<endl;
    // else if(winner == -10) cout<<"You Won"<<endl;
    // else{
    //     cout<<"It is tie"<<endl;
    // }

    // char board[3][3]={
    //     {'-', '-', 'X'},
    //     {'-', 'X', '-'},
    //     {'-', '-', '-'}
    // };
    // print_board(board);
    // findBestMove(board);

}