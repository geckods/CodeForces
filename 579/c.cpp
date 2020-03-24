#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

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

   	ll mymin=LLONG_MAX;
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   		if(mymin==LLONG_MAX)mymin=arr[i];
   		else{
   			mymin=gcd(mymin,arr[i]);
   		}
   		// mymin=min(mymin,arr[i]);
   	}

   	if(mymin==1)cout<<1<<endl;
   	else{
   		ll ans=0;
   		for(ll j=1;j*j<=mymin;j++){
   			if(j*j==mymin){
   				ans++;
   			}
   			else if (mymin%j==0){
   				ans+=2;
   			}
   		}
		cout<<ans<<endl;
   	}

}