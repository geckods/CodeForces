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

    int n,m;
    cin>>n>>m;


    char mainarr[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>mainarr[i][j];
    	}
    }

    int* dp[n][m][2][4];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		for(int z=0;z<4;z++){
	    		dp[i][j][0][z] = (int*)malloc(4*sizeof(int));
	    		dp[i][j][1][z] = (int*)malloc(4*sizeof(int));
   	 			for(int k=0;k<4;k++){
    				dp[i][j][0][z][k]=INT_MAX;
    				dp[i][j][1][z][k]=INT_MAX;
    			}
    		}
    	}
    }
    //0 is bottom
    //1 is right

    char chararr[4] = {'A','G','C','T'};

    for(int i=n-1;i>=0;i--){
    	for(int j=m-1;j>=0;j--){
    		for(int k=0;k<4;k++){
    			int ans=0;
    			int currchange=0;

    			if(mainarr[i][j]!=chararr[k]){
    				currchange++;
    			}

    			if(i==n-1){
    				if(j==n-1){
    					for(int a=0;a<2;a++){
    						for(int b=0;b<4;b++){
    							// if(b==k)continue;
    							dp[i][j][a][b][k]=currchange;
    						}
    					}
    				}
    				else{
    					ans=INT_MAX;
    					for(int l=0;l<4;l++){
    						if(k==l)continue;
    						for(int z=0;z<4;z++){ 	   							
	    						ans=min(ans,dp[i][j+1][0][z][l]);
    						}
    					}
    					ans+=currchange;
    				}
    			}
    			else if(j==m-1){
    				ans=INT_MAX;
    				for(int l=0;l<4;l++){
    					if(k==l)continue;
    					ans=min(ans,dp[i+1][j][l]);
    				}
    				ans+=currchange;
    			}
    			else{
    				ans=INT_MAX;
    				for(int l=0;l<4;l++){
    					if(k==l)continue;

    				}
    			}

    		}
    	}
    }

}