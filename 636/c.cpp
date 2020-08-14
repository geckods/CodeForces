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
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	int i=0;
    	ll maxElem=INT_MIN;
    	ll ans=0;
    	while(i<n){
    		int j=i+1;
    		maxElem=arr[i];
    		while(j<n && (arr[j]>0)==(arr[i]>0)){
    			maxElem=max(maxElem,arr[j]);
    			j++;
    		}
    		// cerr<<i<<" "<<j<<endl;

    		ans+=maxElem;
    		i=j;
    	}
    	cout<<ans<<endl;
    }
}