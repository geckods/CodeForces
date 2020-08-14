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

#define MAXN 200001
vector<ll> adj[MAXN];
typedef pair<ll,ll> intpair;

bool visited[MAXN];
bool inStack[MAXN];

stack<ll> myStack;

void clearGraph(ll n){
	for(int i=0;i<n;i++){
		adj[i].clear();
		visited[i]=false;
		inStack[i]=false;
	}
	while(!myStack.empty())myStack.pop();
}

bool isCyclicUtil(ll x){
	if (!visited[x]){
		visited[x]=true;
		inStack[x]=true;

		for(auto it: adj[x]){
			if(inStack[it]){
				return true;
			}
			if(!visited[it] && isCyclicUtil(it)){
				return true;
			}
		}
	}
	inStack[x]=false;
	return false;
}

bool isCyclic(ll n){
	for(int i=0;i<n;i++){
		if(isCyclicUtil(i)){
			// cerr<<i<<" "<<endl;
			return true;
		}
	}
	return false;
}

void topoSortUtil(ll x){
	visited[x]=true;
	for(auto it: adj[x]){
		if(!visited[it]){
			topoSortUtil(it);
		}
	}
	myStack.push(x);
}

vector<ll> topoSort(ll n){
	for(int i=0;i<n;i++){
		if(!visited[i]){
			topoSortUtil(i);
		}
	}

	vector<ll> ans;
	while(!myStack.empty()){
		ans.push_back(myStack.top());
		myStack.pop();
	}
	return ans;
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
    	ll n,m;
    	cin>>n>>m;
    	clearGraph(n);

    	vector<pair<int,intpair>> edgesToAssign;

    	ll t,x,y;
    	for(int i=0;i<m;i++){
    		cin>>t>>x>>y;
    		x--;
    		y--;
			edgesToAssign.push_back({t,{x,y}});
    		if(t!=0){
    			adj[x].push_back(y);
    			// adj[y].push_back(x);
    		}
    	}

    	// check if it is cyclic
    	if(isCyclic(n)){
    		cout<<"NO"<<endl;
    		continue;
    	}

		cout<<"YES"<<endl;

		for(int i=0;i<n;i++){
			visited[i]=false;
		}

		vector<ll> topo = topoSort(n);

		ll pos[n];
		memset(pos,-1,sizeof(pos));

		for(int i=0;i<topo.size();i++){
			pos[topo[i]]=i;
		}

		for(int i=0;i<m;i++){
			// cerr<<edgesToAssign[i].first<<" "<<edgesToAssign[i].second.first<<" "<<edgesToAssign[i].second.second<<endl;
			if(edgesToAssign[i].first==1){
				cout<<edgesToAssign[i].second.first+1<<" "<<edgesToAssign[i].second.second+1<<endl;
			}
			else{
				intpair thePair = edgesToAssign[i].second;
				if(pos[thePair.first]<pos[thePair.second]){
					cout<<thePair.first+1<<" "<<thePair.second+1<<endl;
				}
				else{
					cout<<thePair.second+1<<" "<<thePair.first+1<<endl;					
				}
			}
		}

    }
}