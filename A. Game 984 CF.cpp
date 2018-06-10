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

    file(false);
    int n;
    scanf("%d", &n);
    long long int arr[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    int remainElement = n;
    int i = 0;
    int j = n-1;
    int person = 0;
    while(remainElement!=1){
        if(person==0){
            person =1;
            i++;
        }
        else if(person == 1){
            person = 0;
            j--;
        }
        remainElement--;
    }
    printf("%d\n", arr[j]);
	return 0;
}
