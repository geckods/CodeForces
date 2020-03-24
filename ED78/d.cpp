#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], int parent); 
public: 
    int edgeCount;
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isCyclic();   // returns true if there is a cycle 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
    edgeCount=0;
} 
  
void Graph::addEdge(int v, int w) 
{ 
	edgeCount++;
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Add v to w’s list. 
} 
  
// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        // If an adjacent is not visited, then recur for that adjacent 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        // If an adjacent is visited and not parent of current vertex, 
        // then there is a cycle. 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for (int u = 0; u < V; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
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

    int arr[n][2];
    for(int i=0;i<n;i++){
    	cin>>arr[i][0]>>arr[i][1];
    	arr[i][0]--;
    	arr[i][1]--;
    }

    int oc[2*n];
    int whichoc[2*n];
    for(int i=0;i<n;i++){
    	oc[arr[i][0]]=1;
    	oc[arr[i][1]]=-1;

    	whichoc[arr[i][0]]=i+1;
    	whichoc[arr[i][1]]=-i-1;
    }

    // for(int i=0;i<2*n;i++){
    // 	cout<<i<<" "<<whichoc[i]<<endl;
    // }

    int pref[2*n];
    pref[0]=oc[0];
    for(int i=1;i<2*n;i++){
    	pref[i]=pref[i-1]+oc[i];
    	if(pref[i]==0&&i!=2*n-1){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    }

    map<int,int> myMap;//i to level
    set<pair<int,int> > currOpen;

    Graph g1(n+1);
    for(int i=0;i<2*n;i++){
    	// cerr<<i<<" "<<currOpen.size()<<" "<<whichoc[i]<<endl;
    	if(whichoc[i]>0){
    		//opening
    		myMap[whichoc[i]]=i;
    		currOpen.insert({i,whichoc[i]});
    	}
    	else{
    		auto it=currOpen.lower_bound({myMap[-1*whichoc[i]],-1});
    		auto newit=it;
    		// cerr<<i<<" "<<whichoc[i]<<" "<<myMap[-1*whichoc[i]]<<endl;
    		// cerr<<it->second<<endl;
    		newit++;
    		while(newit!=currOpen.end()){
    			// cerr<<newit->second<<" "<<whichoc[i]<<endl;
	    		// cerr<<"HI"<<endl;
    			g1.addEdge(-1*(whichoc[i]),newit->second);
    			if(g1.edgeCount>n-1){
    				cout<<"NO"<<endl;
    				return 0;
    			}
    			newit++;
    		}
    		currOpen.erase(it);
    	}
    }

    if(g1.edgeCount < n-1 || g1.isCyclic()){
    	cout<<"NO"<<endl;
    }
    else{
    	cout<<"YES"<<endl;
    }


}
