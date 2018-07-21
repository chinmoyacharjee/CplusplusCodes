#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[] = {5,2,-9,3};
	for(int i=0;i<4;i++){
		for(int j = i+1;j<4;j++){
			int temp;
			if(arr[i]<=arr[j]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for(int i=0;i<3;i++){
		cout<<arr[i]<<" ";
	} 
	// sort(arr, arr+4, greater<int>());
	// for(int i=0;i<3;i++){
	// 	cout<<arr[i]<<" ";
	// } 
	return 0;
}
