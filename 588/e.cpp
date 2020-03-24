#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll gcd(ll a, ll b){
	if(a==0) return b;
	if(b==0) return a;

	return gcd(b,a%b);
}

// unordered_map<pair<ll,ll>, ll> mainMap;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll n;
   	cin>>n;

   	ll arr[n];
   	for(int i=0;i<n;i++){
   		cin>>arr[i];
   	}

   	vector<ll> adj[n];
   	ll x,y;
   	for(int i=0;i<n-1;i++){
   		cin>>x;
   		cin>>y;
   		x--;
   		y--;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}

   	ll parent[n];

   	for(int i=0;i<n;i++){
   		parent[i]=-2;
   	}

   	queue<pair<ll,ll> > myQ;

   	myQ.push(make_pair(0,-1));
   	pair<ll,ll> curr;
   	while(!myQ.empty()){
   		curr=myQ.front();
   		myQ.pop();
   		parent[curr.first]=curr.second;
   		for(int i=0;i<adj[curr.first].size();i++){
   			if(parent[adj[curr.first][i]]==-2)
	   			myQ.push(make_pair(adj[curr.first][i],curr.first));
   		}
   	}

   	// for(int i=0;i<n;i++){
   	// 	cout<<parent[i]<<" ";
   	// }
   	// cout<<endl;

   	queue<pair<ll,ll> > theQ;
   	for(int i=0;i<n;i++){
   		theQ.push(make_pair(i,arr[i]));
   	}

   	ll ans=0;

   	// pair<ll,ll> newPair;
   	while(!theQ.empty()){
   		curr = theQ.front();
   		theQ.pop();

   		ans+=curr.second;
   		ans%=MOD;

   		if(parent[curr.first]!=-1){

   			theQ.push(make_pair(parent[curr.first],gcd(arr[parent[curr.first]],curr.second)));
   		}

   	}

   	cout<<ans<<endl;

}