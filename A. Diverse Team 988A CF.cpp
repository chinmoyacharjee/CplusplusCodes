#include<bits/stdc++.h>
using namespace std;

const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("input.txt","r",stdin);
    if(ok)
        freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    set <int> x;
    x.insert(5);
    x.insert(2);
    cout<<x[0]<<endl;

	return 0;
}
