#include<bits/stdc++.h>
using namespace std;
int find_max(char board[3][3], bool isMax);
int find_min(char board[3][3]);



struct Move{
    int row, col;
};

int evaluate(char b[3][3]){
    char player = 'X';
    char opponent = 'O';
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;
 
            else if (b[0][col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }
 
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}

void print_board(char board[3][3]){
    cout<<"|-----|-----|-----|"<<endl;
    for (int i = 0; i<3; i++){
        cout<< "|  " ;
        for (int j = 0; j<3; j++){
            cout<<board[i][j];
            if(j!=2) cout<<"  |  ";
         
        }
        cout<< "  |" << endl;
        cout<<"|-----|-----|-----|"<<endl;
    }cout<<endl<<endl;
}

bool isMovesLeft(char board[3][3]){
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='-')
                return true;
    return false;
}

int find_max(char board[3][3], bool isMax, int &step){
    
    int score = evaluate(board);
    
    if (score == 10)
        return score-step;
 
    if (score == -10)
        return score+step;
 
    if (isMovesLeft(board)==false)
        return 0;

    if(isMax){
    // Traverse all cells
        int best = -1000;
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                // Check if cell is empty
                if (board[i][j]=='-'){
                    // Make the move
                    board[i][j] = 'X';
        
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max(best, find_max(board, !isMax, ++step));
        
                    // Undo the move
                    board[i][j] = '-';
                }
              }
        }
        return best;
    }else{
        int best = 1000;
        
            // Traverse all cells
        for (int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                // Check if cell is empty
                if (board[i][j]=='-'){
                    // Make the move
                    board[i][j] = 'O';
        
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best, find_max(board, isMax, ++step));
        
                    // Undo the move
                    board[i][j] = '-';
                }
            }
        }
        return best;
    }
}
int find_min(char board[3][3]){
    int score = evaluate(board);
    
    if (score == 10)
        return 10;
 
    if (score == -10)
        return score;
 
    if (isMovesLeft(board)==false)
        return 0;
    

    int best = 1000;
 
        // Traverse all cells
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            // Check if cell is empty
            if (board[i][j]=='-'){
                // Make the move
                board[i][j] = 'O';
    
                // Call minimax recursively and choose
                // the minimum value
                // best = min(best, find_max(board, ));
    
                // Undo the move
                board[i][j] = '-';
            }
        }
    }
    return best;    
}


Move findBestMove(char board[3][3]){
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    int bestVal = -1000;
    

    for (int i = 0; i<3; i++){

        for (int j = 0; j<3; j++){
            
            if (board[i][j]=='-'){
                
                board[i][j] = 'X';
                // print_board(board);
                int step = 0;

                int moveVal = find_max(board, false, step);
                cout<<"Move "<<i<<j<<" Value:"<<moveVal<<" step: "<<step<<endl;
                // Undo the move
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

Move random_move(char board[3][3]){
    srand(time(NULL));
    Move random_move;
    while(true){
        int i = rand()%3;
        int j = rand()%3;

        if(board[i][j]=='-'){
            random_move.row = i;
            random_move.col = j;

            return random_move;
        }
    }
}

Move get_human_move(char board[3][3]){
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


int play(char board[3][3]){
    
    char player_cpu = 'X';
    char player_human = 'O';
    char player = player_cpu;

    int rand_count = 0;

    Move move;

    while(true){

        

        
        if(player == player_cpu){
            if(rand_count<2){
                move = random_move(board);
                board[move.row][move.col] = player_cpu;
                rand_count++;
            }
            else{
                move = findBestMove(board);
                board[move.row][move.col] = player_cpu;
            }
            player = player_human;
        }
        else if(player == player_human){
            move = get_human_move(board);
            board[move.row][move.col] = player_human;
            player = player_cpu;
        }

        print_board(board);

        int score = evaluate(board);
    
        if (score == 10)
            return 10;
     
        if (score == -10)
            return score;
     
        if (isMovesLeft(board)==false)
            return 0;
        }
        

}


int main(){
    char board[3][3]={
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    print_board(board);
    
    int winner = play(board);
    if(winner == 10) cout<<"Cpu Won"<<endl;
    else if(winner == -10) cout<<"You Won"<<endl;
    else{
        cout<<"It is tie"<<endl;
    }
}