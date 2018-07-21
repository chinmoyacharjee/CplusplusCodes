#include<iostream>


using namespace std;
int **matrix1, **matrix2, **matrix3;
int row1, col1, row2, col2;


void input()
{
cin >> col1 >> row1;

	matrix1 = new int *[row1];
	for(int i = 0; i < row1; i++){
		matrix1[i] = new int [col1];
		
	}
	for(int i = 0; i < row1; i++){
		for(int j = 0; j < col1; j++){
			cin >> matrix1[i][j];
		} 	
	}
	
	cin >> col2 >> row2;
	matrix2 = new int *[row2];
	for(int i = 0; i < row2; i++){
		matrix2[i] = new int [col2];
		
	}
	for(int i = 0; i < row2; i++){
		for(int j = 0; j < col2; j++){
			cin >> matrix2[i][j];
		} 	
	}
	
	matrix3 = new int *[row1];
	for(int i = 0; i < row1; i++){
		matrix3[i] = new int [col2];
		
	}


}
	
void multiplication(){
	for(int i = 0; i < row1; i++){
		for(int j = 0; j < col2; j++){
			matrix3[i][j] = 0;
			for(int k = 0; k < col1 ; k++){ 
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}
void print()
{
	for(int i = 0; i < row1; i++){
		for(int j = 0; j < col2; j++){
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}	
}
void delete1()
{
	for(int i = 0; i < row1; i++){
		delete [] matrix1[i];
		
	}
	delete [] matrix1;
	
	for(int i = 0; i < row2; i++){
		delete [] matrix2[i];
		
	}
	delete [] matrix2;
	
	for(int i = 0; i < row1; i++){
		delete [] matrix3[i];
		
	}
	delete [] matrix3;


}		
int main(){
//	freopen("matMul.txt", "r", stdin);
	
	
	
	
	
	input();
		
	if(col1 != row2){
		cout << "Multiplication Impossible\n";
		return 0;
		}
	multiplication();
	
	print();
	delete1();
	
		
	return 0;
}
		
	
		
	

