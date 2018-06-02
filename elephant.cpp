#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   int i=1;
   scanf("%d",&n);
   while(i <= sqrt(n))
    {
        if(n%i==0) {

            if (i != (n / i)) {
                printf("%d,",n/i);
            }printf("%d,",i);
        }

        i++;
    }

}
