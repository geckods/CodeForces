#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
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

    ll a[n];
    ll b[n];
    ll aPos[n];
    ll bPos[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	a[i]--;
    	aPos[a[i]]=i;
    }
    for(int i=0;i<n;i++){
    	cin>>b[i];
    	b[i]--;
    	bPos[b[i]]=i;
    }

    map<ll,ll> myMap;
    for(int i=0;i<n;i++){
    	ll curr=aPos[i]-bPos[i];
    	if(curr<0)curr+=n;
    	myMap[curr]++;
    }

    ll ans=0;
    for(auto it : myMap){
    	ans=max(ans,it.second);
    }
    cout<<ans<<endl;

}