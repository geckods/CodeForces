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
typedef pair<ll,ll> intpair;

vector<intpair> adj[MAXN];
set<intpair> inAdj[MAXN];
vector<intpair> tmp[10];
vector<intpair> pairNotAllowed[9][9];

bool forbidden[9][9];
bool marked[9][9];
ll ans;

void backTrack(ll k, ll x, ll maxK){

	if(forbidden[k-1][x] || marked[k-1][x])return;

	if(k==maxK){
		// cerr<<k<<" "<<x<<endl;
		ans++;
		return;
	}

	intpair cannotHave;
	tmp[k].clear();
	for(int i=0;i<pairNotAllowed[k-1][x].size();i++){
		cannotHave = pairNotAllowed[k-1][x][i];
		if(marked[cannotHave.first][cannotHave.second]==0){
			marked[cannotHave.first][cannotHave.second]=true;
			tmp[k].push_back({cannotHave.first,cannotHave.second});
		}
	}

	ll emptyAns=-1;

	for(int j=0;j<k+1;j++){
		if(forbidden[k][j] || marked[k][j]){
			continue;
		}
		backTrack(k+1,j,maxK);			
	}

	for(int i=0;i<tmp[k].size();i++){
		cannotHave = tmp[k][i];
		marked[cannotHave.first][cannotHave.second]=false;
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

    ll n,m,k;
    cin>>n>>m>>k;

    ll u,v,w;
    for(int i=0;i<m;i++){
    	cin>>u>>v>>w;
    	u--;
    	v--;
    	adj[u].push_back({w,v});
    }

    ans=0;
    intpair j;
    for(int i=0;i<n;i++){
    	sort(adj[i].begin(),adj[i].end());
    	for(int z=0;z<adj[i].size();z++){
    		j=adj[i][z];
    		if(inAdj[j.second].find({adj[i].size()-1,z})!=inAdj[j.second].end()){
    			forbidden[adj[i].size()-1][z]=true;
    		}
    		else{
	    		inAdj[j.second].insert({adj[i].size()-1,z});
    		}
    	}
    }

    intpair at,bt;
    ll q,x;
    for(int i=0;i<n;i++){
    	// sort(inAdj[i].begin(),inAdj[i].end());
    	q=0;
    	for(auto at:inAdj[i]){
    		w=0;
    		for(auto bt:inAdj[i]){
    			// cerr<<q<<" "<<w<<endl;
    			if(w<=q){
    				w++;
    				continue;
    			}
				pairNotAllowed[at.first][at.second].push_back({bt.first,bt.second});
    			w++;
    		}
    		q++;
    	}
    }

    backTrack(1,0,k);

    cout<<ans<<endl;

}
