#include<bits/stdc++.h>
using namespace std;

const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("in.txt","r",stdin);
 //   if(ok)
       // freopen("output.txt","w",stdout);
}


int main(){

    file(true);
    long long int n,m;
    bool arr[n+1];
    long long int tempArr[n+1];
    long long int q[n+1];
    long long int x;
    long long int y;
    memset(arr, false, sizeof(arr));
    long long int count=0;
    set<int> mset;

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        tempArr[i] = x;
        cout<<x<<endl;
    }
    for(int i=0;i<m;i++){
        cin>>y;
        for(int j = y-1; j<n; j++){
            mset.insert(tempArr[j]);
        }
        cout<<mset.size()<<endl;
        mset.clear();
    }

return 0;
}
