#include <bits/stdc++.h>
using namespace std;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use intONG_MAX/intONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef pair<int,int> intpair;

#define MAXN 2000

int board[MAXN][MAXN];
bool seen[MAXN][MAXN];
int dist[MAXN][MAXN];
int thisMin[MAXN][MAXN];

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    getchar();
    for(int i=0;i<n;i++){
    	// string s;
    	// cin>>s;
    	for(int j=0;j<m;j++){
    		board[i][j]=getchar()-'a';
    		// cerr<<i<<" "<<j<<" "<<board[i][j]<<endl;
    	}
    	getchar();
    }

    int minDist;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
			dist[i][j]=INT_MAX;
	   		minDist = i+1;
	   		minDist=min(minDist,j+1);
	   		minDist=min(minDist,n-i);
	   		minDist=min(minDist,m-j);
			thisMin[i][j]=minDist;
    	}
    }

    for(int letter = 0;letter<26;letter++){
    	queue<pair<intpair,int>> myQ;

    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			seen[i][j]=false;
    			if(board[i][j]==letter){
    				myQ.push({{i,j},0});
	    			seen[i][j]=true;
    			}
    		}
    	}

		int i,j,d;
		pair<intpair,int> temp;
    	while(!myQ.empty()){
    		temp = myQ.front();
    		myQ.pop();

    		i = temp.first.first;
    		j = temp.first.second;
    		d = temp.second;

    		if(d>=dist[i][j])continue;

    		if(board[i][j]!=letter)
	    		dist[i][j]=min(dist[i][j],d);

    		if(d>=thisMin[i][j])continue;

    		if(i>0 && !seen[i-1][j]){
    			myQ.push({{i-1,j},d+1});
    			seen[i-1][j]=true;
    		}

    		if(j>0 && !seen[i][j-1]){
    			myQ.push({{i,j-1},d+1});
    			seen[i][j-1]=true;    			
    		}

    		if(i<n-1 && !seen[i+1][j]){
    			myQ.push({{i+1,j},d+1});
    			seen[i+1][j]=true;
    		}

    		if(j<m-1 && !seen[i][j+1]){
    			myQ.push({{i,j+1},d+1});
    			seen[i][j+1]=true;    			
    		}
    	}
    }

    int ans=0;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		minDist = dist[i][j];
    		minDist = min(minDist,thisMin[i][j]);
	   		ans+=minDist;
    	}
    }

    cout<<ans<<endl;


}