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

    ll t;
    cin>>t;

    while(t--){
    	ll n,m,k;
    	cin>>n>>m>>k;

    	ll arr[n];
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

  //   	ll minrange[n][n];//represents minimum in the range
		// for (int i = 0; i < n; i++) 
  //       	minrange[i][i] = arr[i]; 
  
	 //    for (int i=0; i<n; i++) 
	 //    { 
	 //        for (int j = i+1; j<n; j++) 	  
	 //           if (minrange[i][j - 1] < arr[j]) 
	 //              minrange[i][j] = minrange[i][j - 1]; 
	 //           else
	 //              minrange[i][j] = arr[j]; 
	 //    }

    	//for all orientations of k, check the min of the range that I may get
    	ll ans=INT_MIN;
    	ll minians;
    	for(int i=0;i<=min(k,m-1);i++){
    		minians=INT_MAX;
    		//i is the number of people that you persuade to take the left
    		//you persuade k-i people to take the right
    		//m-k-1 people are free

    		for(int j=0;j<=m-min(k,m-1)-1;j++){
    			// cout<<i<<" "<<j<<" "<<arr[i+j]<<" "<<arr[n-1-(k-i)-(m-k-1-j)]<<endl;
    			//number of free people who pick left
    			minians=min(minians,max(arr[i+j],arr[n-1-(k-i)-(m-k-1-j)]));
    		}
    		ans=max(ans,minians);
    	}
    	// if(ans==INT_MAX){
    	// 	ans=max()
    	// }
    	cout<<ans<<endl;
    }

}
