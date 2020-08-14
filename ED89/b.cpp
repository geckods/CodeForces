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

bool rangeIntersect(ll a,ll b, ll x, ll y){
    return(a<=y && b>=x);
}

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
        ll n,x,m;
        cin>>n>>x>>m;
        ll currmin,currmax;
        currmin=currmax=x;
        ll arr[m][2];
        for(int i=0;i<m;i++){
            cin>>arr[i][0]>>arr[i][1];
            if(rangeIntersect(arr[i][0], arr[i][1], currmin, currmax)){
                currmin=min(currmin,arr[i][0]);
                currmax=max(currmax,arr[i][1]);
            }
            // cerr<<i<<" "<<currmin<<" "<<currmax<<endl;
        }
        cout<<currmax-currmin+1<<endl;
    }
}