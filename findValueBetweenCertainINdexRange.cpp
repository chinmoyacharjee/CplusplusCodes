#include<bits/stdc++.h>
using namespace std;

void file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


int main(){

    file();
    int size;
    cin>>size; //size must be below than 10^5.

    int arr[size];
    int cum[size];
    long long int x;
    memset(arr,0,sizeof(arr));
    memset(cum,0,sizeof(arr));

    for (int i=0;i<size;i++){
        cin>>x;
        arr[x]++;
    }


    for (int i=0;i<size;i++){
        for(int j=0;j<sizeof(arr[i]);j++){
            cum[i] += cum[i-1] + arr[j];
        }
    }
    for(int i=0;i<size;i++){
        cout<<cum[i]<<endl;
    }




return 0;
}
