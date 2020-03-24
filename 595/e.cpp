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

    ll n,c;
    cin>>n>>c;

    ll a[n];
    for(int i=0;i<n-1;i++){
    	cin>>a[i];
    }

    ll b[n];
    for(int i=0;i<n-1;i++){
    	cin>>b[i];
    }

    ll ap[n];
    ll bp[n];

    ap[0]=a[0];
    bp[0]=b[0];
    for(int i=1;i<n;i++){
    	ap[i]=a[i]+ap[i-1];
    	bp[i]=b[i]+bp[i-1];
    }

    ll dp[n][2];
    dp[0][0]=0;
    dp[0][1]=c;

    for(int i=1;i<n;i++){
    	dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
    	dp[i][1]=min(dp[i-1][0]+b[i-1]+c,dp[i-1][1]+b[i-1]);
    }

    for(int i=0;i<n;i++){
    	cout<<min(dp[i][0],dp[i][1])<<" ";
    }
    cout<<endl;
}
