#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;
#define MAXN 200001
vector<ll> adj[MAXN];

ll dist1[MAXN];
ll distn[MAXN];

bool visited[MAXN];

bool compare(intpair a, intpair b){
	return a.first-a.second<b.first-b.second;
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

    ll special[k];
    for(int i=0;i<k;i++){
    	cin>>special[i];
    	special[i]--;
    }

    ll x,y;
    for(int i=0;i<m;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    queue<intpair> myQ;
    myQ.push({0,0});

    for(int i=0;i<n;i++){
    	visited[i]=false;
    }

    while(!myQ.empty()){
    	intpair thepair=myQ.front();
    	myQ.pop();
    	// if(visited[thepair.first])continue;
    	visited[thepair.first]=true;
    	dist1[thepair.first]=thepair.second;
    	// cerr<<thepair.first<<" "<<thepair.second<<endl;
    	for(auto i:adj[thepair.first]){
    		if(visited[i])continue;
    		visited[i]=true;
    		myQ.push({i,thepair.second+1});
    	}
    }

    for(int i=0;i<n;i++){
    	visited[i]=false;
    }


    myQ.push({n-1,0});

    while(!myQ.empty()){
    	intpair thepair=myQ.front();
    	myQ.pop();
    	// if(visited[thepair.first])continue;
    	visited[thepair.first]=true;
    	distn[thepair.first]=thepair.second;
    	for(auto i:adj[thepair.first]){
    		if(visited[i])continue;
    		visited[i]=true;
    		myQ.push({i,thepair.second+1});
    	}
    }

    //sort vector by dist1, get bestdistn back
    vector<intpair> myVec;
    for(int i=0;i<k;i++){
    	myVec.push_back({dist1[special[i]],distn[special[i]]});
    	// cerr<<i<<" "<<special[i]<<" "<<dist1[special[i]]<<" "<<distn[special[i]]<<endl;
    }
    // cerr<<"HI"<<endl;

    ll ans=0;

    sort(myVec.begin(),myVec.end(), compare);
    // reverse(myVec.begin(),myVec.end());

    //take all length through that paths, get max of them

    ll backbest[k];
    backbest[k-1]=myVec[k-1].second;

    for(int i=k-2;i>=0;i--){
    	// cerr<<i<<" "<<myVec[i].first<<" "<<myVec[i].second<<endl;
    	ans=max(ans,myVec[i].first+backbest[i+1]+1);
    	backbest[i]=max(backbest[i+1],myVec[i].second);
    }

    // cout<<dist1[n-1]<<endl;
    cout<<min(ans,dist1[n-1])<<endl;

    //sort by a1-a2=z
    //anything with b1-b2>z will go through ax

}
    //mark all distances from 1
    //mark all distances from n
