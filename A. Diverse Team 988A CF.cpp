#include<bits/stdc++.h>
using namespace std;

const int N             = 3e5+5;
const long long Nb      = 12345689012345678;
const long double pi    = 3.141592653589793;
const long long int inf = 1e18;

void file(bool ok){
    freopen("input.txt","r",stdin);
    if(ok)
        freopen("output.txt","w",stdout);
}


int main(){

    file(false);
    
    set <int> x;
    set<int>::iterator it;
    int n, k;
    scanf("%d%d", &n,&k);
    int arr[101];
    for(int i=0;i<n;i++){
    	int val;
    	scanf("%d", &val);
    	arr[val] = i+1;
    	x.insert(val);
    }
    if(x.size()<k){
    	printf("NO\n");
    }else{
    	printf("YES\n");
    	// printf("size: %d\n",x.size());
    	int i=0;
    	for (it=x.begin(); it!=x.end(), i < k;  ++it){
    		int z = arr[*it];
    		printf("%d ", z);
    		i++;
    	}
    	printf("\n");
    	   
    }

	return 0;
}
