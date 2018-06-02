
#include<bits/stdc++.h>
using namespace std;
void file(){
    freopen("input.txt","r",stdin);
}
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b){
       return (a.first > b.first);
}
int main(){
    file();
    long long int n,q,x,y;
    //cin>>n>>q;
    scanf("%lld%lld",&n,&q);
    long long int arr[n+2],arr1[n+2],cum[n+2],arr2[n+2],cum1[n+2],q1[q],q2[q];

    for(int i = 0;i<n;i++){
        //cin>>arr[i];
        scanf("%lld",&arr[i]);
        cum[i] = 0;
        arr1[i] = 0;
    }
    arr1[n] = 0;
    arr1[n+1] = 0;
    //arr1[] = 0;

    cum[n] = 0;
    cum[n+1] = 0;
    //cum[n+2] = 0;

    sort(arr,arr+n,greater<int>());

    //memset(cum,0,sizeof(cum));
    //memset(arr1,0,sizeof(arr1));

     for(int i=0;i<q;i++){
        scanf("%lld%lld",&x,&y);
        q1[i]=x;
        q2[i]=y;
        arr1[x]++;
        arr1[y+1]--;

    }
    vector< pair <int,int> > vect;
    for(int i = 1;i<=n;i++){
        cum[i]+= cum[i-1]+arr1[i];
        vect.push_back( make_pair(cum[i],i) );
        cum1[i-1] = 0;

    }
    sort(vect.begin(),vect.end(),sortinrev);

    for(int i = 0; i<n;i++){
        arr2[vect[i].second-1] = arr[i];
    }

    for(int i=1;i<=n;i++){
        cum1[i] = cum1[i-1]+arr2[i-1];
    }
    long long int total=0;
    for(int i=0;i<q;i++){
        total+=(cum1[q2[i]]-cum1[q1[i]-1]);
    }
    //
    printf("%lld\n",total);

    return 0;

}
