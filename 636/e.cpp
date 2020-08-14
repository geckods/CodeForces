#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

#define endl '\n'
#define MAXN 200001

vector<ll> adj[MAXN];
ll p[MAXN];
ll prefp[MAXN];
bool seen[MAXN];
ll Adist[MAXN];
ll Bdist[MAXN];
ll Cdist[MAXN];

void bfsa(ll a){
	queue<ll> myQ;
	Adist[a]=0;
	myQ.push(a);
	while(!myQ.empty()){
		ll curr=myQ.front();
		seen[curr]=true;
		myQ.pop();
		for(auto y:adj[curr]){
			Adist[y]=min(Adist[y],Adist[curr]+1);
			if(seen[y])continue;
			seen[y]=true;
			myQ.push(y);
		}
	}
}


void bfsb(ll b){
	queue<ll> myQ;
	Bdist[b]=0;
	myQ.push(b);
	while(!myQ.empty()){
		ll curr=myQ.front();
		seen[curr]=true;
		myQ.pop();
		for(auto y:adj[curr]){
			Bdist[y]=min(Bdist[y],Bdist[curr]+1);
			if(seen[y])continue;
			seen[y]=true;
			myQ.push(y);
		}
	}
}


void bfsc(ll c){
	queue<ll> myQ;
	Cdist[c]=0;
	myQ.push(c);
	while(!myQ.empty()){
		ll curr=myQ.front();
		seen[curr]=true;
		myQ.pop();
		for(auto y:adj[curr]){
			Cdist[y]=min(Cdist[y],Cdist[curr]+1);
			if(seen[y])continue;
			seen[y]=true;
			myQ.push(y);
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


    ll t;
    cin>>t;
    while(t--){
    	ll n,m,a,b,c;
    	cin>>n>>m>>a>>b>>c;
	    // get length of paths from C to every node
    	a--;
    	b--;
    	c--;

    	for(int i=0;i<n;i++){
    		adj[i].clear();
    		seen[i]=false;
    		Adist[i]=Bdist[i]=Cdist[i]=INT_MAX;
    	}

	    for(int i=0;i<m;i++){
	    	p[i]=prefp[i]=0;
	    	cin>>p[i];
	    	// prefp[m+i]=prefp[2*m+i]=prefp[3*m+i]=1e15;
	    }

	    ll x,y;
	    for(int i=0;i<m;i++){
	    	cin>>x>>y;
	    	x--;
	    	y--;
	    	adj[x].push_back(y);
	    	adj[y].push_back(x);
	    }

	    sort(p,p+m);
	    prefp[0]=p[0];
	    for(int i=1;i<m;i++)prefp[i]=prefp[i-1]+p[i];


	    bfsa(a);
		for(int i=0;i<n;i++)seen[i]=false;
	    bfsb(b);
		for(int i=0;i<n;i++)seen[i]=false;	
	    bfsc(c);

	    ll ans=LLONG_MAX;

	    // ll minAC=INT_MAX;
	    // for(int i=0;i<n;i++){
	    	// cerr<<i<<" "<<Adist[i]<<" "<<Bdist[i]<<" "<<Cdist[i]<<endl;
	    // }

	    for(int i=0;i<n;i++){
	    	// cerr<<i<<" "<<Adist[i]<<" "<<Bdist[i]<<" "<<Cdist[i]<<endl;
	    	ll miniAns=0;
	    	if(Bdist[i]>0){
	    		miniAns+=prefp[Bdist[i]-1];
	    	}
	    	// cerr<<i<<" "<<miniAns<<endl;
	    	if(Bdist[i]+Adist[i]+Cdist[i]>0){
	    		if(Bdist[i]+Adist[i]+Cdist[i]>m){
	    			miniAns=LLONG_MAX;
	    		}
	    		else{
			    	miniAns+=prefp[Bdist[i]+Adist[i]+Cdist[i]-1];
	    		}
	    	}
	    	// cerr<<i<<" "<<miniAns<<" "<<Adist[i]<<" "<<Bdist[i]<<" "<<Cdist[i]<<endl;
	    	ans=min(ans,miniAns);

	    	// ans=min(ans,prefp[Bdist[i]]+prefp[min(Bdist[i]+Adist[i]+Cdist[i],m-1)]);
	    }
	    // cerr<<"HI"<<endl;
	    cout<<ans<<endl;

    }
}