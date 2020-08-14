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

typedef pair<ll,ll> intpair;

#define MAXN 100001

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
    	map<ll,ll> occ;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		occ[arr[i]]++;
    	}

    	ll maxC = 0;
    	for(auto it:occ){
    		maxC=max(maxC,it.second);
    	}

    	ll numMax = 0;
    	for(auto it:occ){
    		if(it.second == maxC){
    			numMax++;
    		}
    	}

    	ll ans = (n-maxC*numMax)/(maxC-1) + numMax-1;
    	cout<<ans<<endl;
    }
}