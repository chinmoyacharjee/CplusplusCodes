#include<bits/stdc++.h>
using namespace std;
#define  ll long long int
const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("input.txt","r",stdin);
 //   if(ok)
   //     freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    ll num;
    int x;
    scanf("%lld",&num);
    ll c1=0,c2 =0;
    for(ll i = 0;i<num;i++){
        scanf("%d",&x);
        if(x==1){
            c1++;
        }else c2++;
    }
    ll total =0;
    if(c2==0){
        total+=(int)c1/3;
    }
    else if(c2>=c1){
        total+=c1;
        //c2-=c1;
    }else if(c2<c1){
        total+=c2;
        c1-=c2;
        total+= (int)c1/3;
    }
    printf("%lld",total);


return 0;
}

