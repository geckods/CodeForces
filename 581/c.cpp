#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<int> > floydWarshall (vector<vector<int> > graph)  
{  
    vector<vector<int> > dist;
    int V=graph.size();

    for(int i=0;i<V;i++){
    	dist.push_back(vector<int>());
    	for(int j=0;j<V;j++){
    		dist[i].push_back(0);
    	}
    }

    int i, j, k;  
  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  

    return dist;
  
}  


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	vector<vector<int> > graph;

   	char x;
   	for(int i=0;i<n;i++){
   		graph.push_back(vector<int>());
   		for(int j=0;j<n;j++){
   			cin>>x;
   			if(x=='1'){
   				graph[i].push_back(1);
   			}
   			else{
	   			graph[i].push_back(9999);
	   		}
   		}
   	}

   	vector<vector<int> > dist = floydWarshall(graph);

   	for(int i=0;i<n;i++){
   		dist[i][i]=0;
   	}


   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<n;j++){
   	// 		cout<<dist[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }

   	int m;
   	cin>>m;
   	vector<int> p;
   	for(int i=0;i<m;i++){
   		int x;
   		cin>>x;
   		p.push_back(x);
   	}


   	int i=0;
   	int j;
   	vector<int> sol;
   	sol.push_back(p[0]);
   	while(i<m){
   		j=i+1;
   		while(j<m && dist[p[i]-1][p[j]-1] >= (j-i)){
   			// cout<<i<<" "<<j<<" "<<p[i]<<" "<<p[j]<<" "<<dist[p[i]-1][p[j]-1]<<endl;
   			j++;
   		}
   		// cout<<"J"<<j<<endl;
   		j--;
   		sol.push_back(p[j]);
   		if(j==m-1){
   			break;
   		}
   		else{
   			i=j;
   		}
   	}

   	cout<<sol.size()<<endl;
   	for(int i=0;i<sol.size();i++){
   		cout<<sol[i]<<" ";
   	}
   	cout<<endl;
}