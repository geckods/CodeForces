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

#define MAXN 200001

vector<ll> adj[MAXN];
ll imbalance[MAXN]; //difference in desired one count and actual onceount
ll zc[MAXN];
ll oc[MAXN];
ll unmatched[MAXN];
ll dp[MAXN];
ll desiredoc[MAXN];

bool seen[MAXN];

ll a[MAXN];
ll b[MAXN];
ll c[MAXN];

void fillArrays(ll x){
	bool isLeaf = true;
	seen[x]=true;
	for(auto y:adj[x]){
		if(!seen[y]){
			isLeaf=false;
			break;
		}
	}

	ll dpSum=0;
	ll leftOver=0;
	ll imSum=0;
	ll absSum=0;

	if(isLeaf){
		if(b[x]==1){
			oc[x]=1;
			zc[x]=0;
		}
		else{
			zc[x]=1;
			oc[x]=0;
		}

		if(c[x]==1){
			desiredoc[x]=1;
		}
		else{
			desiredoc[x]=0;
		}

		if(b[x]==c[x]){
			unmatched[x]=0;
		}
		else{
			unmatched[x]=1;
		}

		// leftOver=unmatched[x];
	}
	else{
		if(b[x]==1)oc[x]++;
		else zc[x]++;

		if(c[x]==1)desiredoc[x]++;

		if(b[x]!=c[x]){
			unmatched[x]++;
			absSum++;
		}


		for (auto y:adj[x]){

			if(!seen[y]){

				a[y]=min(a[y],a[x]);

				fillArrays(y);
				oc[x]+=oc[y];
				zc[x]+=zc[y];
				desiredoc[x]+=desiredoc[y];
				unmatched[x]+=unmatched[y];

				dpSum+=min(dp[y],a[x]*(unmatched[y]-imbalance[y]));
				absSum+=abs(imbalance[y]);
			}
		} 
	}

	imbalance[x]=oc[x]-desiredoc[x];


	dp[x]=a[x]*(unmatched[x]-imbalance[x]);
	dp[x]=min(dp[x],dpSum+a[x]*(absSum-abs(imbalance[x])));

	if(isLeaf)dp[x]=0;
	// cerr<<x<<" "<<absSum<<" "<<unmatched[x]<<" "<<imbalance[x]<<" "<<dp[x]<<endl;
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

    ll moc=0;
    ll mdoc=0;

    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i]>>c[i];
    	moc+=b[i];
    	mdoc+=c[i];
    	imbalance[i]=zc[i]=oc[i]=unmatched[i]=dp[i]=0;
    	seen[i]=false;
    }

    ll u,v;
    for(int i=0;i<n-1;i++){
    	cin>>u>>v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    if(moc!=mdoc){
    	cout<<-1<<endl;
    	return 0;
    }

    fillArrays(0);

    cout<<dp[0]<<endl;

}