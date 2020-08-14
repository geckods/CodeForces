#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    vector<ll> adj[n];

    for(int i=0;i<n-1;i++){
    	ll u,v;
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    ll ans=INT_MAX;

    map<ll,ll> myMap;
    for(int i=0;i<n;i++){
    	myMap[arr[i]]++;
    }

    for(int i=0;i<n;i++){
    	ll minians=INT_MIN;
    	minians = max(minians, arr[i]);
    	myMap[arr[i]]--;
    	for(int j=0;j<adj[i].size();j++){
    		minians = max(minians, arr[adj[i][j]]+1);
    		myMap[arr[adj[i][j]]]--;
    	}

    	auto it = myMap.rbegin();
    	while(it != myMap.rend() && it->second==0){
    		it++;
    	}
    	
    	if(it != myMap.rend())
	    	minians=max(minians, it->first+2);

    	ans=min(ans,minians);
    	myMap[arr[i]]++;
    	for(int j=0;j<adj[i].size();j++){
    		myMap[arr[adj[i][j]]]++;
    	}
    }
    cout<<ans<<endl;
}
