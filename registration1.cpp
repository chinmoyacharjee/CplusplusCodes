#include<bits/stdc++.h>
using namespace std;
int main(){
    map <string, pair<bool, int>> mymap;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(mymap[s].first == false){
            mymap[s].first = true;
            mymap[s].second++;
            cout<<"OK"<<endl;
        }else{
            cout<<s<<mymap[s].second<<endl;
            mymap[s].second++;
        }
    }
    return 0;
}
