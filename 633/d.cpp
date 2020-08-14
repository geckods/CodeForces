#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define MAXN 100001
vector<ll> adj[MAXN];

#define endl '\n'

pair<int, int> bfs(int u, int n) 
{ 
    //  mark all distance with -1 
    int dis[n]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
  
            if (dis[v] == -1) 
            { 
                q.push(v); 
  
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    //  get farthest node distance and its index 
    for (int i = 0; i < n; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
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

    ll x,y;
    for(int i=0;i<n-1;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    pair<int, int> t1, t2; 
  
    t1 = bfs(0,n); 
 
    t2 = bfs(t1.first,n); 

	cout<<ceil(((double)t2.second)/2)<<endl;
}  