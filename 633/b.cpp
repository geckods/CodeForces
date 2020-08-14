#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
#define MAXN 100001

bool hasEvenLeaf[MAXN];
bool hasOddLeaf[MAXN];
bool seen[MAXN];
bool isLeaf[MAXN];
int leafCount[MAXN];

vector<ll> adj[MAXN];

void bfs(int x){
	if(adj[x].size()==1){
		isLeaf[x]=true;
		hasEvenLeaf[x]=true;
	}
	seen[x]=true;
	for(auto it:adj[x]){
		if(!seen[it]){
			bfs(it);
		}
	}

	for(auto it:adj[x]){
		// cerr<<x<<" "<<it<<endl;
		if(hasEvenLeaf[it])hasOddLeaf[x]=true;
		if(hasOddLeaf[it])hasEvenLeaf[x]=true;
		if(hasEvenLeaf[x])hasOddLeaf[it]=true;
		if(hasOddLeaf[x])hasEvenLeaf[it]=true;
	}

}

void bfs2(int x){
	if(isLeaf[x]){
		// isLeaf[x]=true;
		hasEvenLeaf[x]=true;
	}
	seen[x]=true;
	for(auto it:adj[x]){
		// // cerr<<x<<" "<<it<<endl;
		// 	if(hasEvenLeaf[it])hasOddLeaf[x]=true;
		// 	if(hasOddLeaf[it])hasEvenLeaf[x]=true;
		// 	if(hasEvenLeaf[x])hasOddLeaf[it]=true;
		// 	if(hasOddLeaf[x])hasEvenLeaf[it]=true;
		// if(seen[it]){

		// }
		// else{
		// 	bfs(it);
		// }
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

    ll n;
    cin>>n;

    ll a,b;
    for(int i=0;i<n-1;i++){
    	cin>>a>>b;
    	a--;
    	b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    memset(hasOddLeaf,false,sizeof(hasOddLeaf));
    memset(hasEvenLeaf,false,sizeof(hasEvenLeaf));
    memset(seen,false,sizeof(seen));
    memset(isLeaf,false,sizeof(isLeaf));
    memset(leafCount,0,sizeof(leafCount));

    bfs(0);


    ll minAns=1;
    for(int i=0;i<n;i++){
    	// cerr<<<<endl;
    	// cerr<<i<<" "<<hasEvenLeaf[i]<<" "<<hasOddLeaf[i]<<endl;
    	if(hasEvenLeaf[i]&&hasOddLeaf[i]){
    		minAns=3;
    		break;
    	}
    }

    // bool isLine=true;
    // for(int i=0;i<n;i++){
    // 	if(adj[i].size()>2)isLine=false;
    // }

    // if(isLine && n%2==0)
    // cout<<minAns<<endl;

    for(int i=0;i<n;i++){
    	for(auto it:adj[i]){
    		if(isLeaf[it])leafCount[i]++;
    	}
    }

    ll maxAns=n-1;
    for(int i=0;i<n;i++){
    	maxAns-=max((leafCount[i]-1),0);
    }

    cout<<minAns<<" "<<maxAns<<endl;

    // minimum is either 1 or 3



}