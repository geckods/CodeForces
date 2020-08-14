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

#define MAXN 1001
vector<ll> adj[MAXN];
bool seen[MAXN];
int depth[MAXN];


ll bfs(ll x){
    queue<intpair> myQ;

    ll maxDepth=0;

    myQ.push({x,0});
    while(!myQ.empty()){
        intpair temp = myQ.front();
        myQ.pop();

        // cerr<<temp.first<<" "<<temp.second<<endl;

        depth[temp.first]=temp.second;
        seen[temp.first]=true;

        maxDepth=max(maxDepth,temp.second);

        for(auto y:adj[temp.first]){
            // cerr<<x<<" "<<y<<endl;
            if(!seen[y]){

                seen[y]=true;
                myQ.push({y,temp.second+1});
            }
        }
    }
    return maxDepth;

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

        for(int i=0;i<MAXN;i++){
            adj[i].clear();
            seen[i]=false;
            depth[i]=-1;
        }

        ll n,x;
        cin>>n>>x;

        x--;
        ll u,v;
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll maxDepth = bfs(x);

        ll depthCount[maxDepth+1];
        memset(depthCount,0,sizeof(depthCount));
        for(int i=0;i<n;i++){
            depthCount[depth[i]]++;
        }

        if(adj[x].size()<2){
            cout<<"Ayush"<<endl;
        }
        else{
            bool ayushStart = true;
            depthCount[1]--;
            for(int i=maxDepth;i>=1;i--){
                // cerr<<i<<" "<<depthCount[i]<<endl;
                if(depthCount[i]%2==1){
                    ayushStart=!ayushStart;
                }
            }
            if(ayushStart){
                cout<<"Ayush"<<endl;
            }
            else{
                cout<<"Ashish"<<endl;
            }
        }

    }
}