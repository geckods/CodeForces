#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
    	ll n;
    	cin>>n;

    	ll arr[n];

    	ll minElem=0;

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		minElem=min(minElem,arr[i]);
    	}

    	for(int i=0;i<n;i++){
    		arr[i]-=minElem;
    		// cerr<<arr[i]<<endl;
    	}

    	// if a bit is set and then unset, that bit is the max
    	ll ans=0;
    	ll maxElemSoFar=0;

    	for(int i=0;i<n;i++){
    		ll x = maxElemSoFar-arr[i];
    		if(x<=0){
    			maxElemSoFar=arr[i];
    			continue;
    		}

    		ll j=0;
    		while(x){
    			x/=2;
    			j++;
    		}

    		ans=max(ans,j);

    		maxElemSoFar=max(maxElemSoFar,arr[i]);

    	}
    	cout<<ans<<endl;

    }

}
