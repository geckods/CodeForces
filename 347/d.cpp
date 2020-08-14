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

#define MAXN 100001
ll dp[MAXN][2][2];
bool seen[MAXN];
bool leaf[MAXN];
char color[MAXN];
ll parentVertex[MAXN];
bool isBackEdge[MAXN];

vector<pair<ll, ll> > adj[MAXN];

void dfs_leaf(ll x, ll parent){
	parentVertex[x]=parent;
	seen[x]=true;
	ll sc=0;
	for(auto y:adj[x]){
		if(!seen[y.first]){
			sc++;
			dfs_leaf(y.first, x);
		}
		else{
			if(y.first!=parent){
				isBackEdge[y.second]=true;
			}
		}
	}

	if(sc==0){
		leaf[x]=true;
	}
}

// 0 blue, 1 red
// 0 not toggle, 1 toggle

void dfs_dp(ll x){
	seen[x]=true;
	if(leaf[x]){
		dp[x][0][0]=dp[x][1][0]=0;
		dp[x][0][1]=dp[x][1][1]=0;
	}
	else{
		for(auto y: adj[x]){
			if(!seen[y.first]){
				dfs_dp(y.first);
				if(color[y.second]=='B'){
					dp[x][0][0]+=dp[y.first][0][0];
					dp[x][0][1]+=dp[y.first][0][1];
					dp[x][1][0]+=dp[y.first][1][1];
					dp[x][1][1]+=dp[y.first][1][0];
				}
				else{
					dp[x][0][0]+=dp[y.first][0][1];
					dp[x][0][1]+=dp[y.first][0][0];
					dp[x][1][0]+=dp[y.first][1][0];
					dp[x][1][1]+=dp[y.first][1][1];					
				}
			}
		}
	}
	dp[x][0][1]++;
	dp[x][1][1]++;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    ll x,y;
    char c;
    for(int i=0;i<m;i++){
    	cin>>x>>y>>c;
    	x--;
    	y--;
    	adj[x].push_back({y,i});
    	adj[y].push_back({x,i});
    	color[i]=c;
    }

    dfs_leaf(0, -1);
    memset(seen,false, sizeof(seen));
    dfs_dp(0);

    // for(int i=0;i<n;i++){
    // 	cerr<<i<<" "<<leaf[i]<<endl;
    // }
    // for(int i=0;i<m;i++){
    // 	cerr<<i<<" "<<isBackEdge[i]<<endl;
    // }

    cout<<dp[0][0][0]<<endl;
    cout<<dp[0][0][1]<<endl;
    cout<<dp[0][1][0]<<endl;
    cout<<dp[0][1][1]<<endl;

    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<2;j++){
    // 		for(int k=0;k<2;k++){
    // 			cerr<<i<<" "<<j<<" "<<k<<endl;
    // 			cerr<<dp[i][j][k]<<endl;
    // 		}
    // 	}
    // }

    // cout<<min(dp[0][0][0],dp[0][0][1],dp[0][1][0],dp[0][1][1])<<endl;




}