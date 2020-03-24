#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //dp[n][k][lastcolumn]

    int n,k;
    cin>>n>>k;

    ll dp[n+1][k+1][4];
    //00 - bb - 0
    //01 - bw - 1
    //10 - wb (from top) - 2
    //11 = ww - 3
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=k;j++){
    		for(int z=0;z<4;z++){
    			dp[i][j][z]=0;
    		}
    	}
    }

    dp[1][1][0]=1;
    dp[1][1][3]=1;

    if(k>1){
	    dp[1][2][1]=1;
	    dp[1][2][2]=1;
	}

	for(int i=2;i<=n;i++){
    	for(int j=1;j<=k;j++){
    		dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3];//adding bb
//    		cout<<i<<" "<<j<<" "<<dp[i-1][safejmin][2]<<endl;
    		int safejminterm = (j-2<0)?0:dp[i-1][j-2][2];
    		dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j][1] + safejminterm + dp[i-1][j-1][3];
    		safejminterm = (j-2<0)?0:dp[i-1][j-2][1];
    		dp[i][j][2] = dp[i-1][j-1][0] + safejminterm + dp[i-1][j][2] + dp[i-1][j-1][3];
    		dp[i][j][3] = dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3];//adding ww
    		for(int z=0;z<4;z++){
    			dp[i][j][z]%=998244353;
    		}
    	}
    }


 //    for(int testi=1;testi<=n;testi++){
	//     for(int z=0;z<4;z++){
	//     	for(int j=1;j<=k;j++){
	//     		cout<<dp[testi][j][z]<<" ";
	//     	}
	//     	cout<<endl;
	//     }
	//     cout<<endl<<endl<<endl;
	// }


    ll ans=0;
    for(int i=0;i<4;i++){
    	ans+=dp[n][k][i];
    	ans%=998244353;
    }

    cout<<ans<<endl;
}
