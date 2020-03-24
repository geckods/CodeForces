#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define MAXN 1500
#define MAXM 1500

int arr[MAXN][MAXN];
// int newarr[MAXN*9][MAXN*9];

void paintColor(int i, int j, int n, int m, int c){
	if(arr[i][j]!=0)return;
	arr[i][j]=c;
	if(i>0 && arr[i-1][j]==0){
		paintColor(i-1,j,n,m,c);
	}
	if(j>0 && arr[i][j-1]==0){
		paintColor(i,j-1,n,m,c);
	}
	if(i<n-1 && arr[i+1][j]==0){
		paintColor(i+1,j,n,m,c);
	}
	if(j<m-1 && arr[i][j+1]==0){
		paintColor(i,j+1,n,m,c);
	}

}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;


    int ogi;
    int ogj;

    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	for(int j=0;j<m;j++){
    		if(s[j]=='#'){
    			arr[i][j]=-1;
    		}
    		else{
    			if(s[j]=='S'){
    				ogi=i;
    				ogj=j;
    			}
    			arr[i][j]=0;
    		}
    	}
    }

    int c=1;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(arr[i][j]==0){
    			paintColor(i,j,n,m,c);
    			c++;
    		}
    	}
    }

    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<m;j++){
    // 		cout<<arr[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    //you add edges to the graph only if they meet in a new edges

    vector<pair<int,int>> adj[c-1];

    set<pair<int,pair<int,int>>> testSet;

    for(int j=0;j<m;j++){
    		// cerr<<j<<endl;
    	if(arr[0][j]!=-1 && arr[n-1][j]!=-1){
    		if(testSet.find({arr[0][j]-1,{arr[n-1][j]-1,2000}})==testSet.end()){
	    		adj[arr[0][j]-1].push_back({arr[n-1][j]-1,2000});
	    		testSet.insert({arr[0][j]-1,{arr[n-1][j]-1,2000}});    			
    		}
    		if(testSet.find({arr[n-1][j]-1,{arr[0][j]-1,-2000}})==testSet.end()){
	    		adj[arr[n-1][j]-1].push_back({arr[0][j]-1,-2000});
	    		testSet.insert({arr[n-1][j]-1,{arr[0][j]-1,-2000}});
	    	}

    	}
    }

    for(int i=0;i<n;i++){
    	if(arr[i][0]!=-1&& arr[i][m-1]!=-1){
    		if(testSet.find({arr[i][0]-1,{arr[i][m-1]-1,1}})==testSet.end()){
	    		adj[arr[i][0]-1].push_back({arr[i][m-1]-1,1});
	    		testSet.insert({arr[i][0]-1,{arr[i][m-1]-1,1}});
	    	}
    		if(testSet.find({arr[i][m-1]-1,{arr[i][0]-1,-1}})==testSet.end()){
    			adj[arr[i][m-1]-1].push_back({arr[i][0]-1,-1});
	    		testSet.insert({arr[i][m-1]-1,{arr[i][0]-1,-1}});
	    	}
    	}
    }

    // for(int i=0;i<c-1;i++){
    // 	cout<<i<<": "<<endl;
    // 	for(int j=0;j<adj[i].size();j++){
    // 		cout<<adj[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    map<pair<int,int>,bool> visited;
    // memset(visited,0,sizeof(visited));
    queue<pair<int,int>> curr;
    int thestart=arr[ogi][ogj]-1;
    curr.push({thestart,0});

    bool works=false;
    while(curr.size()>0){
    	pair<int,int> thenext = curr.front();
    	curr.pop();

    	int nextone=thenext.first;
    	int val = thenext.second;

    	if(nextone==thestart && val!=0){
    		works=true;
    		break;
    	}

    	// cout<<nextone<<" "<<val<<endl;

    	visited[thenext]=true;
    	for(int i=0;i<adj[nextone].size();i++){
    		if(adj[nextone][i].first==thestart && val+adj[nextone][i].second!=0){
    			works=true;
    			break;
    		}
	    // cerr<<"HI"<<endl;
    		if(!visited[{adj[nextone][i].first,val+adj[nextone][i].second}]){
    			curr.push({adj[nextone][i].first,val+adj[nextone][i].second});
    			visited[{adj[nextone][i].first,val+adj[nextone][i].second}]=true;
    		}
    	}
    	if(works)break;
    }

    cout<<(works?"Yes":"No")<<endl;


}
