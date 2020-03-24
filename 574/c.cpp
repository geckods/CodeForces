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


    ll n;
    cin>>n;

    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<n;i++){
    	cin>>b[i];
    }

    ll dp[n+2][2];

    for(int i=0;i<=n+1;i++){
    	dp[i][0]=dp[i][1]=0;
    }

    for(int i=n-1;i>=0;i--){
    	ll maxterma=INT_MIN;
    	maxterma=max(maxterma,dp[i+1][1]);
    	maxterma=max(maxterma,dp[i+2][1]);
    	dp[i][0]=a[i]+maxterma;

    	ll maxtermb=INT_MIN;
    	maxtermb=max(maxtermb,dp[i+1][0]);
    	maxtermb=max(maxtermb,dp[i+2][0]);
    	dp[i][1]=b[i]+maxtermb;
    }

    // for(int i=n-1;i>=0;i--){
    // 	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }

    cout<<max(dp[0][0],dp[0][1])<<endl;
}
