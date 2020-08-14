#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'
// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
    	ll n,m;
    	cin>>n>>m;
    	int arr[n][m];
    	bool blocked[n][m];
    	for(int i=0;i<n;i++){
    		string s;
    		cin>>s;
    		for(int j=0;j<m;j++){
    			blocked[i][j]=false;
    			switch(s[j]){
    				case '.':
    					arr[i][j]=0;
    					break;
    				case '#':
    					arr[i][j]=1;
    					blocked[i][j]=true;
    					break;
    				case 'G':
    					arr[i][j]=2;
    					break;
    				case 'B':
    					arr[i][j]=3;
    					break;
    			}
    			// cerr<<i<<" "<<j<<" "<<arr[i][j]<<endl;
    		}
    	}

    	if(arr[n-1][m-1]==3){
    		cout<<"NO"<<endl;
    		continue;
    	}


    	bool done=false;

    	for(int ipj = n+m-3;ipj>=0;ipj--){
    		for(int i=0;i<n;i++){
    			int j=ipj-i;

    			if(i<0 || i>=n)continue;
    			if(j<0 || j>=m)continue;

	    		bool isBlocked = false;
	    		bool canGoDown = (i<n-1) && (!blocked[i+1][j]);
	    		bool canGoRight = (j<m-1) && (!blocked[i][j+1]);
	    		isBlocked = !(canGoDown||canGoRight);
	    		isBlocked |= (arr[i][j]==1);

	    		blocked[i][j]=isBlocked;

	    		// cerr<<i<<" "<<j<<" "<<isBlocked<<" "<<canGoDown<<" "<<canGoRight<<endl;

	    		if(isBlocked){
	    			if(arr[i][j]==2){
	    				cout<<"NO"<<endl;
	    				done=true;
	    				break;
	    			}
	    		}
	    		else{
	    			if(arr[i][j]==3){
	    				// must block
	    				if(canGoDown){
	    					if(arr[i+1][j]==2){
	    						cout<<"NO"<<endl;
	    						done=true;
	    						break;
	    					}
	    					else{
	    						arr[i+1][j]=1;
	    						blocked[i+1][j]=true;
	    					}
	    				}

	    				if(canGoRight){
	    					if(arr[i][j+1]==2){
	    						cout<<"NO"<<endl;
	    						done=true;
	    						break;
	    					}
	    					else{
	    						arr[i][j+1]=1;
	    						blocked[i][j+1]=true;
	    					}	    					
	    				}

	    			}
	    		}
    		}
    		if(done)break;
    	}

    	if(!done){
	    	for(int ipj = n+m-3;ipj>=0;ipj--){    	
	    		for(int i=0;i<n;i++){
	    			int j=ipj-i;

	    			if(i<0 || i>=n)continue;
	    			if(j<0 || j>=m)continue;

		    		bool isBlocked = false;
		    		bool canGoDown = (i<n-1) && (!blocked[i+1][j]);
		    		bool canGoRight = (j<m-1) && (!blocked[i][j+1]);
		    		isBlocked = (!canGoDown)&&(!canGoRight);
		    		isBlocked |= (arr[i][j]==1);

		    		blocked[i][j]=isBlocked;

		    		if(isBlocked){
		    			if(arr[i][j]==2){
		    				cout<<"NO"<<endl;
		    				done=true;
		    				break;
		    			}
		    		}
	    		}
	    		if(done)break;
	    	}    		
    	}
    	if(!done)
	    	cout<<"YES"<<endl;
    }
}