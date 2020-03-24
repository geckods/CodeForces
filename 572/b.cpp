#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	sort(arr,arr+n);

   	if(arr[n-1]>=(arr[n-2]+arr[n-3])){
   		cout<<"NO"<<endl;
   	}
   	else{
   		cout<<"YES"<<endl;
   		int i;
   		for(i=n-1;i>=0;i-=2){
   			cout<<arr[i]<<" ";
   		}
   		if(i==-1){
   			i=0;
   		}
   		else{
   			i=1;
   		}
   		for(;i<n;i+=2){
   			cout<<arr[i]<<" ";
   		}
   		cout<<endl;
   	}
}