#include <iostream>
#include <fstream>

using namespace std;

int **matrix1, **matrix2, **matrix3;
int row1, col1, row2, col2;

void multiplyMatrices(void)
{
	matrix3 = new int* [row1];
	for(int i=0; i<row1; i++)
		matrix3[i] = new int [col2];
		
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col2; j++)
		{
			matrix3[i][j]=0;
			for(int k=0; k<col1 ; k++)
			{
				matrix3[i][j] += matrix1[i][k] *matrix2[k][j];
			}
		}
	}
}

void printInput(void)
{
	for(int i=0;i<row1;i++)
	{
		for (int j=0;j<col1;j++)
		{
			cout << matrix1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	for(int i=0;i<row2;i++)
	{
		for (int j=0;j<col2;j++)
		{
			cout << matrix2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;	 
}

bool readInput(char *fileName)
{
	ifstream iFile;
	iFile.open(fileName);
	if(iFile.is_open())
	{
		iFile >> row1 >> col1 ;
		
		matrix1 = new int* [row1];
		for(int i =0; i<row1; i++)
			matrix1[i] = new int[col1];
		
				
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col1; j++)
			{
				iFile >> matrix1[i][j];
			}
		}
		
		iFile >> row2 >> col2 ;
		
		matrix2 = new int* [row2];
		for(int i =0; i<row2; i++)
			matrix2[i] = new int[col2];
		
				
		for(int i=0; i<row2; i++)
		{
			for(int j=0; j<col2; j++)
			{
				iFile >> matrix2[i][j];
			}
		}
		
		//printInput();
		
		iFile.close();
		return true;
	}
	else
	{
		cout << "Could not open input file"<< endl;
		return false;
	}
}

void printResult(void)
{
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col2; j++)
		{
			cout << matrix3[i][j] << "\t";
		}
		cout << endl;
	}	
}

void deallocateMemory(void)
{
	for(int i =0; i<row1; i++)
		delete [] matrix1[i];
	delete [] matrix1;
	
	for(int i =0; i<row2; i++)
		delete [] matrix2[i];
	delete [] matrix2;
	
	for(int i=0; i<row1; i++)
		delete [] matrix3[i];
	delete [] matrix3;
}

int main (int argc, char * argv [])
{
	if(!readInput(argv[1])) return -1;
	
	if(col1 != row2)
	{
		cout << "Multiplication Impossible\n";
		return -1;
	}
	
	multiplyMatrices();
	printResult();
	deallocateMemory();
	
	return 0;
}
