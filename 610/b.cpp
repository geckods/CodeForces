#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n,p,k;
        cin>>n>>p>>k;

        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        ll dp[n];

        ll ans=-1;

        dp[0]=arr[0];
        if(arr[0]>p){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            dp[i]=arr[i]+dp[i-1];
            if(i==k-1){
                dp[i]=min(dp[i],arr[i]);
            }
            else if (i>=k){
                dp[i]=min(dp[i],arr[i]+dp[i-k]);
            }
        }

        ans=n;
        while(dp[ans-1]>p)ans--;

        cout<<ans<<endl;


    }

}
