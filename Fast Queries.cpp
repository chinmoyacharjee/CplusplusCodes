
#include<bits/stdc++.h>
using namespace std;
void file(){
    freopen("input.txt","r",stdin);
}

int main(){
    file();
    int T;

    long long int n,q;
    scanf("%d",&T);
    for(int o=1;o<=T;o++){

        scanf("%lld%lld",&n,&q);
        long long int arr[n+2],m,p,ans[q+2],t[n+2];
        //cout<<"dd"<<endl;
        for(long long int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }//cout<<"dd"<<endl;
        for(long long int i=0;i<q;i++){
            scanf("%lld%lld",&m, &p);
            //memset(t,0,sizeof(t));
            long long int countM = 0;
            set<int>s;
            for(long long int j = m-1; j<p; j++){
               s.insert(arr[j]);
            }
            ans[i] = s.size();

        }printf("Case %d:\n",o);
        for(long long int i = 0;i<q;i++) printf("%lld\n",ans[i]);
    }

    return 0;
}

