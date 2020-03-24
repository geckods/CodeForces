#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 100000
#define MOD 1000000007

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,k;
    cin>>t>>k;

    ll dp[MAX+1];
    ll cumdp[MAX+1];
    dp[0]=0;
    cumdp[0]=1;

    for(int i=1;i<MAX+1;i++){
    	if(i<k){
    		dp[i]=1;
    	}
    	else{
    		dp[i]=1+cumdp[i-k];
    	}
    	dp[i]%=MOD;
    	cumdp[i]=cumdp[i-1]+dp[i];
    	cumdp[i]%=MOD;
    }

//    cout<<dp[2]<<endl<<endl;

    int queries[t][2];
    for(int i=0;i<t;i++){
    	cin>>queries[i][0]>>queries[i][1];
    }

    for(int i=0;i<t;i++){
    	ll ans = cumdp[queries[i][1]]-cumdp[queries[i][0]-1];
    	ans%=MOD;
    	if(ans<0) ans+=MOD;
    	cout<<ans<<endl;
    }

}
