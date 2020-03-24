#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int a1,a2,a3,a4;
   	cin>>a1>>a2>>a3>>a4;

   	int arr[4];
   	arr[0]=a1;
   	arr[1]=a2;
   	arr[2]=a3;
   	arr[3]=a4;

   	sort(arr,arr+4);
   	if(arr[0]+arr[3]==arr[1]+arr[2] || arr[0]+arr[1]+arr[2]==arr[3]){
   		cout<<"YES"<<endl;
   	}   	   	
   	else{
   		cout<<"NO"<<endl;
   	}
}
