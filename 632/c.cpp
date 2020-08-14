#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // =

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    map<ll,ll> myMap;

    ll invalid[n];
    ll curr=0;
    ll ans=0;

    for(int i=0;i<n;i++){
    	curr+=arr[i];
    	myMap[curr]=-2;
    }

    myMap[0]=-1;
    curr=0;

    ll currmax=-2;

    for(int i=0;i<n;i++){
    	curr+=arr[i];
    	currmax=max(currmax,myMap[curr]);
	    ans+=i-currmax-1;
    	// cerr<<i<<" "<<ans<<endl;
    	myMap[curr]=i;
    }
    cout<<ans<<endl;
}