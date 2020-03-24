#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

vector<vector<ll> > pathVec;

class Graph 
{ 
    int V; // No. of vertices in graph 
    list<int> *adj; // Pointer to an array containing adjacency lists 
  
    // A recursive function used by printAllPaths() 
    void printAllPathsUtil(int , int , bool [], int [], int &); 
  
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v); 
    void printAllPaths(int s, int d); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); // Add v to u’s list. 
} 
  
// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int s, int d) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
  
    // Create an array to store paths 
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 
  
    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print all paths 
    printAllPathsUtil(s, d, visited, path, path_index); 
} 
  
// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int u, int d, bool visited[], 
                            int path[], int &path_index) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // If current vertex is same as destination, then print 
    // current path[] 
    if (u == d) 
    { 
        // for (int i = 0; i<path_index; i++) 
        //     cout << path[i] << " "; 
        // cout << endl;
        pathVec.push_back(vector<ll>());
        for (int i = 0; i<path_index; i++){
            pathVec[pathVec.size()-1].push_back(path[i]);
        }
        
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, d, visited, path, path_index); 
    } 
  
    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
} 
  
ll n,m,t;
ll pathlengtharr[5000][5000];

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>t;
    Graph g(n);

    ll a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        // cout<<a<<b<<endl;
        g.addEdge(a-1,b-1);
        pathlengtharr[a-1][b-1]=c;
    }

    g.printAllPaths(0, n-1);

    // cout<<pathVec.size()<<endl;

    ll time[pathVec.size()];

    int bestSize=0;
    int currBest=-1;

    for(int i=0;i<pathVec.size();i++){
        ll minitime=0;
        for(int j=0;j<pathVec[i].size()-1;j++){
            minitime+=pathlengtharr[pathVec[i][j]][pathVec[i][j+1]];
            if(minitime>t) break;
        }
        // cout<<(pathVec[si].size()>bestSize)<<endl;
        if(pathVec[i].size()>bestSize && minitime<=t){
            bestSize = pathVec[i].size();
            currBest=i;
        }

        // cout<<bestSize<<" "<<pathVec[i].size()<<" "<<minitime<<" "<<t<<endl;
    }

    // cout<<currBest<<endl;
    cout<<pathVec[currBest].size()<<endl;
    for(int i=0;i<pathVec[currBest].size();i++){
        cout<<pathVec[currBest][i]+1<<" ";
    }
    cout<<endl;
}
/*

// Driver program 

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
  
    int s = 2, d = 3; 
    cout << "Following are all different paths from " << s 
        << " to " << d << endl; 
    g.printAllPaths(s, d); 
  
    return 0; 
}
*/