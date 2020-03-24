#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	vector<int> adj[n];

   	int u,v;
   	for(int i=0;i<n-1;i++){
   		cin>>u>>v;
   		u--;
   		v--;

   		adj[u].push_back(v);
   		adj[v].push_back(u);
   	}

   	for(int i=0;i<n;i++){
   		if(adj[i].size()==2){
   			// int j = adj[i][0];
   			// if(adj[j].size()==2){
   				cout<<"NO"<<endl;
   				return 0;
   			// }
   		}
   	}

   	cout<<"YES"<<endl;
}