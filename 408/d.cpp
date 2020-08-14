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

#define MAXN 300001

typedef pair<ll,ll> intpair;

vector<intpair> adj[MAXN];
bool isPolice[MAXN];
bool seen[MAXN];
bool usedEdge[MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k,d;
    cin>>n>>k>>d;

    memset(isPolice,false,sizeof(isPolice));
    memset(seen,false, sizeof(seen));
    memset(usedEdge, false, sizeof(usedEdge));

    ll p;
    for(int i=0;i<k;i++){
    	cin>>p;
    	p--;
    	isPolice[p]=true;
    }

    ll u,v;
    for(int i=0;i<n-1;i++){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].push_back({v,i});
    	adj[v].push_back({u,i});
    }

    queue<intpair> myQ;
    for(int i=0;i<n;i++){
    	if(isPolice[i])myQ.push({i,0});
    }

    // cerr<<myQ.size()<<endl;

    while(!myQ.empty()){
    	intpair front = myQ.front();
    	myQ.pop();
    	// if(seen[front.first])continue;
    	seen[front.first]=true;

    	cerr<<front.first<<endl;
    	for(auto j: adj[front.first]){
    		if(!seen[j.first] && !isPolice[j.first]){
    			seen[j.first]=true;
    			usedEdge[j.second]=true;
    			myQ.push({j.first,front.second+1});
    		}
    	}
    }

    ll rc=0;
    for(int i=0;i<n-1;i++){
    	if(usedEdge[i])rc++;
    }

    cout<<n-1-rc<<endl;

    for(int i=0;i<n-1;i++){
    	if(!usedEdge[i]){
    		cout<<i+1<<" ";
    	}
    }
    cout<<endl;

}