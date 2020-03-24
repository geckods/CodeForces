#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//damn good question, my intuition was fancy. Great solve
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
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}
   	sort(arr,arr+n);

   	ll prefix[n];
   	prefix[0]=arr[0];
   	for(int i=1;i<n;i++){
   		prefix[i]=arr[i]+prefix[i-1];
   	}

   	ll oneans=0;
   	for(int i=0;i<n;i++){
   		oneans+=arr[i]*(n-i-1);
   	}

   	ll q;
   	cin>>q;

   	for(int i=0;i<q;i++){
   		ll quer;
   		cin>>quer;

   		if(quer==1){
   			cout<<oneans<<endl;
   			continue;
   		}

   		ll ans=0;
   		ll z=0;
   		ll backind=1;
   		while(backind<n){
   			ans+=prefix[n-backind-1];
   			backind+=pow(quer,++z);
   		}

   		cout<<ans<<endl;
   	}
}