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

#define MAXN 200001
vector<ll> adj[MAXN];
typedef pair<ll,ll> intpair;
bool removed[MAXN];
bool isLeaf[MAXN];
ll cleafc[MAXN];

void clearGraph(ll n){
	for(int i=0;i<n;i++){
		adj[i].clear();
		removed[i]=false;
		cleafc[i]=0;
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

    ll t;
    cin>>t;

    while(t--){
    	ll n,k;
    	cin>>n>>k;
    	clearGraph(n);
    	ll x,y;
    	for(int i=0;i<n-1;i++){
    		cin>>x>>y;
    		x--;
    		y--;
    		adj[x].push_back(y);
    		adj[y].push_back(x);
    	}
	
		ll ans=0;

		queue<ll> myQ;
		for(int i=0;i<n;i++){
			if(adj[i].size()==1){
				myQ.push(i);
			}
		}

		while(!myQ.empty()){
			ll curr = myQ.front();
			myQ.pop();
			cerr<<curr<<endl;
			for(auto j: adj[curr]){
				if(!removed[j]){
					// cerr<<curr<<" "<<j<<endl;
					cleafc[j]++;
					if(cleafc[j]%k==0){
						// cerr<<j<<" "<<cleafc[j]<<endl;
						ans++;
						if(cleafc[j]==adj[j].size()-1){
							myQ.push(j);
						}
					}
				}
			}
			removed[curr]=true;
		}

		cout<<ans<<endl;
    }


}