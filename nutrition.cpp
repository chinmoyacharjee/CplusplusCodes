#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("input.txt","r",stdin);
   // if(ok)
     //   freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    ll n,a,b;

    scanf("%lld %lld %lld",&n,&a,&b);

    if(n%a==0 || n%b==0){
        printf("YES\n");

    }else{

        ll t,t1;
        if(a<b){
            t = a;
            t1 = b;
        }else{
            t = b;
            t1 = a;
        }

        if((n%t1)%t==0) printf("YES\n");

        else{
            ll x = n%a;
            ll y = n%b;

            ll x1 = x+y;
            ll y1 = abs(x-y);

            if(x1%t==0 || y1%t==0){
                printf("YES\n");
            }else printf("NO\n");
        }


    }


return 0;
}

