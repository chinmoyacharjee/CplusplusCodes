
#include<bits/stdc++.h>
using namespace std;
int main(){

    long long int size;
    cin>>size;
    string arr[size];
    map<string,int> mymap;
    map<string,int>::iterator it;
    string s;
    string prints[size];
    int temp;

    for (int i=0; i<size; i++){

        cin>>s;
        it = mymap.find(s);
        if (it != mymap.end()){ // found it

            temp = it->second;
            mymap.at(s) = ++temp;
            cout<<it->first<<it->second<<endl;

            //prints[i]=it->first+ (char)(it->second+'0');
        }else{
            cout<<"OK"<<endl;
            mymap.insert(pair<string,int>(s,0));
        }
    }

   return 0;

}
