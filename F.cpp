
#include<bits/stdc++.h>
using namespace std;
void file(){
    freopen("input.txt","r",stdin);
}

int main(){
    string s;
   // file();
    cin>>s;
    long long int len  = s.length();
    long long int arr[len];
    memset(arr,0,len);

    long long int count = 0;
    for (int i=0;i<len-1;i++){
        if(s[i]==s[i+1]){
            count++;
        }arr[i+1]=count;
    }

    long long int q,x,y;
    cin>>q;

    for(int i = 0;i<q;i++){
       cin>>x>>y;
       printf("%d\n",arr[y-1]-arr[x-1]);
    }

    return 0;
}

