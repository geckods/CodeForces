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
#define MAXELEM 200000
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    ll minind[MAXELEM+1];
    ll maxind[MAXELEM+1];
    memset(minind,-1,sizeof(minind));
    memset(maxind,-1,sizeof(maxind));
    for(int i=0;i<n;i++){
    	if(minind[arr[i]]==-1)minind[arr[i]]=i;
    	maxind[arr[i]]=i;
    }

    int i=0;

    ll ans=0;

    while(i<n){
    	int j=i;
    	ll currend=maxind[arr[i]];
    	while(j<currend){
    		j++;
    		currend=max(currend,maxind[arr[j]]);
    	}
    	// i to j-1 is now a segment

    	ll mostFreq=0;
    	unordered_map<ll,ll> myCountMap;
    	for(int k=i;k<=j;k++){
    		myCountMap[arr[k]]++;
    		if(myCountMap[arr[k]]>mostFreq)mostFreq=myCountMap[arr[k]];
    	}

    	ans+=j+1-i-mostFreq;
    	i=j+1;
    }
    cout<<ans<<endl;
}
