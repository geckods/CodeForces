#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 100001
vector<vector<int>> adj(MAXN);
vector<vector<int>> queries(MAXN);

typedef pair<int,int> intpair;

map<intpair,int> LCA;
vector<int> ancestor;
vector<bool> visited;

int parent[MAXN];
int ranka[MAXN];

int thedepth[MAXN];

void make_set(int v) {
    parent[v] = v;
    ranka[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranka[a] < ranka[b])
            swap(a, b);
        parent[b] = a;
        if (ranka[a] == ranka[b])
            ranka[a]++;
    }
}


void dfs(int v, int depth)
{
    visited[v] = true;
    ancestor[v] = v;
    thedepth[v]=depth;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u,depth+1);
            union_sets(v, u);
            ancestor[find_set(v)] = v;
        }
    }

    for (int other_node : queries[v]) {
        if (visited[other_node]){
        	LCA[{v,other_node}]=ancestor[find_set(other_node)];
            // cout << "LCA of " << v << " and " << other_node
            //      << " is " << ancestor[find_set(other_node)] << ".\n";
        }
    }
}

void compute_LCAs(int n) {
    // initialize n, adj and DSU
    // for (each query (u, v)) {
    //    queries[u].push_back(v);
    //    queries[v].push_back(u);
    // }

    ancestor.resize(n);
    visited.assign(n, false);
    dfs(0,0);
}


int getdist(int a, int b){
	int thelca=LCA[{a,b}];
	return abs(thedepth[a]-thedepth[thelca])+abs(thedepth[b]-thedepth[thelca]);
}


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int u,v;
    for(int i=0;i<n-1;i++){
    	cin>>u>>v;
    	u--;
    	v--;
		adj[u].push_back(v);
		adj[v].push_back(u);  	
    	make_set(i);
    }
    make_set(n-1);

    int q;
    cin>>q;
    // cerr<<q<<endl;
    int x,y,a,b,k;
    vector<int> temp;
    for(int i=0;i<q;i++){
    	cin>>x>>y>>a>>b>>k;
    	x--;
    	y--;
    	a--;
    	b--;
    	queries[x].push_back(y);
    	queries[x].push_back(a);
    	queries[x].push_back(b);
    	queries[y].push_back(a);
    	queries[y].push_back(b);
    	queries[a].push_back(b);

    	queries[y].push_back(x);
    	queries[a].push_back(x);
    	queries[b].push_back(x);
    	queries[a].push_back(y);
    	queries[b].push_back(y);
    	queries[b].push_back(a);
    	temp.push_back(x);
    	temp.push_back(y);
    	temp.push_back(a);
    	temp.push_back(b);
    	temp.push_back(k);
    }

	compute_LCAs(n);

	for(int i=0;i<temp.size();i+=5){
		x=temp[i];
		y=temp[i+1];
		a=temp[i+2];
		b=temp[i+3];
		k=temp[i+4];

		// cerr<<i<<" "<<a<<" "<<b<<" "<<getdist(a,b)<<endl;
		// cerr<<i<<" "<<x<<" "<<y<<" "<<LCA[{x,y}]<<" "<<getdist(x,y)<<endl;

		bool works=false;
		if((k-getdist(a,b))%2==0){
			works=true;
		}

		int newdist=getdist(a,x)+getdist(y,b)+1;
		// cerr<<i<<" "<<newdist<<endl;
		if(k>=newdist && (k-newdist)%2==0){
			works=true;
		}

		newdist=getdist(a,y)+getdist(x,b)+1;
		// cerr<<i<<" "<<newdist<<endl;
		if(k>=newdist && (k-newdist)%2==0){
			works=true;
		}


		if(works){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

}
    //it's parity based -> if k is shortest(u,v)+2x or if 
