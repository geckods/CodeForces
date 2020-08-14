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

    ll n,m,d;
    cin>>n>>m>>d;

    set<intpair> arr;
    for(int i=0;i<n;i++){
    	ll x;
    	cin>>x;
    	arr.insert({x,i});
    }


    ll ans[n];
    memset(ans,-1,sizeof(ans));

    ll cp=0;
    while(!arr.empty()){
    	auto it = arr.begin();
    	while(it!=arr.end()){
    		ans[(*it).second]=cp;
    		auto newIt = arr.lower_bound({(*it).first+d+1,-1});
    		arr.erase(it);
    		it=newIt;
    	}
    	cp++;
    }

    cout<<cp<<endl;
    for(int i=0;i<n;i++){
    	cout<<ans[i]+1<<" ";
    }
    cout<<endl;

}
