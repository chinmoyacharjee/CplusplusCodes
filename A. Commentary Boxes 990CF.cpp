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
    long long int n,m,a,b;
    scanf("%lld%lld%lld%lld", &n,&m,&a,&b);
    long long int rm = n%m;
    if(rm==0){
        printf("0\n");
    }else{
        long long int x = rm*b;
        long long int y = (m-rm)*a;
        // printf("%lld%lld\n",x,y );
        if(x>y){
            printf("%lld\n", y);
        }else{
            printf("%lld\n", x);
        } 
    }
    
	return 0;
}
