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

    ll t;
    cin>>t;
    while(t--){
    	ll n,k,z;
    	cin>>n>>k>>z;
    	ll arr[n];
    	ll ans=0;
    	ll pairSum[n-1] = {0};

    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		if(i<=k)ans+=arr[i];
    	}

    	for(int i=0;i<n-1;i++){
    		pairSum[i]=arr[i]+arr[i+1];
    	}

    	ll prefix[n];
    	prefix[0]=arr[0];
    	for(int i=1;i<n;i++){
    		prefix[i]=arr[i]+prefix[i-1];
    	}

    	ll pairPrefix[n-1];
    	pairPrefix[0]=pairSum[0];
    	for(int i=1;i<n-1;i++){
    		pairPrefix[i]=pairPrefix[i-1]+pairSum[i];
    		// cerr<<i<<" "<<pairSum[i]<<" "<<pairPrefix[i]<<endl;
    	}

    	ll currSum=0;
    	for(int i=0;i<k;i++){
    		ll miniAns=0;
    		miniAns+=currSum;

    		ll canSpend = min(z,(k-i)/2);
    		ll leftOver = k-i-canSpend*2;

    		// cerr<<canSpend<<" "<<leftOver<<endl;

    		miniAns+=pairSum[i]*(canSpend+1);
    		miniAns+=prefix[i+leftOver]-prefix[i+1];

    		// cerr<<i<<" "<<canSpend<<" "<<leftOver<<" "<<miniAns<<endl;
    		ans=max(ans,miniAns);

    		currSum+=arr[i];
    	}

    	// ll largest=0;
    	// ll largestPair=-1;
    	// for(int i=0;i<k;i++){
    	// 	if(pairSum[i]>largest){
    	// 		largest=pairSum[i];
    	// 		largestPair=i;
    	// 	}
    	// }

    	// // cerr<<largest<<" "<<largestPair<<endl;

    	// ll lastPair = k-1;
    	// ll c = 0;
    	// while(lastPair>largestPair && c<z){
    	// 	ans-=pairSum[lastPair];
    	// 	ans+=largest;
    	// 	c++;
    	// 	lastPair-=2;
    	// }
    	// cerr<<ans<<endl;
    	cout<<ans<<endl;




    }
}