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

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    // int a=0;
    // int ans=0;
    // int diff=0;
    // for(int i=0;i<n;i++){
    // 	if(a%2!=arr[i]%2){
    // 		diff--;
    // 	}
    // 	ans+=arr[i];
    // 	a=arr[i];
    // }

    // // cout<<ans<<endl;
    // cout<<((ans+1)/2+(diff)/2)<<endl;
    // return 0;

    ll dp[n][4];

    for(int i=0;i<n;i++){
    	dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
    }

    dp[n-1][0]=arr[n-1]/2;
    dp[n-1][1]=1+(arr[n-1]-1)/2;//1 stick out bottom
    dp[n-1][2]=1+(arr[n-1]-1)/2;//1 stick out top
    if(arr[n-1]>1)
	    dp[n-1][3]=2+(arr[n-1]-2)/2;//1 stick out top and bottom
	else{
	    dp[n-1][3]=0;		
	}

    for(int i=n-2;i>=0;i--){

    	//single row greedy
    	//->0
	    dp[i][0]=max(dp[i][0],arr[i]/2+dp[i+1][0]);
    	dp[i][0]=max(dp[i][0],(arr[i]-1)/2+dp[i+1][1]);
	    dp[i][0]=max(dp[i][0],dp[i+1][2]+(arr[i]-arr[i+1])/2 + (arr[i+1]-1)/2);
	    dp[i][0]=max(dp[i][0],dp[i+1][3]+(arr[i]-arr[i+1])/2 + (arr[i+1]-2)/2);

	    //->1
	    dp[i][1]=max(dp[i][1],1+(arr[i]-1)/2+dp[i+1][0]);
	    if(arr[i+1]>1)
			dp[i][1]=max(dp[i][1],dp[i+1][2]+(arr[i]-arr[i+1])/2 +1+ (arr[i+1]-2)/2);//removed arr[i+1]-1 because of parity

		//->2
	    dp[i][2]=max(dp[i][2],1+(arr[i]-1)/2+dp[i+1][0]);
	    if(arr[i]>1)
		    dp[i][2]=max(dp[i][2],1+(arr[i]-2)/2+dp[i+1][1]);
    	if(arr[i]>arr[i+1]){
		    dp[i][2]=max(dp[i][2],1+dp[i+1][2]+(arr[i]-arr[i+1]-1)/2+(arr[i+1]-1)/2);
		    dp[i][2]=max(dp[i][2],1+dp[i+1][3]+(arr[i]-arr[i+1]-1)/2+(arr[i+1]-2)/2);
		}

		//->3
		if(arr[i]>1){
		    dp[i][3]=max(dp[i][3],2+(arr[i]-2)/2+dp[i+1][0]);
    		if(arr[i]>arr[i+1] && arr[i+1]>1){
			    dp[i][3]=max(dp[i][3],2+dp[i+1][2]+(arr[i]-arr[i+1]-1)/2+(arr[i+1]-2)/2);
			}
		}
    }

    // for(int i=0;i<n;i++){
    // 	cout<<i<<" "<<arr[i]<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
    // }

    cout<<dp[0][0]<<endl;
}
