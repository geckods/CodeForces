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

   	ll n,k;
   	cin>>n>>k;

   	ll arr[n];

   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	sort(arr,arr+n);

   	ll currmult=1;
   	ll ans=0;
   	for(int i=n/2;i<n-1;i++){
   		if(k<currmult*(arr[i+1]-arr[i])){
   			ans=arr[i]+(k/currmult);
   			k=-1;
   			break;
   		}
   		else{
   			k-=(arr[i+1]-arr[i])*currmult;
   		}
   		currmult++;
   	}

   	if(k>=0){
   		ans=arr[n-1]+(k/currmult);
   	}

   	cout<<ans<<endl;
}
