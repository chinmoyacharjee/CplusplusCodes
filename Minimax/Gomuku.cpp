#include<bits/stdc++.h>
using namespace std;

#define rc 5
#define mem(x,y) memset(x, y, sizeof(x))


int find_max(char board[rc][rc], bool isMax);
int find_min(char board[3][3]);


int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int win_value = 1;
int cpu_turn = 1;

int dist[rc][rc];
int visited[rc][rc];

struct Move{
    int row, col;
};

bool valid(int tx, int ty, char board[rc][rc]){

    char palyer_sign = board[tx][ty];
    if(tx >= rc || tx < 0) return false;
    if(ty >= rc || ty < 0) return false;
    if(board[tx][ty] == palyer_sign) return true;
    return false;

}

bool isMovesLeft(char board[rc][rc]){
    for (int i = 0; i<rc; i++)
        for (int j = 0; j<rc; j++)
            if (board[i][j]=='-')
                return true;
    return false;
}

char determine_winner(char board[rc][rc]){
    for(int i=0; i<rc; i++){
        for(int j=0; j<rc; j++){
            if(dist[i][j] == 2){
                return board[i][j];
            }
        }
    }
}


bool is_winner(int tx, int ty, int dx, int dy, char board[rc][rc]){
    int palyer_sign = board[tx][ty];
    int count = 0;
    if(cpu_turn<3){
        win_value = cpu_turn;
    }
    else win_value = 3;

    while(true){
        if(palyer_sign == board[tx][ty]){
            count++;
        }else return false;

        if(count==win_value) return true;

        tx += dx;
        ty += dy;
        
        if(!valid(tx, ty, board)) return false;

    }
}



int evaluate(char board[rc][rc]){
    char player = 'X';
    char opponent = 'O';
    for(int i=0; i<rc; i++){
        for(int j=0; j<rc; j++){
            if(board[i][j] == 'O' || board[i][j] == 'X'){            
                
                char palyer_sign = board[i][j];

                for(int k = 0; k<8; k++){
                    int dirX = fx[k];
                    int dirY = fy[k];
                    if(is_winner(i, j, dirX, dirY, board)){
                        if(palyer_sign == player) return 10;
                        else if(palyer_sign == opponent) return -10; 
                    }
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
            if(j!=rc-1) cout<<"  |  ";
         
        }
        cout<<"  |  "<<endl;
        for(int i=0;i<rc;i++) cout<<"|-----";
        cout<<"|"<<endl;
    }cout<<endl<<endl;
}

int find_max(char board[rc][rc], bool isMax, int &step, int &alpha, int &beta){
    
    int score = evaluate(board);

    printf("%d\r", step);
    
    if (score == 10){
        return score-step;
    }
 
    if (score == -10){
        return score+step;
    }
 
    if (isMovesLeft(board)==false)
        return 0;

    if(isMax){
        int best = -1000;
        for (int i = 0; i<rc; i++){
            for (int j = 0; j<rc; j++){
                if (board[i][j]=='-'){
                    board[i][j] = 'X';
        
                    best = max(best, find_max(board, !isMax, ++step, alpha, beta));
                    alpha = max(best, alpha);
                    board[i][j] = '-';
                    
                    
                }
            }
        }
        return best;
    }else{
        int best = 1000;
        
        for (int i = 0; i<rc; i++){
            for (int j = 0; j<rc; j++){
                if (board[i][j]=='-'){
                    board[i][j] = 'O';
        
                    best = min(best, find_max(board, isMax, ++step, alpha, beta));
                    beta = min(best, beta);

                    board[i][j] = '-';
                    
                    
                }
            }
        }
        return best;
    }
}
Move findBestMove(char board[rc][rc]){
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    int bestVal = -1000;    

    for (int i = 0; i<rc; i++){

        for (int j = 0; j<rc; j++){
            
            if (board[i][j]=='-'){
                
                board[i][j] = 'X';
                int step = 0;
                cout<<i<<j<<endl;
                int alpha = -1000;
                int beta = 1000;
                int moveVal = find_max(board, false, step, alpha, beta );
                cout<<"Move: "<<i<<j<<" Value:"<<moveVal<<" step: "<<step<<endl;
                board[i][j] = '-';

                if (moveVal > bestVal){

                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
 
    // printf("The value of the best Move is : %d\n\n",
    //         bestVal);
    // printf("The Optimal Move is :\n");
    // printf("ROW: %d COL: %d\n\n", row, col );
    
}

Move random_move(char board[rc][rc]){
    srand(time(NULL));
    Move random_move;
    while(true){
        int i = rand()%rc;
        int j = rand()%rc;

        if(board[i][j]=='-'){
            random_move.row = i;
            random_move.col = j;

            return random_move;
        }
    }
}

Move get_human_move(char board[rc][rc]){
    Move human_move;
    while(true){
        int i;
        int j;
        cout<<"row col:";
        cin>>i>>j;
        
        if(board[i][j]=='-'){
            human_move.row = i;
            human_move.col = j;

            return human_move;
        }
        else{
            cout<<"Enter Valid Input"<<endl;
        }
    }
}


int play(char board[rc][rc]){
    
    char player_cpu = 'X';
    char player_human = 'O';
    char player = player_cpu;

    int rand_count = 0;
    

    Move move;

    while(true){

        if(player == player_cpu){
            if(cpu_turn == 1){
                move = random_move(board);
                board[move.row][move.col] = player_cpu;
                // rand_count++;
            }
            else{

                move = findBestMove(board);
                board[move.row][move.col] = player_cpu;
            }
            player = player_human;
            cpu_turn++;
        }
        else if(player == player_human){
            move = get_human_move(board);
            board[move.row][move.col] = player_human;
            player = player_cpu;
        }

        print_board(board);

        int score = 2;
    
        if (score == 10)
            return 10;
     
        if (score == -10)
            return score;
     
        if (isMovesLeft(board)==false)
            return 0;
    }
}


void test(char board[rc][rc]){
    int rn = 0;
    bool player = true;
    while(rn<10){
        Move move = random_move(board);
        if(player){
            board[move.row][move.col] = 'X';            
        }else{
            board[move.row][move.col] = 'O';          
        }
    print_board(board);

        player = !player;
// player = !player;
        rn++;
    }
    print_board(board);

    int winner = play(board);
    if(winner == 10) cout<<"Cpu Won"<<endl;
    else if(winner == -10) cout<<"You Won"<<endl;
    else{
        cout<<"It is tie"<<endl;
    }
    



    // char board[rc][rc]={
    //     {'X', '-', '-'},
    //     {'X', '-', '-'},
    //     {'X', '-', '-'}
    // };

    print_board(board);
    cout<<evaluate(board)<<endl;

}

int main(){
    char board[rc][rc];

    memset(board, '-', sizeof(board));
    // test(board);

    int winner = play(board);
    if(winner == 10) cout<<"Cpu Won"<<endl;
    else if(winner == -10) cout<<"You Won"<<endl;
    else{
        cout<<"It is tie"<<endl;
    }
    



    // // char board[rc][rc]={
    // //     {'X', '-', '-'},
    // //     {'X', '-', '-'},
    // //     {'X', '-', '-'}
    // // };

    // print_board(board);
    // cout<<evaluate(board)<<endl;
    

}