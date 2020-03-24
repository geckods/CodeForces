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
   	bool haseven = false;
   	bool hasodd = false;

   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		if(arr[i]%2==0){
   			haseven=true;
   		}
   		else{
   			hasodd=true;
   		}
   	}

   	if(hasodd&&haseven){
   		sort(arr,arr+n);
   	}

   	for(int i=0;i<n;i++){
   		cout<<arr[i]<<" ";
   	}

   	cout<<endl;
}