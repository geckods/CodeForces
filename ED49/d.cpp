#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 100000
vector<ll> adj[MAXN];
ll cost[MAXN];
bool visited[MAXN];
bool added[MAXN];


int dfs(int x){
	if(visited[x]){
		if(added[x]){
			return 0;
		}
		else{
			return cost[x];
		}
	}
	int mincost = cost[x];
	int tempcost;
	visited[x]=true;
	for(int i=0;i<adj[x].size();i++){
		tempcost = dfs(adj[x][i]);
		if(tempcost<mincost) mincost=tempcost;
	}
	cost[x]=mincost;
	added[x]=true;
	return mincost;
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>cost[i];
    }

    ll ai;
    for(int i=0;i<n;i++){
    	cin>>ai;
    	adj[i].push_back(ai-1);
    }

    for(int i=0;i<MAXN;i++){
    	visited[i]=false;
    	added[i]=false;
    }

    ll ans=0;
   	for(int i=0;i<n;i++){
   		ans+=dfs(i);
   		cout<<ans<<endl;
   	}

   	cout<<ans<<endl;
}
