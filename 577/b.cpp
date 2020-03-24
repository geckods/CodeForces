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

   	ll n;
   	cin>>n;

   	ll arr[n];

   	ll sum=0;
   	ll maxof=0;

   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		maxof=max(maxof,arr[i]);
   		sum+=arr[i];
   	}

   	if(sum%2==0 && maxof<=(sum-maxof)){
   		cout<<"YES"<<endl;
   	}
   	else{
   		cout<<"NO"<<endl;
   	}
}