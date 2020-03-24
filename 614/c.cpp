#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> llpair;

#define MAXN 3001

bool seen[MAXN];
ll ts[MAXN];
vector<ll> adj[MAXN];
bool marked[MAXN];
// vector<pair<llpair,ll> > adj2[MAXN];
map<llpair,ll> edgeWeight;
map<llpair,ll> allot;
map<llpair,ll> secondallot;


ll subTreeSize(ll node){
	ll ans=1;//this node
	seen[node]=true;
	for(ll i=0;i<adj[node].size();i++){
		if(!seen[adj[node][i]]){
			// cout<<node<<" "<<adj[node][i]<<endl;
			ans+=subTreeSize(adj[node][i]);
		}
	}

	ts[node]=ans;
	return ans;
}

void edgeThrough(ll node,ll n){
	for(ll i=0;i<adj[node].size();i++){
		llpair currpair=make_pair(min(node,adj[node][i]),max(node,adj[node][i]));
		if(edgeWeight[currpair]==-1){
			edgeWeight[currpair]=(n-ts[adj[node][i]])*ts[adj[node][i]];
			edgeThrough(adj[node][i],n);
		}
	}

}

bool compare(llpair a, llpair b){
	return edgeWeight[a]-adj[a.first].size()-adj[a.second].size()>edgeWeight[b]-adj[b.first].size()-adj[b.second].size();
}

ll ogans;

void allMex(ll ognode, ll currnode, set<ll> currSet){
	if(currnode>ognode){
		// cout<<ognode<<" "<<currnode<<" "<<*currSet.begin()<<endl;
		ogans+=*(currSet.begin());
	}
	seen[currnode]=true;
	for(ll i=0;i<adj[currnode].size();i++){
		if(!seen[adj[currnode][i]]){
			//remove from set
			llpair currpair=make_pair(min(currnode,adj[currnode][i]),max(currnode,adj[currnode][i]));
			currSet.erase(currSet.find(allot[currpair]));
			//run bfs
			allMex(ognode, adj[currnode][i],currSet);
			//add to set
			currSet.insert(allot[currpair]);
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

    //keep track of how many paths go through the edge for each edge
    //there are nC2 paths in total - if x paths go through an edge, then nC2-x paths do not
    //allot highest numbers to least frequent edges

    ll n;
    cin>>n;

    memset(seen,false,sizeof(seen));
    memset(marked,false,sizeof(marked));

    memset(ts,0,sizeof(ts));

    vector<llpair> keepTrack;

    for(ll i=0;i<n;i++){
    	adj[i].clear();
    	// adj2[i].clear();
    }

    ll x,y;
    for(ll i=0;i<n-1;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    	llpair currpair = make_pair(min(x,y),max(x,y));
    	edgeWeight[currpair]=-1;
    	keepTrack.push_back(currpair);
    }

    // for(ll i=0;i<n;i++){
    // 	cout<<i+1<<":"<<endl;
    // 	for(ll j=0;j<adj[i].size();j++){
    // 		cout<<adj[i][j]+1<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;

    subTreeSize(0);
    edgeThrough(0,n);

    for(ll i=0;i<keepTrack.size();i++){
    	for(ll j=i+1;j<keepTrack.size();j++){
    		if(keepTrack[i].first==keepTrack[j].first||keepTrack[i].second==keepTrack[j].first||keepTrack[i].first==keepTrack[j].second||keepTrack[i].second==keepTrack[j].second){
    			secondallot[keepTrack[i]]+=edgeWeight[keepTrack[j]];
    			secondallot[keepTrack[j]]+=edgeWeight[keepTrack[i]];

    		}
    	}
    }

    sort(keepTrack.begin(),keepTrack.end(),compare);

    for(ll i=0;i<keepTrack.size();i++){
    	allot[keepTrack[i]]=i;
    	// cout<<keepTrack[i].first<<" "<<keepTrack[i].second<<" "<<edgeWeight[keepTrack[i]]<<" "<<endl;
    }

    ll ans=0;

    set<ll> tempSet;

    for(ll i=0;i<n;i++){
    	tempSet.clear();
    	for(ll j=0;j<n;j++){
    		seen[j]=false;
    		tempSet.insert(j);
    	}
    	ogans=0;
    	allMex(i,i,tempSet);
    	ans+=ogans;
    	// cout<<i<<" "<<ogans<<endl;
    }
    // cout<<endl;
    // for(ll i=0;i<n;i++){
    // 	cout<<i+1<<" "<<ts[i]<<endl;
    // }

    cout<<ans<<endl;

}