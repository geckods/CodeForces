#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 2001

typedef pair<ll,ll> intpair;

ll where[MAXN][MAXN+2];
ll weight[MAXN][MAXN+2];
ll isCycle[MAXN][MAXN+2];

vector<intpair> adj[MAXN];

void fillArrays(ll n){
	map<ll,ll> myMap;

	for(auto j:adj[x]){
		myMap[j.first]=j.second;
	}

	for(int i=1;i<=MAXN+1;i++){
		ll shp = LLONG_MAX;
		ll shc = LLONG_MAX;
		for(auto it:myMap){
			shp=min(shp,it.second);
			if(it.first==x){
				shc=min(shc,it.second);
			}
		}
		weight[x][i]=shp;
		isCycle[x][i]=shc;

		map<ll,ll> temp;
		for(auto it:myMap){
			for(auto jt:adj[it.first]){
				
			}
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

    ll n,m,q;
    cin>>n>>m>>q;

    // dp[i][j] -> intpair the shortest path from node i of length j goes where and scores what
    ll u,v,w;
    for(int i=0;i<m;i++){
    	cin>>u>>v>>w;
    	u--;
    	v--;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    } 

    for(int i=0;i<n;i++){
    	fillArrays(i);
    }


}
