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
 
bool inCount[MAXN];
vector<ll> edgeList[9][9];
unordered_set<ll> edgeListSet[9][9];
 
bool forbidden[9][9];
 
ll ans;
 
void backTrack(ll k, ll x, ll maxK){
	if(forbidden[k-1][x]){
		return;
	}
 
    ll it;
    for(int i=0;i<edgeList[k-1][x].size();i++){
        it = edgeList[k-1][x][i];
		if(inCount[it]){
			return;
		}
    }
 
 
	if(k==maxK){
		ans++;
	}
	else{
        for(int i=0;i<edgeList[k-1][x].size();i++){
            it = edgeList[k-1][x][i];
			inCount[it]=true;
        }

		for(int j=0;j<k+1;j++){
			if(forbidden[k][j]){
				continue;
			}
 
			backTrack(k+1,j,maxK);
		}
        for(int i=0;i<edgeList[k-1][x].size();i++){
            it = edgeList[k-1][x][i];
            inCount[it]=false;
        }
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
            j = adj[i][z];
    		edgeList[adj[i].size()-1][z].push_back(j.second);
    		edgeListSet[adj[i].size()-1][z].insert(j.second);
    	}
    }
 
    for(int i=0;i<k;i++){
    	for(int j=0;j<k;j++){
    		if(edgeListSet[i][j].size()<edgeList[i][j].size()){
    			forbidden[i][j]=true;
    		}
    		else{
    			forbidden[i][j]=false;
    		}
    	}
    }
 
    backTrack(1,0,k);
 
    cout<<ans<<endl;
 
}