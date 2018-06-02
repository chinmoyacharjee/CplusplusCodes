#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("input.txt","r",stdin);
    //if(ok)
      //  freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    int m,n,l,r;
    char x[106];
    char f,t;
    scanf("%d %d %s",&m,&n,x);

    for(int i=0;i<n;i++){
        scanf("%d %d %c %c",&l,&r,&f,&t);
        if(l==r){
            if(x[l-1]==f) x[l-1] = t;
        }else{
            for(int j=l-1;j<r;j++){
                if(x[j]==f) x[j] = t;
            }
        }


    }printf("%s\n",x);

return 0;
}

