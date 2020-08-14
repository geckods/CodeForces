#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

#define MAXN 200001

vector<ll> adj[MAXN];
bool seen[MAXN];
int depth[MAXN];
int childCount[MAXN];
bool isLeaf[MAXN];

void bfs(ll x, ll d){
	depth[x]=d;
	seen[x]=true;

	// if(adj[x].size()==1 && x!=0)isLeaf[x]=true;

	for(auto y:adj[x]){
		if(seen[y])continue;
		bfs(y,d+1);
		childCount[x]+=childCount[y]+1;
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

    ll n,k;
    cin>>n>>k;
    ll x,y;
    for(int i=0;i<n-1;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    memset(seen,false,sizeof(seen));
    memset(depth,0,sizeof(depth));
    memset(childCount,0,sizeof(childCount));

    bfs(0,0);
    // for(int i=0;i<n;i++){
    	// cerr<<i<<" "<<depth[i]<<" "<<childCount[i]<<endl;
    // }

    vector<ll> myVec;
    for(int i=0;i<n;i++){
    	myVec.push_back(depth[i]-childCount[i]);
    }
    sort(myVec.begin(),myVec.end());
    reverse(myVec.begin(),myVec.end());

    ll ans=0;
    for(int i=0;i<k;i++){
    	ans+=myVec[i];
    }
    cout<<ans<<endl;


}
