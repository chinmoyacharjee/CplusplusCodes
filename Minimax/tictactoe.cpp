#include<bits/stdc++.h>
using namespace std;

#define bug printf("Tested\n");

const long long int inf = 1e18;

string sign(int s){
	if(s == 1){
		return "X";
	}else if(s == 0){
		return "O";
	}return " ";
}

void print_board(int board[]){
	cout<<"|-----|-----|-----|"<<endl;
	for(int i=0;i<9;i+=3){
		
		cout<< "|  " << sign(board[i]) << "  |  " << sign(board[i+1]) << "  |  " << sign(board[i+2]) << "  |" << endl;
		cout<<"|-----|-----|-----|"<<endl;
	}
	cout<<endl;
}

int determine_winner(int board[9]){
	int player_cpu = 1;
	int player_human = 0;

	

	if(board[0]  ==  board[1] && board[1] == board[2] && board[0]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	else if(board[0] == board[3] && board[3] == board[6] && board[0]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	else if(board[0] == board[4] && board[4] == board[8] && board[0]!=-1){
		if(board[0] == player_cpu)  return player_cpu;
		else if(board[0] == player_human) return player_human;
	}
	else if(board[1] == board[4] && board[4] == board[7] && board[1]!=-1){
		if(board[1] == player_cpu)  return player_cpu;
		else if(board[1] == player_human) return player_human;
	}
	else if(board[2] == board[4] && board[4] == board[6] && board[2]!=-1){
		if(board[2] == player_cpu)  return player_cpu;
		else if(board[2] == player_human){
			return player_human;	
		} 
	}
	else if(board[2] == board[5] && board[5] == board[8] && board[2]!=-1){
		if(board[2] == player_human)  return player_human;
		else if(board[2] == player_cpu){
			return player_cpu;	
		} 
		 
	}
	else if(board[3] == board[4] && board[4] == board[5] && board[3]!=-1){
		if(board[3] == player_cpu)  return player_cpu;
		else if(board[3] == player_human) return player_human;
	}
	else if(board[6] == board[7] && board[7] == board[8] && board[6]!=-1){
		if(board[6] == player_cpu)  return player_cpu;
		else if(board[6] == player_human) return player_human;
	}
}


bool is_board_empty(int board[]){
	for(int i = 0; i<9; i++){
		if(board[i]==-1) return true;
	}
	return false;
} 

int is_game_over(int board[]){
	int winner_player = determine_winner(board);
	return winner_player;
	int cell_empty = is_board_empty(board);
	return cell_empty;
}

int return_max(int arr[]){
	int max_value =  - 100000;
	for(int i=0;i<9;i++){
		if(arr[i] >= max_value) max_value = arr[i];
	} 
	return max_value;
}
int return_min(int arr[]){
	
	int min_value =  100000;
	for(int i=0;i<9;i++){
		if(arr[i] <= min_value) min_value = arr[i];
	} 
	return min_value;
}


int generate_move(int board[], int cell, bool turn){
	
	// print_board(board);

	int temp = determine_winner(board);
	if(temp==0){
		
		return -10;
	}
	if(temp==1){
		
		return 10;
	}

	if(is_board_empty(board)==false) return 0;


	if(turn){ //cpu
		// max = inf;
		int best = -100005;	
	
		for(int i = 0; i<9; i++){
			
			if(board[i]==-1){
				board[i] = 1;
				// bug
				best = max(best, generate_move(board, i, !turn));
				board[i] = -1;
					
			}			
		}
		return best;
		// return return_max(max_min_holder);

	}
	else{ //human
		int best = 100005;
		
		for(int i = 0; i<9; i++){
			if(board[i]==-1){
				board[i] = 0;
				best = min(best, generate_move(board, i, turn));	
				board[i] = -1;
			}
			
		}
		return best;
		// return return_min(max_min_holder);

	}

}


void find_best_move(int *board){
	int max_value = - 10000;
	int cell;
	for(int i = 0; i<9; i++){
		if(board[i]==-1){
			board[i] = 1;
			// print_board(board);
			int move = generate_move(board, i, false);	
			// cout<<move<<endl;
			board[i] = -1;
			if(max_value < move){
				// cout<<max_value<<" "<<move<<" "<<i<<endl;
				max_value = move;
				cell = i;
			}
			
		}
	}
	board[cell] = 1;
	// cout<<"best move, cell no: "<< cell <<" best val: "<<max_value<< endl; 
	// print_board(board);
			
}

void play(){

	int board[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
	print_board(board);
	int player;
	int player_human = 0;
	int player_cpu = 1;
	player = player_cpu;
	while(true){
		if(player == player_cpu){
			cout<<"cpu"<<endl;
			find_best_move(board);
			print_board(board);
			player = player_human;
		}
		else if(player == player_human){
			cout<<"you"<<endl;
			print_board(board);
			int position;
			cout<<"choose position: ";
			cin>>position;
			board[position-1] = 0;
			print_board(board);
			player = player_cpu;
		}
	}
	
}

int main(){

	play();
	// int board[] = {-1, 1, -1, 0, 1, -1, 0, -1, -1};
	// cout << "Initial Board: "<<endl;
	// print_board(board);
	// find_best_move(board);
	return 0;
}

/*
Full Name: 	Chinmoy Acharjee
Mobile No: 	01521328290
NID:		19981592830000475
Profession: Student
Current Institution: University of Dhaka
Home Town: 	Chittagong 

*/