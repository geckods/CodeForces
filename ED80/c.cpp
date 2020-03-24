#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAXN 1000
#define MAXM 10
#define MOD 1000000007

ll dp[MAXM+1][MAXN+1][MAXN+1];
ll cumdp[MAXM+1][MAXN+1][MAXN+1];
ll cumcumdp[MAXM+1][MAXN+1][MAXN+1];


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

    for(int k=1;k<=m;k++){
        if(k==1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i<=j){
                        dp[k][i][j]=1;
                    }
                    else{
                        dp[k][i][j]=0;
                    }
                }
            }
        }
        else{
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    dp[k][i][j]=0;
                }
            }

            for(int j=1;j<=n;j++){
                for(int i=1;i<=j;i++){
                    dp[k][i][j]=dp[k][i-1][j]+cumdp[k-1][i][j];
                    dp[k][i][j]%=MOD;
                    // cout<<k<<" "<<i<<" "<<j<<" "<<dp[k][i][j]<<endl;
                }
            }
        }



        for(int i=1;i<=n;i++){
            cumdp[k][i][n]=dp[k][i][n];
            for(int j=n-1;j>0;j--){
                cumdp[k][i][j]=cumdp[k][i][j+1]+dp[k][i][j];
                cumdp[k][i][j]%=MOD;
            }
        }
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=cumdp[m][i][i];
        ans%=MOD;
    }
    cout<<ans<<endl;

}
