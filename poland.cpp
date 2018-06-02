
#include<bits/stdc++.h>
using namespace std;
void file(){
    freopen("input.txt","r",stdin);
}

int main(){
    int x,y;
    file();
    cin>>x>>y;
    string pol[x+2], em[y+2];

    map<string,int> poland;
    map<string,int> emptyB;
    map<string,int>::iterator it1;
    map<string,int>::iterator it2;
    string s;
    for (int i=0;i<x;i++){
        cin>>s;
        pol[i] = s;
        poland.insert(pair<string,int>(s,i));
    }
    for (int i=0;i<y;i++){
        cin>>s;
        em[i] = s;
        emptyB.insert(pair<string,int>(s,i));
    }

    if(abs(x-y)>1){
        if(x>y) printf("YES\n");
        else if(x<y) printf("NO\n");
    }else{
        int i = 0;
        int j = 0;
        while(true){
            if(i%2==0){
                it1 = emptyB.find(pol[i]);
                if(it1!=emptyB.end()){
                    emptyB.erase(it1);
                }
                poland.erase(pol[i]);
            }else{
                it2=poland.find(em[j]);
                if(it2!=poland.end()){
                    poland.erase(it2);
                }
                emptyB.erase(em[j]);
            }if(poland.size()==0){
                printf("NO\n");
                break;
            }else if(emptyB.size()==0){
                printf("YES\n");
                break;
            }
            i++;
            j++;
        }
    }






    return 0;
}
