#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

int main(){
/*	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
*/
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> adj[n];
    int a,b;
    for(int i=0;i<m;i++){
    	cin>>a;
    	cin>>b;
    	addEdge(adj,a-1,b-1);
    }

    set<int> seen;
    set<int> neighbors;

    vector<int> ans;
    ans.push_back(1);

    seen.insert(0);
    int curr = 0;
    int min;

    
    while(seen.size()<n){
    	for(int i=0;i<adj[curr].size();i++){
            if(seen.find(adj[curr][i])==seen.end()){
                neighbors.insert(adj[curr][i]);
            }
//            adj[curr].erase(adj[curr].begin+i);
//            adj[adj[curr][i]].remove(curr);
            adj[adj[curr][i]].erase(remove(adj[adj[curr][i]].begin(), adj[adj[curr][i]].end(), curr), adj[adj[curr][i]].end());
    	}

//    	min=10000000;
//    	for (auto it=neighbors.begin(); it != neighbors.end(); ++it){
//    		if(*it<min) min=*it;
//    	}

        min = *neighbors.begin();
    	neighbors.erase(min);
    	seen.insert(min);
    	curr=min;
    	ans.push_back(min+1);
    }

    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
}
