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

    ll q;
    cin>>q;
    for(int quer=0;quer<q;quer++){
    	ll n;
    	cin>>n;

    	ll a[n];
    	ll b[n];
    	for(int i=0;i<n;i++){
    		cin>>a[i]>>b[i];
    	}

    	ll dp[n][3];
    	for(int i=0;i<n;i++){
    		for(int j=0;j<3;j++){
    			dp[i][j]=0;
    		}
    	}
    	dp[n-1][0]=0;
    	dp[n-1][1]=b[n-1];
    	dp[n-1][2]=2*b[n-1];
    	for(int i=n-2;i>=0;i--){
    		if(a[i]==a[i+1]){
    			dp[i][0]=min(dp[i+1][1],dp[i+1][2]);
    			dp[i][1]=b[i]+min(dp[i+1][0],dp[i+1][2]);
    			dp[i][2]=2*b[i]+min(dp[i+1][0],dp[i+1][1]);
    		}
    		else if(a[i]==a[i+1]-1){
    			dp[i][0]=min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    			dp[i][1]=b[i]+min(dp[i+1][1],dp[i+1][2]);
    			dp[i][2]=2*b[i]+min(dp[i+1][0],dp[i+1][2]);
    		}
    		else if(a[i]==a[i+1]+1){
    			dp[i][0]=min(dp[i+1][0],dp[i+1][2]);
    			dp[i][1]=b[i]+min(dp[i+1][0],dp[i+1][1]);
    			dp[i][2]=2*b[i]+min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    		}
    		else if(a[i]==a[i+1]-2){
    			dp[i][0]=min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    			dp[i][1]=b[i]+min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    			dp[i][2]=2*b[i]+min(dp[i+1][2],dp[i+1][1]);    			
    		}
    		else if (a[i]==a[i+1]+2){
    			dp[i][0]=min(dp[i+1][0],dp[i+1][1]);
    			dp[i][1]=b[i]+min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    			dp[i][2]=2*b[i]+min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);		    			
    		}
    		else{
    			dp[i][0]=min(min(dp[i+1][0],dp[i+1][1]),dp[i+1][2]);
    			dp[i][1]=dp[i][0]+b[i];
    			dp[i][2]=dp[i][1]+b[i];
    		}
    	}
    	cout<<min(min(dp[0][0],dp[0][1]),dp[0][2])<<endl;
    }
}