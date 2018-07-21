#include<bits/stdc++.h>
using namespace std;

const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}

int moves(int i, int val, int eORo){
    if(eORo==0){
        return abs(2*i - val);    
    }
    else return abs((2*i-1) - val);
    
}

int main(){

    file(false);
    int n;
    scanf("%d", &n);
    int arr[(n/2)+1];
    int eORo = 1; //odd
    int totalMoves = 0;
    
    for(int i=0;i<n/2;i++){
        scanf("%d",&arr[i]);         
    }

    sort(arr, arr+n/2, greater<int>());

    if(arr[0]%2==0){
        eORo = 0; //even
    }        

    for(int i=0;i<n/2;i++){
        totalMoves += moves(i+1, arr[i], eORo);
        cout<<arr[i]<<"--"<<moves(i+1, arr[i], eORo)<<endl;
    }

    printf("%d\n", totalMoves);  
	return 0;
}
