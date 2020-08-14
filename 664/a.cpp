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

    ll n,d,m;
    cin>>n>>d>>m;

    vector<ll> lessThan;
    vector<ll> greaterThan;
    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    	if(arr[i]>m){
    		greaterThan.push_back(arr[i]);
    	}
    	else{
    		lessThan.push_back(arr[i]);
    	}
    }

	ll gn = greaterThan.size();
	ll ln = lessThan.size();    

    sort(greaterThan.begin(), greaterThan.end());
    sort(lessThan.begin(), lessThan.end());
    reverse(greaterThan.begin(), greaterThan.end());
    reverse(lessThan.begin(), lessThan.end());

    if(gn==0){
    	ll ans=0;
    	for(int i=0;i<n;i++){
    		ans+=arr[i];
    	}
    	cout<<ans<<endl;
    	return 0;
    }

    ll gtp[gn];
    gtp[0]=greaterThan[0];
    for(ll i=1;i<gn;i++){
    	gtp[i]=gtp[i-1]+greaterThan[i];
    }

    if(gn==n){
    	cout<<gtp[(int) ceil((double)n)/(d+1)]<<endl;
    	return 0;
    }

    ll ltp[ln];
    ltp[0]=lessThan[0];
    for(int i=1;i<ln;i++){
    	ltp[i]=ltp[i-1]+lessThan[i];
    }

    ll ans=0;
    // cerr<<ans<<endl;
    for(ll i=0;i<=gn;i++){

    	if((i-1)*(d+1) +1 > n)break;

    	ll numBig = i;
    	ll numSmall = min(n-((i-1)*(d+1))-1,ln);

    	ll minians=0;
    	if(numBig>0)minians+=gtp[numBig-1];
    	if(numSmall>0)minians+=ltp[numSmall-1];
    	ans=max(ans,minians);
    }

    cout<<ans<<endl;

}
