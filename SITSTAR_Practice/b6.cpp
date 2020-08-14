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

ll msbPos(ll x){
	if(x==0)return -1;

	int ans=40;
	while(1){
		if((x>>ans)&1){
			return ans;
		}
		ans--;
	}
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;

    ll c,d;
    c=min(a,b);
    d=max(a,b);

    // cout<<msbPos(c)<<" "<<msbPos(d)<<endl;
    while(msbPos(d)>msbPos(c)){
    	d=d>>1;
    }


    ll e = d^c;
    ll toMove = msbPos(e)+1;
    cout<<(d>>toMove)<<endl;

}