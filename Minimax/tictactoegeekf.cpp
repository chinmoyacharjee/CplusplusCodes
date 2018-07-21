// C++ program to find the next optimal move for
// a player
#include<bits/stdc++.h>
using namespace std;
 
struct Move{
    int row, col;
};
 
char player = 'x', opponent = 'o';
 
// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char board[3][3]){
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
 
// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int evaluate(char b[3][3])
{
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
 
// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board

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

int minimax(char board[3][3], int depth, bool isMax)
{
    // print_board(board);
    int score = evaluate(board);
    // cout<<"score: "<<score<<endl;
 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return 10;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false){
        cout<<"called"<<endl;
        return 0;
    }
 
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = player;
 
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax) );
 
                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = opponent;
 
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(board, depth+1, isMax));
 
                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
 
// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
 
    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if celll is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = player;
                print_board(board);

 
                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);
                cout<<moveVal<<endl;
                // Undo the move
                board[i][j] = '_';
 
                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
 
    printf("The value of the best Move is : %d\n\n",
            bestVal);
    printf("The Optimal Move is :\n");
    printf("ROW: %d COL: %d\n\n", bestMove.row, bestMove.col );
 
    return bestMove;
}
Move random_choose(char board[3][3]){
    // rand()%9;
    while(true){
        Move random_move;
        random_move.row = rand()%3;
        random_move.col = rand()%3;

        if(board[random_move.row][random_move.col]=='_') return random_move;
    } 
}
void play(){
    char board[3][3] =
    {
        {'_', '_', '_'},
        {'O', '_', '_'},
        {'O', '_', '_'}
    };
    print_board(board);
 
    
    int player_human = 0;
    int player_cpu = 1;
    int player = player_cpu;
    
    int random_choose_count = 0;

    while(true){
        
        if(player == player_cpu){
            cout<<"Cpu Turn:"<<endl;
            if(random_choose_count<2){
                Move random_move = random_choose(board);
                board[random_move.row][random_move.col] = 'x';
                random_choose_count++;
            }else{
                Move bestMove = findBestMove(board);
                board[bestMove.row][bestMove.col] = 'x';
            }
            player = player_human;
        }else if(player == player_human){
            cout<<"Your Turn:"<<endl;
            cout<<"row  col:";
            int r, c; 
            cin>>r>>c;
            board[r][c] = 'o';
            player = player_cpu;
        }print_board(board);
    }
 
    // printf("The Optimal Move is :\n");
    // printf("ROW: %d COL: %d\n\n", bestMove.row,
                                  // bestMove.col );
}

// Driver code
int main()
{
    // play();
    char board[3][3] =
    {
        {'_', 'x', '_'},
        {'o', 'x', '_'},
        {'o', '_', '_'}
    };
    findBestMove(board);
    
    return 0;
}