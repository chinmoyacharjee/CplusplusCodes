#include<bits/stdc++.h>
using namespace std;

const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool printInFile){
    freopen("input.txt","r",stdin);
    if(printInFile)
        freopen("output.txt","w",stdout);
}


int main(){

    file(false);
    map<string,string> mymap;
    mymap["purple"] = "Power";
    mymap["green"] =     "Time";
    mymap["blue"] =     "Space";
    mymap["orange"] =     "Soul";
    mymap["red"] =     "Reality";
    mymap["yellow"] =     "Mind";
    

    map<string,string> mymap1;

    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        mymap1[x] = "0";
    }
    printf("%d\n", 6-n);
    for (map<string, string>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        // cout<<it->first<<endl;
        int count = mymap1.count(it->first);
        if(count==0) cout<<it->second<<endl;
    }

	return 0;
}
