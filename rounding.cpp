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
        //freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    ll x;
    scanf("%lld",&x);
    int y = x%10;
    if(y<=5) printf("%lld\n",x-y);
    else printf("%lld\n",x+(10-y));
return 0;
}

