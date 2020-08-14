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

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,h;
    cin>>n>>h;

    ll seg[n][2];
    for(int i=0;i<n;i++){
    	cin>>seg[i][0]>>seg[i][1];
    }

    ll pref[n];
    pref[0]=0;

    for(int i=1;i<n;i++){
    	pref[i]=pref[i-1]+(seg[i][0]-seg[i-1][1]);
    }

    ll ans=h;
    for(int i=0;i<n;i++){
    	ll miniAns=0;
    	ll prefInd = lower_bound(pref,pref+n,pref[i]+h)-pref;

    	prefInd--;
    	miniAns = seg[prefInd][1]-seg[i][0]+h-(pref[prefInd]-pref[i]);
    	ans=max(ans,miniAns);
    }
    cout<<ans<<endl;


}