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

void recFill(vector<vector<int>> &grid, int i, int j, int n, int m){
	grid[i][j]=2;
	if(i>0 && grid[i-1][j]==1){
		recFill(grid,i-1,j,n,m);
	}

	if(i<n-1 && grid[i+1][j]==1){
		recFill(grid,i+1,j,n,m);
	}

	if(j>0 && grid[i][j-1]==1){
		recFill(grid,i,j-1,n,m);
	}

	if(j<m-1 && grid[i][j+1]==1){
		recFill(grid,i,j+1,n,m);
	}

}

int floodFill(vector<vector<int>> grid, int n, int m){
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==1){
				ans++;
				recFill(grid,i,j,n,m);
			}			
		}
	}
	return ans;
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

    vector<vector<int>> grid;
    string s;
    bool hasBlack=false;
    for(int i=0;i<n;i++){
    	grid.push_back(vector<int>());
    	cin>>s;
    	for(int j=0;j<m;j++){
    		if(s[j]=='.'){
	    		grid[i].push_back(0);
    		}
    		else{
    			grid[i].push_back(1);
    			hasBlack=true;
    		}
    	}
    }
    if(!hasBlack){
    	cout<<0<<endl;
    	return 0;
    }

    bool hasBlackRow[n];
    bool hasBlackCol[m];


    bool allRowsBlack=true;
    bool allColsBlack=true;

    for(int i=0;i<n;i++){
    	bool seenBlack=false;
    	bool seenWhite=false;
    	for(int j=0;j<m;j++){
    // cerr<<grid.size()<<" "<<grid[0].size()<<" "<<grid[0][0]<<endl;
    		if(grid[i][j]==1){
    			if(!seenBlack){
    				seenBlack=true;
    			}
    			else{
    				if(seenWhite){
    					cout<<-1<<endl;
    					return 0;
    				}
    			}
    		}
    		else{
    			if(seenBlack){
    				seenWhite=true;
    			}
    		}
    	}
    	hasBlackRow[i]=seenBlack;
    	if(!seenBlack)allRowsBlack=false;
    }

    for(int j=0;j<m;j++){
    	bool seenBlack=false;
    	bool seenWhite=false;
    	for(int i=0;i<n;i++){
    		if(grid[i][j]==1){
    			if(!seenBlack){
    				seenBlack=true;
    			}
    			else{
    				if(seenWhite){
    					cout<<-1<<endl;
    					return 0;
    				}
    			}
    		}
    		else{
    			if(seenBlack){
    				seenWhite=true;
    			}
    		}
    	}
    	// if(!seenBlack){
    	// 	cout<<-1<<endl;
    	// 	return 0;
    	// }    	
    	hasBlackCol[j]=seenBlack;
    	if(!seenBlack)allColsBlack=false;
    }

    if(allRowsBlack^allColsBlack){
    	cout<<-1<<endl;
    	return 0;
    }



    cout<<floodFill(grid,n,m)<<endl;

}