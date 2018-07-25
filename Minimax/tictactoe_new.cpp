#include<bits/stdc++.h>
using namespace std;

int find_max(int board[9]);
int find_min(int board[9]);
void print_board(int board[9]);

int determine_winner(int board[9]){
	int player_cpu = 1;
	int player_human = 0;

	if(board[0]  ==  board[1] && board[1] == board[2] && board[0]!=-1 && board[1]!=-1 && board[2]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	if(board[0] == board[3] && board[3] == board[6] && board[0]!=-1 && board[3]!=-1 && board[6]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	if(board[0] == board[4] && board[4] == board[8] && board[0]!=-1 && board[4]!=-1 && board[8]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	if(board[1] == board[4] && board[4] == board[7] && board[1]!=-1 && board[4]!=-1 && board[7]!=-1){
		if(board[1] == player_cpu)  return player_cpu;
		else if(board[1] == player_human) return player_human;
	}
	if(board[2] == board[4] && board[4] == board[6] && board[2]!=-1 && board[4]!=-1 && board[6]!=-1){
		if(board[2] == player_cpu)  return player_cpu;
		else if(board[2] == player_human){
			// cout<<"32"<<endl;
			// print_board(board);
			return player_human;	
		} 
	}
	if(board[2] == board[5] && board[5] == board[8] && board[2]!=-1 && board[5]!=-1 && board[8]!=-1){
		
		if(board[2] == player_cpu){  
			// cout<<"Entered"<<endl;
			return player_cpu;
		}
		else if(board[2] == player_human) return player_human;
	}
	if(board[3] == board[4] && board[4] == board[5] && board[3]!=-1 && board[4]!=-1 && board[5]!=-1){
		if(board[3] == player_cpu)  return player_cpu;
		else if(board[3] == player_human) return player_human;
	}
	if(board[6] == board[7] && board[7] == board[8] && board[6]!=-1 && board[7]!=-1 && board[8]!=-1){
		if(board[6] == player_cpu)  return player_cpu;
		else if(board[6] == player_human) return player_human;
	}
	return 0;
}

int win(int board[]){
	int temp_board[3][3];
	int k = 0;
	int player = 1;
	int opponent = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			temp_board[i][j] = board[k];
			k++;
		}
	}
	for (int row = 0; row<3; row++)
    {
        if (temp_board[row][0]==temp_board[row][1] &&
            temp_board[row][1]==temp_board[row][2])
        {
            if (temp_board[row][0]==player)
                return +10;
            else if (temp_board[row][0]==opponent)
                return -10;
        }
    }
 
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (temp_board[0][col]==temp_board[1][col] &&
            temp_board[1][col]==temp_board[2][col])
        {
            if (temp_board[0][col]==player)
                return +10;
 
            else if (temp_board[0][col]==opponent)
                return -10;
        }
    }
 
    // Checking for Diagonals for X or O victory.
    if (temp_board[0][0]==temp_board[1][1] && temp_board[1][1]==temp_board[2][2])
    {
        if (temp_board[0][0]==player)
            return +10;
        else if (temp_board[0][0]==opponent)
            return -10;
    }
 
    if (temp_board[0][2]==temp_board[1][1] && temp_board[1][1]==temp_board[2][0])
    {
        if (temp_board[0][2]==player)
            return +10;
        else if (temp_board[0][2]==opponent)
            return -10;
    }
 
    // Else if none of them have won then return 0
    return -10;


}


bool is_board_empty(int board[9]){
	for(int i = 0; i<9; i++){
		if(board[i]==-1) return true;
	}
	return false;
} 

string sign(int s){
	if(s == 1){
		return "X";
	}else if(s == 0){
		return "O";
	}return " ";
}

void print_board(int board[9]){
	cout<<"|-----|-----|-----|"<<endl;
	for(int i=0;i<9;i+=3){
		
		cout<< "|  " << sign(board[i]) << "  |  " << sign(board[i+1]) << "  |  " << sign(board[i+2]) << "  |" << endl;
		cout<<"|-----|-----|-----|"<<endl;
	}
	cout<<endl;
}


int generate_move(int board[9], bool turn){
	int temp = determine_winner(board);
	if(temp==1) return 10;
	if(temp==0) return 10;
	if(is_board_empty(board)==false) return 0;

	if(turn){	
		int best = -10000;

		for(int i=0;i<9;i++){
			if(board[i]==-1){
				board[i] = 1;
				best = max(best, generate_move(board, !turn));
				board[i] = -1;
			}
		}
		return best;
	}
	else{
		int best = 10000;

		for(int i=0;i<9;i++){
			if(board[i]==-1){
				board[i] = 0;
				best = min(best,  generate_move(board, turn));
				board[i] = -1;
			}
		}
		return best;
	}
}





// int find_max(int board[9]){
// 	int temp = determine_winner(board);
// 	if(temp==1) return +10;
// 	if(temp==0) return -10;
// 	if(is_board_empty(board)==false) return 0;

// 	int best = -10000;

// 	for(int i=0;i<9;i++){
// 		if(board[i]==-1){
// 			board[i] = 1;
// 			best = max(best, find_min(board));
// 			board[i] = -1;
// 		}
// 	}
// 	return best;
// }

// int find_min(int board[9]){
// 	int temp = determine_winner(board);

// 	if(temp==1) return +10;
// 	if(temp==0) return -10;
// 	if(is_board_empty(board)==false){
// 		cout<<"called"<<endl;
// 		return 0;
// 	}

// 	int best = 10000;

// 	for(int i=0;i<9;i++){
// 		if(board[i]==-1){
// 			board[i] = 0;
// 			best = min(best, find_max(board));
// 			board[i] = -1;
// 		}
// 	}
// 	return best;

// }


void find_best_move(int *board){
	int max_val = -10000;
	int optimum_cell;
	for(int i=0; i<9; i++){
		if(board[i]==-1){
			board[i] = 1;
			print_board(board);
			int best_value = generate_move(board, false); 
			cout<<"best val : "<<best_value<<endl;
			if(best_value > max_val){
				optimum_cell = i;
				max_val = best_value;				
			}
			board[i] = -1;
		}
	}
	cout << "Cell: " << optimum_cell << " Value: "<< max_val<< endl;
}



int main(){
	
	int board[] = 
	{
		-1, -1, 1, 
		-1,  1, -1, 
		-1, -1, -1
	};
	print_board(board);
	find_best_move(board);
	return 0;
}