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
#define MAXN 200000
vector<int> adj[MAXN];

bool isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
         
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool isCyclic(int n) 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[n]; 
    bool *recStack = new bool[n]; 
    for(int i = 0; i < n; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < n; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
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

    ll n,m;
    cin>>n>>m;

    ll x;
    ll y;

    bool hasInEdge[n];
    memset(hasInEdge,false,sizeof(hasInEdge));
    for(int i=0;i<m;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	hasInEdge[y]=true;
    	adj[x].push_back(y);
    }

    // cout<<isCyclic(n)<<endl;
    if(isCyclic(n)){
    	cout<<-1<<endl;
    }
    else{
    	int count=0;
    	for(int i=0;i<n;i++){    		
    		if(!hasInEdge[i]){
    			count++;
    		}
    	}
    	cout<<count<<endl;
    	for(int i=0;i<n;i++){
    		if(!hasInEdge[i]){
    			cout<<'A';
    		}
    		else{
    			cout<<'E';
    		}    		
    	}
    	cout<<endl;
    }

}