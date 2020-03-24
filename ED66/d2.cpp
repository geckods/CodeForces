#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n,k;
   	cin>>n>>k;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	ll cumarr[n-1];
   	cumarr[n-2] = arr[n-1];

   	for(int i=n-3;i>=0;i--){
   		cumarr[i] = arr[i+1]+cumarr[i+1];
   	}


   	// for(int i=0;i<n-1;i++){
   	// 	cout<<cumarr[i]<<" ";
   	// }
   	// cout<<endl;
   	// for(int i=0;i<n-1;i++){
   	// 	cout<<cumarr[i]<<" ";
   	// }
   	// cout<<endl;

   	ll ans = cumarr[0]+arr[0];
   	sort(cumarr,cumarr+n-1);
   	// cout<<ans<<endl;

   	for(int i=0;i<k-1;i++){
   		ans+=cumarr[n-2-i];
   	}

   	cout<<ans<<endl;
}