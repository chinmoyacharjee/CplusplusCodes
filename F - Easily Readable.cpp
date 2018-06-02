#include<bits/stdc++.h>
using namespace std;

void file(){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int main(){
    int t;
    file();

    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        long long int m;
        scanf("%lld",&m);
        string s;

        map<string,long long int> mymap;
        map<string,long long int>::iterator it;

        set<string> myset;
        set<string>::iterator it1;

        for(int j=0;j<m;j++){
            cin>>s;
            it1 = myset.find(s);
            if(it1==myset.end()){
                string temp="";
                temp += (char)s[0];
                if(s.length()!=1) temp +=(char)s[s.length()-1];
                temp +=(char)(s.length()+'0');

                it = mymap.find(temp);
                if (it != mymap.end()){ // found it
                    mymap[temp]++;
                }else{
                    mymap[temp] = 1;
                }

            }else myset.insert(s);



        }

        long long int n;
        char c;
        scanf("%lld%c",&n,&c);
        printf("Case %d:\n",i);
        for(long long int k=0;k<n;k++){

            string s1;
            getline(cin,s1);
            //cout<<s1<<endl;
            istringstream iss;
            iss.str (s1);
            string tempS;

            long long int x = 1;
            while(iss>>tempS){
                string temp2;
                temp2 += (char)tempS[0];
                if(tempS.length()!=1) temp2 +=(char)tempS[tempS.length()-1];
                temp2 +=(char)(tempS.length()+'0');
                //cout<<temp2<<endl;
                if(mymap[temp2]!=0)
                    x *= mymap[temp2];
            }printf("%d\n",x);

        }


    }
/*for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';*/
    return 0;
}
