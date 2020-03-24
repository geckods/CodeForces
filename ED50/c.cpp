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

    ll t;
    cin>>t;

    ll dp[20][10][4];
  	memset(dp,0,sizeof(dp));
//	ll cumdp[20][10][4];//cumulates across leading digit

    for(int i=1;i<19;i++){
    	for(int j=1;j<10;j++){
    		dp[i][j][1]=pow((ll)2,i-1);
    	}
    }

    for(int i=1;i<19;i++){
    	for(int j=1;j<10;j++){
    		
    		for(int nexti=1;nexti<i;nexti++){
    			for(int nextj=1;nextj<10;nextj++){
    				
		    	}
    		}
