#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx,tune=native")
 
int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
 
    vector<string> myVec;
    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	myVec.push_back(s);
    }

    // if(n==1||m==1){
    // 	for(int i=0;i<n;i++){
    // 		for(int j=0;j<m;j++){
    // 			if(myVec[i][j]=='#'){
    // 				cout<<0<<endl;
    // 				return 0;
    // 			}
    // 		}
    // 	}
    // 	cout<<1<<endl;
    // 	return 0;
    // }
 
    //let's build a 'does there exist a path dp arr'
    // vector<vector<int> > dp;
    // for(int i=0;i<n;i++){
    // 	dp.push_back(vector<int>(m,0));
    // }
    int dp[n][m];
    dp[n-1][m-1]=1;
    for(int ijsum=n+m-3;ijsum>=0;ijsum--){
    	for(int i=max(0,ijsum-m+1);i<=min(ijsum,n-1);i++){
    		int j=ijsum-i;
    		if(j<0 || i>n-1)break;
    		if(j<0||i<0||j>m-1||i>n-1)continue;
    		if(myVec[i][j]=='#')dp[i][j]=0;
    		else{
    			if(i==n-1){
    				dp[i][j]=dp[i][j+1];
    			}
    			else if (j==m-1){
    				dp[i][j]=dp[i+1][j];
    			}
    			else{
    				dp[i][j]=dp[i+1][j]|dp[i][j+1];
    			}
    		}
    	}
    }
 
    if(dp[0][0]==0){
    	cout<<0<<endl;
    	return 0;
    }
    if(n==1||m==1){
    	cout<<1<<endl;
    	return 0;
    }
 
    //now send two dudes;
    int onei=0,onej=0,twoi=0,twoj=0;
 
    //one goes right if he can
    //two goes down if he can
    while(1){
    	if((onei==n-1&&onej==m-1)||onei>n-1 || onej>m-1){
    		break;
    	}
 
    	if(onei==twoi && onej==twoj && (onei>0 || onej>0)){
    		cout<<1<<endl;
    		return 0;
    	}
 
    	if(onej<m-1 && dp[onei][onej+1]==1){
    		onej++;
    	}
    	else{
    		onei++;
    	}
 
    	if(twoi<n-1 && dp[twoi+1][twoj]==1){
    		twoi++;
    	}
    	else{
    		twoj++;
    	}
    }
 
    cout<<2<<endl;
}
