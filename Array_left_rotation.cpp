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


int main(){

    //file(false);
    int n, l;
    scanf("%d%d",&n,&l);
    
    int temp_arr[n+1];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        // arr[x] = i;
        int index;
        index = i-l;
        if(index<0){
            index+=n;
        }
        printf("%d--%d\n", index, x);
        temp_arr[index] = x;
    }
    for(int i=0;i<n;i++){
        printf("%d ", temp_arr[i]);
    }
    printf("\n");
	return 0;
}
